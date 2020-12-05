// Warehouse_db.h
#pragma once

#ifndef DBHELPER_H
#include "DBHelper.h"
#endif
#ifndef PRODUCTS_H
#include "Product.h"
#endif
#ifndef WAREHOUSES_H
#include "Warehouse.h"
#endif

#ifndef WAREHOUSE_DB_H
namespace DatabaseLayer {
	class Warehouse_db {
	private:
		DBHelper* dbHelper = nullptr;
	public:
		Warehouse_db();

		std::vector<BusinessLayer::Warehouse> getWarehouses();
		std::vector<BusinessLayer::Product> getInventory(BusinessLayer::Warehouse);
		std::vector<BusinessLayer::Product> getAllInventory();
		void stockInventory(BusinessLayer::Product, BusinessLayer::Warehouse);
		void addInventory(BusinessLayer::Product, BusinessLayer::Warehouse);
		void addWarehouse(BusinessLayer::Warehouse);
		std::vector<BusinessLayer::Product>  getOtherProducts(BusinessLayer::Warehouse);
		void test();
	};
}
#define WAREHOUSE_DB_H
#endif