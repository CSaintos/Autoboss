#pragma once
#include "Product.h"
#include <vector>
#include <string>
namespace BusinessLayer {
	class Warehouse {
	private:
		std::vector<Product> mInventory;
		int mWarehouseID, mPhoneNumber;
		std::string mEmail, mAddress;
	public:
		Warehouse(std::vector<Product> inventory, int warehouseID, std::string email, std::string address, int phoneNumber);
		void appendInventory(std::vector<Product>& v, Product& p);
		std::vector<Product> getInventory() const;
		int getWarehouseID() const;
		std::string getEmail() const;
		int getPhoneNumber() const;
		std::string getAddress() const;

	};
}