// DatabaseCtr.cpp
#ifndef DATABASECTRL_H
#include "DatabaseCtrl.h"
#endif

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() :
	dbHelper(std::make_unique<DBHelper>()),
	invoiceDB(std::make_unique<Invoice_db>()),
	productDB(std::make_unique<Product_db>()),
	salespersonDB(std::make_unique<Salesperson_db>()),
	warehouseDB(std::make_unique<Warehouse_db>())
{}

DatabaseCtrl* DatabaseCtrl::databaseCtrl = nullptr;

DatabaseCtrl* DatabaseCtrl::GetInstance() {
	if (databaseCtrl == nullptr) {
		databaseCtrl = new DatabaseCtrl();
	}
	return databaseCtrl;
}

void DatabaseCtrl::openDB() {
	dbHelper->openDB();
}

void DatabaseCtrl::closeDB() {
	dbHelper->closeDB();
}

void DatabaseCtrl::test() {
	dbHelper->test();
	invoiceDB->test();
	productDB->test();
	salespersonDB->test();
	warehouseDB->test();
}

void DatabaseCtrl::setCurrentDate(std::string date) {
	std::ostringstream query;
	query << "UPDATE dbo.CurrentDate ";
	query << "SET [Date] = " << "'" + date + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::string DatabaseCtrl::getPassword() {
	std::vector<std::vector<std::string>> vectorString;
	vectorString = dbHelper->sqlexec("SELECT [Password] FROM dbo.Credentials WHERE [Id] = 1");
	return vectorString[0][0];
}

void DatabaseCtrl::setPassword(std::string password) {
	std::ostringstream query;
	query << "UPDATE dbo.Credentials ";
	query << "SET [Password] = " << "'" + password + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Warehouse> DatabaseCtrl::getWarehouses() { // TODO KINDA
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM Warehouses");
	std::vector<BusinessLayer::Warehouse> warehouseList;
	std::vector<Product> inv;
	int phoneNumber = 0;
	
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		warehouseList.push_back(Warehouse(inv, std::stoi(contents[0]), contents[1], contents[2], phoneNumber));
	}

	return warehouseList;
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getInventory(BusinessLayer::Warehouse warehouse) { // TODO
	return std::vector<BusinessLayer::Product>();
}

void DatabaseCtrl::addProduct(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) { // TODO
	
}

void DatabaseCtrl::addWarehouse(BusinessLayer::Warehouse warehouse) { // TODO KINDA
	std::ostringstream query;
	query << "INSERT INTO ";
	query << "dbo.Warehouses([warehouseID], [address], [email], [phoneNumber]) ";
	query << "VALUES (";
	query << std::to_string(warehouse.getWarehouseID()) + ", '";
	query << warehouse.getAddress() + "', '";
	query << warehouse.getEmail() + "', '";
	query << "wh.get PhoneNumber()')";
	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Salesperson> DatabaseCtrl::getSalespeople() { // TODO KINDA
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM dbo.SalesPeople");
	std::vector<std::vector<std::string>>::iterator itr;
	std::vector<Salesperson> empList;

	//*itr = EmployeeID, commission rate, name, total commission, total sales amount
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		empList.push_back(Salesperson(std::vector<Invoice>(),
			std::stoi(contents[0]),
			std::stod(contents[1]),
			contents[2],
			std::stod(contents[3]),
			std::stod(contents[4])));
	}

	return empList;
}

void DatabaseCtrl::setCommissionRate(BusinessLayer::Salesperson salesperson) { // TODO KINDA
	std::ostringstream query;
	query << "UPDATE SalesPeople SET commissionRate = ";
	query << std::to_string(salesperson.getCommisionRate());
	query << " WHERE employeeID = ";
	query << std::to_string(salesperson.getEmployeeID());
	dbHelper->sqlexec(query.str());

}

std::vector<BusinessLayer::Product> DatabaseCtrl::getProducts() { // TODO
	return std::vector<BusinessLayer::Product>();
}

BusinessLayer::Product DatabaseCtrl::getProductDetails(BusinessLayer::Product product) { // TODO
	return BusinessLayer::Product();
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getLowStock() { // TODO
	return std::vector<BusinessLayer::Product>();
}

void DatabaseCtrl::createProduct(BusinessLayer::Product product) { // TODO

}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getOInvoices() { // TODO
	return std::vector<BusinessLayer::Invoice>();
}

BusinessLayer::Invoice DatabaseCtrl::getOInvoiceDetails(BusinessLayer::Invoice openInvoice) { // TODO
	return BusinessLayer::Invoice();
}

void DatabaseCtrl::payInvoice(BusinessLayer::Invoice openInvoice) { // TODO

}

void DatabaseCtrl::updateProduct(BusinessLayer::Product product) { // TODO

}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getCInvoices() { // TODO
	return std::vector<BusinessLayer::Invoice>();
}

BusinessLayer::Invoice DatabaseCtrl::getCInvoiceDetails(BusinessLayer::Invoice closedInvoice) { // TODO
	return BusinessLayer::Invoice();
}

void DatabaseCtrl::addSalesperson(BusinessLayer::Salesperson salesperson) { // TODO KINDA
	std::ostringstream query;
	query << "INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount) ";
	query << "VALUES(";
	query << std::to_string(salesperson.getEmployeeID()) + ", ";
	query << std::to_string(salesperson.getCommisionRate()) + ", '";
	query << salesperson.getEmployeeName() + "', ";
	query << std::to_string(salesperson.getTotalCommission()) + ", ";
	query << std::to_string(salesperson.getTotalSalesAmount()) + ")";
	dbHelper->sqlexec(query.str());
}

void DatabaseCtrl::addOInvoice(BusinessLayer::Invoice openInvoice) { // TODO

}