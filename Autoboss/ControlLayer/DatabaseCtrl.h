// DatabaseCtr.h
#pragma once

#ifndef DBHELPER_H
#include "DBHelper.h"
#define DBHELPER_H
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

#ifndef MEMORY
#include <memory>
#define MEMORY
#endif

#ifndef DATABASECTRL_H
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