// DBHelper.cpp
#ifndef DBHELPER_H
#include "DBHelper.h"
#endif

using namespace DatabaseLayer;
using namespace std; // place holder

DBHelper::DBHelper() : rc(0), env(0), dbc(0), stmt(0), cbData(0), szData("0")
{}

void DBHelper::openDB() {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
	rc = SQLDriverConnect(dbc, NULL,
		(SQLWCHAR*)L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=(localdb)\\MSSQLLocalDB;DATABASE=AutobossDB;Trusted=true;", 
		SQL_NTS, NULL, 1024, NULL, SQL_DRIVER_NOPROMPT);
	// Deallocate handles
	if (!SQL_SUCCEEDED(rc)) {
		cout << "Failed to connect to database" << endl;
		SQLFreeHandle(SQL_HANDLE_DBC, dbc);
		SQLFreeHandle(SQL_HANDLE_ENV, env);
	}
	else {
		cout << "Database Connection Success" << endl;
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

vector<vector<string>> DBHelper::sqlexec(string sqlstr) {
	wstring str2(sqlstr.length(), L' ');
	copy(sqlstr.begin(), sqlstr.end(), str2.begin());
	vector<vector<string>> vectorString;

	rc = SQLFreeStmt(stmt, SQL_DROP);
	rc = SQLAllocStmt(dbc, &stmt);

	rc = SQLExecDirect(stmt, const_cast<SQLWCHAR*>(str2.c_str()), SQL_NTS);
	if (rc == SQL_NO_DATA_FOUND) {
		cout << "No data was found" << endl;
	}
	if (!SQLSUCCESS(rc)) {
		error_out(stmt, SQL_HANDLE_STMT);
	}
	else {
		for (rc = SQLFetch(stmt); rc == SQL_SUCCESS; rc = SQLFetch(stmt)) {
			int i = 1;
			vector<string> vectorSubString;

			for (int i = 1; rc == SQL_SUCCESS && rc != SQL_NO_DATA; ++i) {
				rc = SQLGetData(stmt, i, SQL_C_CHAR, szData, sizeof(szData), &cbData);
				string str(reinterpret_cast<char*>(szData));
				vectorSubString.push_back(str);
				//cout << str << " "; // place holder
			}
			vectorSubString.pop_back();
			vectorString.push_back(vectorSubString);
			//cout << endl; // place holder
		}
	}

	return vectorString;
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
}