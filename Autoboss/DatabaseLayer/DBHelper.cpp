// DBHelper.cpp
#ifndef DBHELPER_H
#include "DBHelper.h"
#endif

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
	if (!SQL_SUCCEEDED(rc)) {
		cout << "Failed to connect" << endl;
		SQLFreeHandle(SQL_HANDLE_DBC, dbc);
		SQLFreeHandle(SQL_HANDLE_ENV, env);
	}
	else {
		cout << "Connection Success" << endl;
		rc = SQLAllocStmt(dbc, &stmt);
		if (!SQL_SUCCEEDED(rc)) {
			cout << "Failed to allocate stmt handle" << endl;
		}
	}
}

void DBHelper::closeDB() {
	SQLFreeStmt(stmt, SQL_DROP);
	SQLDisconnect(dbc);
	SQLFreeHandle(SQL_HANDLE_DBC, dbc);
	SQLFreeHandle(SQL_HANDLE_ENV, env);
}

void DBHelper::sqlexec(std::string sqlstr) {
	const unsigned char* charsql = reinterpret_cast<const unsigned char*> (sqlstr.c_str());
	//cout << charsql << endl;
	rc = SQLExecDirect(stmt, (SQLWCHAR*)L"SELECT * FROM dbo.Warehouses", SQL_NTS);
	if (rc == SQL_NO_DATA_FOUND) {
		cout << "No data was found" << endl;
	}
	if (!SQLSUCCESS(rc)) {
		error_out(stmt, SQL_HANDLE_STMT);
	}
	else {
		cout << "SQL query success?" << endl;
		for (rc = SQLFetch(stmt); rc == SQL_SUCCESS; rc = SQLFetch(stmt)) {
			SQLGetData(stmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData);
			// In this example, the data is sent to the console; SQLBindCol() could be called to bind   
			// individual rows of data and assign for a rowset.
			printf("%s\n", (const char*)szData);
		}
	}
}

void DBHelper::error_out(SQLHANDLE handle, SQLINTEGER handleType) {
	SQLINTEGER i = 0;
	SQLINTEGER native;
	SQLWCHAR state[7];
	SQLWCHAR text[256];
	SQLSMALLINT len;

	cout << "SQL query failure" << endl;
	do {
		rc = SQLGetDiagRec(handleType, handle, ++i, state, &native, text, sizeof(text)/2, &len);

		if (SQL_SUCCEEDED(rc)) {
			wcout << state << ":" << i << ":" << native << ":" << text << endl;
		}
	} while (rc == SQL_SUCCESS);
}

void DBHelper::test() {
	cout << "Database tester" << endl;
	sqlexec("SELECT * FROM dbo.Products");
}

