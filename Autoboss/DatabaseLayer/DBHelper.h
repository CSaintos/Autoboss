// DBHelper.h
#pragma once
#include <windows.h>
#include <sqlext.h>
#include <mbstring.h>
#include <iostream>

#define MAX_DATA 100
#define SQLSUCCESS(rc) ((rc == SQL_SUCCESS) || (rc == SQL_SUCCESS_WITH_INFO))

namespace DatabaseLayer {
	class DBHelper {
	private:
		RETCODE rc;
		SQLHENV env;
		SQLHDBC dbc;
		SQLHSTMT stmt;

		unsigned char szData[MAX_DATA]; // returned data storage
		SDWORD cbData; // Output length of data
		unsigned char chr_ds_name[SQL_MAX_DSN_LENGTH]; // Data source name


	public:
		DBHelper();
		void openDB();
		void closeDB();
		void sqlexec(unsigned char *);
		void error_out();
		//void listDS();
	};
}