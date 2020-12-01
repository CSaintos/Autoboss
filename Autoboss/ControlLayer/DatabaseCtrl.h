// DatabaseCtr.h
#pragma once

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
#ifndef DBHELPER_H
#include "DBHelper.h"
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
		std::string getCurrentDate();
		std::string getPassword();
		void setPassword(std::string password);
		std::vector<BusinessLayer::Warehouse> getWarehouses(); // DONE KINDA
		std::vector<BusinessLayer::Product> getInventory(BusinessLayer::Warehouse); // DONE KINDA
		void stockInventory(BusinessLayer::Product, BusinessLayer::Warehouse); // DONE KINDA
		void addInventory(BusinessLayer::Product, BusinessLayer::Warehouse); // TODO
		std::vector<BusinessLayer::Product>  getOtherProducts(BusinessLayer::Warehouse); // TODO
		void addWarehouse(BusinessLayer::Warehouse); // DONE KINDA
		std::vector<BusinessLayer::Product> getLowStock(); // DONE KINDA
		std::vector<BusinessLayer::Invoice> getOInvoices(); // DONE KINDA NEEDS REVIEW
		BusinessLayer::Invoice getOInvoiceDetails(BusinessLayer::Invoice); // DONE KINDA NEEDS REVIEW
		void payInvoice(BusinessLayer::Invoice); // DONE KINDA NEEDS REVIEW
		std::vector<BusinessLayer::Product> getProducts(); // DONE KINDA
		std::vector<BusinessLayer::Salesperson> getSalespeople(); // DONE KINDA
		void addOInvoice(BusinessLayer::Invoice); // DONE KINDA NEEDS REVIEW
		std::vector<BusinessLayer::Invoice> getCInvoices(); // DONE KINDA NEEDS REVIEW
		BusinessLayer::Invoice getCInvoiceDetails(BusinessLayer::Invoice); // DONE KINDA NEEDS REVIEW
		void createProduct(BusinessLayer::Product); // DONE KINDA
		BusinessLayer::Product getProductDetails(BusinessLayer::Product); // DONE KINDA
		void updateProduct(BusinessLayer::Product); // DONE KINDA
		void addSalesperson(BusinessLayer::Salesperson); // DONE KINDA
		void setCommissionRate(BusinessLayer::Salesperson); // DONE KINDA
		/*
		Layer Logic
		*/
	};
}
#define DATABASECTRL_H
#endif