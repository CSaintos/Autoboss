// DatabaseCtr.h
#pragma once
#include "DBHelper.h"
#include "Invoice_db.h"
#include "Product_db.h"
#include "Salesperson_db.h"
#include "Warehouse_db.h"
#include <memory>

namespace ControlLayer {
	class DatabaseCtrl {
	protected:
		DatabaseCtrl();

		static DatabaseCtrl* databaseCtrl;

		DatabaseLayer::DBHelper dbHelper;
	public:
		// Can't be cloneable
		DatabaseCtrl(DatabaseCtrl& other) = delete;
		// Can't be assignable
		void operator=(const DatabaseCtrl&) = delete;
		// Gets BusinessLayer singleton object
		static DatabaseCtrl* GetInstance();
		/*
		Business Logic
		*/

		void openDB();
		void closeDB();
	};
}