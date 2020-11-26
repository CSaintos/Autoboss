// DatabaseCtr.cpp
#ifndef DATABASECTRL_H
#include "DatabaseCtrl.h"
#endif

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() :
	dbHelper(std::make_unique<DBHelper>()) 
{}

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

void DatabaseCtrl::test() {
	dbHelper->test();
}

void DatabaseCtrl::setCurrentDate(std::string date) {
	std::ostringstream query;
	query << "UPDATE dbo.CurrentDate ";
	query << "SET [Date] = " << "'" + date + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::string DatabaseCtrl::getPassword() {
	std::vector<std::vector<std::string>> vectorString;
	vectorString = dbHelper->sqlexec("SELECT [Password] FROM dbo.Credentials WHERE [Id] = 1");
	for (int i = 0; i < vectorString.size(); ++i) {
		for (int j = 0; j < vectorString[i].size(); ++j) {
			return vectorString[i][j];
		}
	}
}