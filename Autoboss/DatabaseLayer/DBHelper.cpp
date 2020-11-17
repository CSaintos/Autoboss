// DBHelper.cpp
#include "DBHelper.h"

using namespace DatabaseLayer;
using namespace std; // place holder

//Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=AutobossDB;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False

DBHelper::DBHelper() : rc(0), env(0), dbc(0), stmt(0), cbData(0), szData("0") {
	_mbscpy_s(chr_ds_name, SQL_MAX_DSN_LENGTH, (const unsigned char *)"AutobossDB");
}

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
	rc = SQLConnect(dbc, (wchar_t*)chr_ds_name, SQL_NTS, NULL, 0, NULL, 0);

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
}

void DBHelper::error_out() {

}