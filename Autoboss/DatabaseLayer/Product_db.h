// Product_db.h
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

#ifndef PRODUCT_DB_H
namespace DatabaseLayer {
	class Product_db {
	private:
		DBHelper* dbHelper = nullptr;
	public:
		Product_db();

		std::vector<BusinessLayer::Product> getProducts();
		BusinessLayer::Product getProductDetails(BusinessLayer::Product);
		std::vector<BusinessLayer::Product> getLowStock();
		void createProduct(BusinessLayer::Product);
		void updateProduct(BusinessLayer::Product);
		void test();
	};
}
#define PRODUCT_DB_H
#endif