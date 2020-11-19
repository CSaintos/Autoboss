// DatabaseCtr.cpp
#include "DatabaseCtrl.h"

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() {}

DatabaseCtrl* DatabaseCtrl::databaseCtrl = nullptr;

DatabaseCtrl* DatabaseCtrl::GetInstance() {
	if (databaseCtrl == nullptr) {
		databaseCtrl = new DatabaseCtrl();
	}
	return databaseCtrl;
}

//void DatabaseCtr::openDB() {
//	dbHelper.closeDB();
//}
//
//void DatabaseCtr::closeDB() {
//	dbHelper.openDB();
//}