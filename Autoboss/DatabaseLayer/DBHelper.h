// DBHelper.h
#pragma once
#include <windows.h>
#include <sql.h>
#include <sqlext.h>

namespace DatabaseLayer {
	class DBHelper {
	private:
		SQLHENV env;
		SQLHDBC dbc;
		//SQLHSTMT stmt;
	public:
		DBHelper();
		void openDB();
		void closeDB();
	};
}