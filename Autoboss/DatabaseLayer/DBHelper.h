// DBHelper.h
#pragma once

#ifndef WINDOWS_H
#include <windows.h>
#define WINDOWS_H
#endif
#ifndef SQLEXT_H
#include <sqlext.h>
#define SQLEXT_H
#endif
#ifndef MBSTRING_H
#include <mbstring.h>
#define MBSTRING_H
#endif
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif

#define SQL_RETURN_CODE_LEN 1000
#define MAX_DATA 100
#define SQLSUCCESS(rc) ((rc == SQL_SUCCESS) || (rc == SQL_SUCCESS_WITH_INFO))

#ifndef DBHELPER_H
namespace DatabaseLayer {
	class DBHelper {
	private:
		SQLHENV env;
		SQLHDBC dbc;
		SQLHSTMT stmt;

		RETCODE rc;

		SQLWCHAR SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER NativeError;
		SQLSMALLINT MsgLen;

		SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
		unsigned char szData[MAX_DATA]; // returned data storage
		SDWORD cbData; // Output length of data
		unsigned char chr_ds_name[SQL_MAX_DSN_LENGTH]; // Data source name


	public:
		DBHelper();
		void openDB();
		void closeDB();
		void sqlexec(std::string sqlstr);
		void error_out();
		void test();
		//void listDS();
	};
}
#define DBHELPER_H
#endif