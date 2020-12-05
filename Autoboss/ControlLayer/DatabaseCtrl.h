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
		
		DatabaseLayer::DBHelper* dbHelper = nullptr;

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
		void checkAndUpdateEssentials();
		void setCurrentDate(std::string date);
		std::string getCurrentDate();
		std::string getPassword();
		void setPassword(std::string password);
		std::vector<BusinessLayer::Warehouse> getWarehouses();
		std::vector<BusinessLayer::Product> getInventory(BusinessLayer::Warehouse);
		std::vector<BusinessLayer::Product> getAllInventory();
		void stockInventory(BusinessLayer::Product, BusinessLayer::Warehouse);
		void addInventory(BusinessLayer::Product, BusinessLayer::Warehouse);
		std::vector<BusinessLayer::Product>  getOtherProducts(BusinessLayer::Warehouse);
		void addWarehouse(BusinessLayer::Warehouse);
		std::vector<BusinessLayer::Product> getLowStock();
		std::vector<BusinessLayer::Invoice> getOInvoices();
		BusinessLayer::Invoice getOInvoiceDetails(BusinessLayer::Invoice);
		void payInvoice(BusinessLayer::Invoice);
		std::vector<BusinessLayer::Product> getProducts();
		std::vector<BusinessLayer::Salesperson> getSalespeople();
		void addOInvoice(BusinessLayer::Invoice);
		std::vector<BusinessLayer::Invoice> getCInvoices();
		BusinessLayer::Invoice getCInvoiceDetails(BusinessLayer::Invoice);
		void createProduct(BusinessLayer::Product);
		BusinessLayer::Product getProductDetails(BusinessLayer::Product);
		void updateProduct(BusinessLayer::Product);
		void addSalesperson(BusinessLayer::Salesperson);
		void setCommissionRate(BusinessLayer::Salesperson);
		void reset();
		/*
		Layer Logic
		*/
	};
}
#define DATABASECTRL_H
#endif