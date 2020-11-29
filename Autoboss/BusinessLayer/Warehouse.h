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
		int mWarehouseID;
		std::string mEmail, mAddress, mPhoneNumber;
	public:
		Warehouse();
		Warehouse(std::vector<Product> inventory, int warehouseID, std::string email, std::string address, std::string phoneNumber);
		void appendInventory(std::vector<Product>& v, Product& p);
		std::vector<Product> getInventory() const;
		int getWarehouseID() const;
		std::string getEmail() const;
		std::string getPhoneNumber() const;
		std::string getAddress() const;

	};
}
#define WAREHOUSE_H
#endif