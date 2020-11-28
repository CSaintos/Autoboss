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
	for (int i = 0; (i < vectorString.size()); ++i) {
		for (int j = 0; (j < vectorString[i].size()); ++j) {
			return vectorString[i][j];
		}
	}
}

void DatabaseCtrl::setPassword(std::string password) {
	std::ostringstream query;
	query << "UPDATE dbo.Credentials ";
	query << "SET [Password] = " << "'" + password + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Warehouse> DatabaseCtrl::getWarehouses() { // TODO
	return std::vector<BusinessLayer::Warehouse>();
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getInventory(BusinessLayer::Warehouse warehouse) { // TODO
	return std::vector<BusinessLayer::Product>();
}

void DatabaseCtrl::addProduct(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) { // TODO
	
}

void DatabaseCtrl::addWarehouse(BusinessLayer::Warehouse warehouse) { // TODO

}

std::vector<BusinessLayer::Salesperson> DatabaseCtrl::getSalespeople() { // TODO
	return std::vector<BusinessLayer::Salesperson>();
}

void DatabaseCtrl::setCommissionRate(BusinessLayer::Salesperson salesperson) { // TODO

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

}

void DatabaseCtrl::addSalesperson(BusinessLayer::Salesperson salesperson) { // TODO

}

void DatabaseCtrl::addOInvoice(BusinessLayer::Invoice openInvoice) { // TODO

}