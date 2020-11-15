#include "DatabaseCtr.h"

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtr::DatabaseCtr() {}

DatabaseCtr* DatabaseCtr::databaseCtr = nullptr;

DatabaseCtr* DatabaseCtr::GetInstance() {
	if (databaseCtr == nullptr) {
		databaseCtr = new DatabaseCtr();
	}
	return databaseCtr;
}
