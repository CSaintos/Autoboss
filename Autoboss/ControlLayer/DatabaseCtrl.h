// DatabaseCtr.h
#pragma once

#ifndef DBHELPER_H
#include "DBHelper.h"
#endif
#ifndef INVOICE_DB_H
#include "Invoice_db.h"
#endif
#ifndef PRODUCT_DB_H
#include "Product_db.h"
#endif
#ifndef SALESPERSON_DB_H
#include "Salesperson_db.h"
#endif
#ifndef WAREHOUSE_DB_H
#include "Warehouse_db.h"
#endif
#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif

#ifndef MEMORY
#include <memory>
#define MEMORY
#endif
#ifndef VECTOR
#include <vector>
#define VECTOR
#endif
#ifndef STRING
#include <string>
#define STRING
#endif
#ifndef SSTREAM
#include <sstream>
#define SSTREAM
#endif

#ifndef DATABASECTRL_H
namespace ControlLayer {
	class DatabaseCtrl {
	protected:
		DatabaseCtrl();

		static DatabaseCtrl* databaseCtrl;
		
		std::unique_ptr<DatabaseLayer::DBHelper> dbHelper;
		std::unique_ptr<DatabaseLayer::Invoice_db> invoiceDB;
		std::unique_ptr<DatabaseLayer::Product_db> productDB;
		std::unique_ptr<DatabaseLayer::Salesperson_db> salespersonDB;
		std::unique_ptr<DatabaseLayer::Warehouse_db> warehouseDB;
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
		void setCurrentDate(std::string date);
		std::string getPassword();
		void setPassword(std::string password);
		std::vector<BusinessLayer::Warehouse> getWarehouses();
		std::vector<BusinessLayer::Product> getInventory(BusinessLayer::Warehouse);
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
		void getProductDetails() {}
		void updateProduct() {}
		void addSalesperson() {}
		void setCommissionRate() {}
		/*
		Layer Logic
		*/
	};
}
#define DATABASECTRL_H
#endif