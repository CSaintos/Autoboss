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

//Can't make Warehouse obj without 
using BusinessLayer::Warehouse;
using BusinessLayer::Product;

#ifndef WAREHOUSE_DB_H
namespace DatabaseLayer {
	class Warehouse_db {
	private:
		std::unique_ptr<DatabaseLayer::DBHelper> dbHelper;

		//BusinessLayer::Warehouse selectWarehouse;
	public:
		Warehouse_db();
		std::vector<BusinessLayer::Warehouse> getWarehouses();
		void addWarehouse(BusinessLayer::Warehouse wh);
		void test();
	};
}
#define WAREHOUSE_DB_H
#endif