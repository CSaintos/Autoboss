// Warehouse_db.cpp
#ifndef WAREHOUSE_DB_H
#include "Warehouse_db.h"
#endif

using namespace DatabaseLayer;

Warehouse_db::Warehouse_db() : 
	dbHelper(DBHelper::GetInstance())
{}

std::vector<BusinessLayer::Warehouse> Warehouse_db::getWarehouses() {
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM Warehouses");
	std::vector<BusinessLayer::Warehouse> warehouseList;
	std::vector<BusinessLayer::Product> inv;

	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		warehouseList.push_back(BusinessLayer::Warehouse(inv, std::stoi(contents[0]), contents[2], contents[1], contents[3]));
	}

	return warehouseList;
}

std::vector<BusinessLayer::Product> Warehouse_db::getInventory(BusinessLayer::Warehouse warehouse) {
	std::vector<BusinessLayer::Product> products;
	std::vector<std::vector<std::string>> inventory;
	std::ostringstream query;

	query << "SELECT p.productID, pd.productName, p.quantityInStock ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.productID = pd.productID ";
	query << "WHERE p.warehouseID = " + std::to_string(warehouse.getWarehouseID());
	inventory = dbHelper->sqlexec(query.str());

	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				std::stoi(contents[2]),
				"",
				""
			)
		);
	}

	return products;
}

std::vector<BusinessLayer::Product> Warehouse_db::getAllInventory() {
	std::vector<std::vector<std::string>> temp;
	std::vector<BusinessLayer::Product> allInventory;
	std::ostringstream query;

	query << "SELECT p.productID, pd.productName, pd.manufacturer, pd.MSRP, SUM(p.quantityInStock) ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.productID = pd.productID ";
	query << "GROUP BY p.productID, pd.productName, pd.manufacturer, pd.MSRP";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		allInventory.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				std::stod(contents[3]),
				0.0,
				std::stoi(contents[4]),
				contents[2],
				""
			)
		);
	}

	return allInventory;
}

void Warehouse_db::stockInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) {
	std::ostringstream query;

	query << "UPDATE dbo.Products ";
	query << "SET [quantityInStock] = [quantityInStock] + " + std::to_string(product.getQuantity()) + " ";
	query << "WHERE productID = " + std::to_string(product.getProductID()) + " AND ";
	query << "warehouseID = " + std::to_string(warehouse.getWarehouseID());

	dbHelper->sqlexec(query.str());
}

void Warehouse_db::addInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) {
	std::ostringstream query;

	query << "INSERT INTO dbo.Products ";
	query << "([warehouseID], [productID], [quantityInStock]) ";
	query << "VALUES (";
	query << std::to_string(warehouse.getWarehouseID()) + ", ";
	query << std::to_string(product.getProductID()) + ", ";
	query << "0)";

	dbHelper->sqlexec(query.str());
}

void Warehouse_db::addWarehouse(BusinessLayer::Warehouse warehouse) {
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	std::ostringstream query2;

	query2 << "SELECT MAX([warehouseID]) ";
	query2 << "FROM dbo.Warehouses";

	temp = dbHelper->sqlexec(query2.str());

	int maxID = std::stoi(temp[0][0]);

	query << "INSERT INTO ";
	query << "dbo.Warehouses([warehouseID], [address], [email], [phoneNumber]) ";
	query << "VALUES (";
	query << std::to_string(maxID + 1) + ", '";
	query << warehouse.getAddress() + "', '";
	query << warehouse.getEmail() + "', '";
	query << warehouse.getPhoneNumber() + "')";

	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Product> Warehouse_db::getOtherProducts(BusinessLayer::Warehouse warehouse) {
	std::vector<std::vector<std::string>> temp;
	std::vector<BusinessLayer::Product> products;
	std::ostringstream query;

	query << "SELECT pd2.[productID], [productName] ";
	query << "FROM dbo.ProductDetails pd2 ";
	query << "EXCEPT ";
	query << "SELECT p.[productID], pd.[productName] ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.[productID] = pd.[productID] ";
	query << "WHERE p.[warehouseID] = " + std::to_string(warehouse.getWarehouseID());

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				0,
				"",
				""
			)
		);
	}

	return products;
}

void Warehouse_db::test() {}
