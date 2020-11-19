// DatabaseCtr.cpp
#include "DatabaseCtrl.h"

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() : dbHelper(std::make_unique<DBHelper>()) {}

DatabaseCtrl* DatabaseCtrl::databaseCtrl = nullptr;

DatabaseCtrl* DatabaseCtrl::GetInstance() {
	if (databaseCtrl == nullptr) {
		databaseCtrl = new DatabaseCtrl();
	}
	return databaseCtrl;
}

void DatabaseCtrl::openDB() {
	dbHelper->openDB();
}

void DatabaseCtrl::closeDB() {
	dbHelper->closeDB();
}