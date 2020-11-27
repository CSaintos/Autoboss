// Warehouse.h
#pragma once

#ifndef PRODUCT_H
#include "Product.h"
#endif

#ifndef VECTOR
#include <vector>
#define VECTOR
#endif
#ifndef STRING
#include <string>
#define STRING
#endif

#ifndef WAREHOUSE_H
namespace BusinessLayer {
	class Warehouse {
	private:
		std::vector<Product> mInventory;
		int mWarehouseID, mPhoneNumber;
		std::string mEmail, mAddress;
	public:
		Warehouse();
		Warehouse(std::vector<Product> inventory, int warehouseID, std::string email, std::string address, int phoneNumber);
		void appendInventory(std::vector<Product>& v, Product& p);
		std::vector<Product> getInventory() const;
		int const getWarehouseID() const;
		std::string getEmail() const;
		int getPhoneNumber() const;
		std::string getAddress() const;

	};
}
#define WAREHOUSE_H
#endif