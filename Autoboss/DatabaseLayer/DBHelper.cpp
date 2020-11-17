// DBHelper.cpp
#include "DBHelper.h"

using namespace DatabaseLayer;

DBHelper::DBHelper() {}

//DBHelper::env;
//DBHelper::dbc;

void DBHelper::openDB() {
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
}

void DBHelper::closeDB() {
	SQLFreeHandle(SQL_HANDLE_DBC, dbc);
	SQLFreeHandle(SQL_HANDLE_ENV, env);
}