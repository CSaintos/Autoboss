// DatabaseCtr.h
#pragma once
#include "DBHelper.h"
#include "Invoice_db.h"
#include "Product_db.h"
#include "Salesperson_db.h"
#include "Warehouse_db.h"
#include <memory>

namespace ControlLayer {
	class DatabaseCtr {
	protected:
		DatabaseCtr();

		static DatabaseCtr* databaseCtr;

		//DBHelper dbHelper = DBHelper::DBHelper();
		//std::unique_ptr<DBHelper> dbHelper; //= DBHelper::DBHelper();
	public:
		// Can't be cloneable
		DatabaseCtr(DatabaseCtr& other) = delete;
		// Can't be assignable
		void operator=(const DatabaseCtr&) = delete;
		// Gets BusinessLayer singleton object
		static DatabaseCtr* GetInstance();
		/*
		Business Logic
		*/

		inline void openDB() { }
		inline void closeDB() { }
	};
}