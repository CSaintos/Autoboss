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
		
		std::unique_ptr<DatabaseLayer::DBHelper> dbHelper;
	public:
		/*
		Singleton Logic
		*/
			// Can't be cloneable
		DatabaseCtrl(DatabaseCtrl& other) = delete;
			// Can't be assignable
		void operator=(const DatabaseCtrl&) = delete;
			// Gets BusinessLayer singleton object
		static DatabaseCtrl* GetInstance();
		
		/*
		Initialization Logic
		*/
		void openDB();
		void closeDB();

		void test(); // tester

		/*
		Main Logic
		*/
		void setCurrentDate(/*Date param*/) {}
		void getPassword() {}
		void setPassword(/*password string param*/) {}
		void getWarehouses() {}
		void getInventory(/*warehouse param*/) {}
		void addProduct(/*warehouse param*/) {}
		void addWarehouse(/*warehouse param*/) {}
		void getLowStock() {}
		void getOInvoices() {}
		void payInvoice(/*invoice param*/) {}
		void getProducts() {}
		void getSalespeople() {}
		void addOInvoice() {}
		void getCInvoices() {}
		void createProduct() {}
		/*
		Layer Logic
		*/
	};
}