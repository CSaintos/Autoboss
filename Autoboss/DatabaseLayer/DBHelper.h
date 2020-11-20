// DBHelper.h
#pragma once
#include <windows.h>
#include <sqlext.h>
#include <mbstring.h>
#include <iostream>

#define SQL_RETURN_CODE_LEN 1000
#define MAX_DATA 100
#define SQLSUCCESS(rc) ((rc == SQL_SUCCESS) || (rc == SQL_SUCCESS_WITH_INFO))

namespace DatabaseLayer {
	class DBHelper {
	private:
		SQLHENV env;
		SQLHDBC dbc;
		SQLHSTMT stmt;

		RETCODE rc;

		SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
		unsigned char szData[MAX_DATA]; // returned data storage
		SDWORD cbData; // Output length of data
		unsigned char chr_ds_name[SQL_MAX_DSN_LENGTH]; // Data source name


	public:
		DBHelper();
		void openDB();
		void closeDB();
		void sqlexec(unsigned char *);
		void error_out();
		void test();
		//void listDS();
	};
}