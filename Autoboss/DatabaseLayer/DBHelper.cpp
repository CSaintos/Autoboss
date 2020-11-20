// DBHelper.cpp
#include "DBHelper.h"

using namespace DatabaseLayer;
using namespace std; // place holder

//Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=AutobossDB;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False

DBHelper::DBHelper() : rc(0), env(0), dbc(0), stmt(0), cbData(0), szData("0") 
{}

//void DBHelper::listDS() {
//	direction = SQL_FETCH_FIRST;
//	ret = SQLDataSources(env, direction,
//		dsn, sizeof(dsn), &dsn_ret,
//		desc, sizeof(desc), &desc_ret);
//	while (SQL_SUCCEEDED(ret)) {
//		direction = SQL_FETCH_NEXT;
//
//		printf("%s - %s\n", (char*)dsn, (char*)desc);
//		if (ret == SQL_SUCCESS_WITH_INFO) {
//			printf("\tdata truncation\n");
//		}
//	}
//}

void DBHelper::openDB() {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
	rc = SQLDriverConnect(dbc, NULL,
		(SQLWCHAR*)L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=(localdb)\\MSSQLLocalDB;DATABASE=AutobossDB;Trusted=true;", 
		SQL_NTS, NULL, 1024, NULL, SQL_DRIVER_NOPROMPT);

	// Deallocate handles
	if (!SQLSUCCESS(rc)) {
		cout << "Failed to connect" << endl;
		SQLFreeHandle(SQL_HANDLE_DBC, dbc);
		SQLFreeHandle(SQL_HANDLE_ENV, env);
	}
	else {
		cout << "Connection Success" << endl;
		rc = SQLAllocStmt(dbc, &stmt);
	}
}

void DBHelper::closeDB() {
	SQLFreeStmt(stmt, SQL_DROP);
	SQLDisconnect(dbc);
	SQLFreeHandle(SQL_HANDLE_DBC, dbc);
	SQLFreeHandle(SQL_HANDLE_ENV, env);
}

void DBHelper::sqlexec(unsigned char * sqlstr) {
	rc = SQLExecDirect(stmt, (wchar_t*)sqlstr, SQL_NTS);
	if (!SQLSUCCESS(rc)) {
		error_out();
	}
	else {
		for (rc = SQLFetch(stmt); rc == SQL_SUCCESS; rc = SQLFetch(stmt)) {
			SQLGetData(stmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData);
			// In this example, the data is sent to the console; SQLBindCol() could be called to bind   
			// individual rows of data and assign for a rowset.
			printf("%s\n", (const char*)szData);
		}
		cout << "SQL query success" << endl;
	}
}

void DBHelper::error_out() {
	/*unsigned char szSQLSTATE[10];  
	   SDWORD nErr;  
	   unsigned char msg[SQL_MAX_MESSAGE_LENGTH + 1];  
	   SWORD cbmsg;  
  
	   while (SQLError(0, 0, hstmt, szSQLSTATE, &nErr, msg, sizeof(msg), &cbmsg) == SQL_SUCCESS) {  
		  sprintf_s((char *)szData, sizeof(szData), "Error:\nSQLSTATE=%s, Native error=%ld, msg='%s'", szSQLSTATE, nErr, msg);  
		  MessageBox(NULL, (const char *)szData, "ODBC Error", MB_OK);  
	   }*/
	cout << "SQL query failure" << endl;
}

void DBHelper::test() {
	sqlexec((unsigned char *)"SELECT * FROM [Products]");
	stmt->execute("SELECT * FROM Products");
}