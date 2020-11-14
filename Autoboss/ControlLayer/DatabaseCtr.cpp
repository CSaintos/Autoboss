#include "DatabaseCtr.h"

using namespace DatabaseLayer;

DatabaseCtr* DatabaseCtr::databaseCtr = nullptr;

DatabaseCtr* DatabaseCtr::GetInstance() {
	if (databaseCtr == nullptr) {
		databaseCtr = new DatabaseCtr();
	}
	return databaseCtr;
}
