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

using BusinessLayer::Product;
using BusinessLayer::Warehouse;

#ifndef PRODUCT_DB_H
namespace DatabaseLayer {
	class Product_db {
	private:
		std::vector<Product> prodList;
		DBHelper helper;
	public:
		Product_db();
		std::vector<Product> getInventory(Warehouse wh);
		std::vector<Product> getAllProducts();
		std::vector<Product> getLowStock();
		void addProduct(Warehouse wh, Product prod, int quantity); //as in add more STONKS
		void createProduct(Product prod);
		void getProductDetails(Product prod);
		void updateProduct(Product prod);
	};
}
#define PRODUCT_DB_H
#endif