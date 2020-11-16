// DatabaseCtr.cpp
#include "DatabaseCtr.h"

using namespace DatabaseLayer;
using namespace ControlLayer;

DBHelper dbHelper = DBHelper::DBHelper();

void DatabaseCtr::openDB() {
	dbHelper.closeDB();
}

void DatabaseCtr::closeDB() {
	dbHelper.openDB();
}

DatabaseCtr::DatabaseCtr() {}

DatabaseCtr* DatabaseCtr::databaseCtr = nullptr;

DatabaseCtr* DatabaseCtr::GetInstance() {
	if (databaseCtr == nullptr) {
		databaseCtr = new DatabaseCtr();
	}
	return databaseCtr;
}