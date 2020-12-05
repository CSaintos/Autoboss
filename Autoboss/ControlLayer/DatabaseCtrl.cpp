// DatabaseCtr.cpp
#ifndef DATABASECTRL_H
#include "DatabaseCtrl.h"
#endif

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() :
	invoiceDB(std::make_unique<Invoice_db>()),
	productDB(std::make_unique<Product_db>()),
	salespersonDB(std::make_unique<Salesperson_db>()),
	warehouseDB(std::make_unique<Warehouse_db>()),
	dbHelper(DBHelper::GetInstance())
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

void DatabaseCtrl::checkAndUpdateEssentials() {
	dbHelper->checkAndUpdateEssentials();
}

void DatabaseCtrl::setCurrentDate(std::string date) {
	dbHelper->setCurrentDate(date);
}

std::string DatabaseCtrl::getCurrentDate() {
	return dbHelper->getCurrentDate();
}

std::string DatabaseCtrl::getPassword() {
	return dbHelper->getPassword();
}

void DatabaseCtrl::setPassword(std::string password) {
	dbHelper->setPassword(password);
}

std::vector<BusinessLayer::Warehouse> DatabaseCtrl::getWarehouses() {
	return warehouseDB->getWarehouses();
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getInventory(BusinessLayer::Warehouse warehouse) {
	return warehouseDB->getInventory(warehouse);
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getAllInventory() {
	return warehouseDB->getAllInventory();
}

void DatabaseCtrl::stockInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) {
	warehouseDB->stockInventory(product, warehouse);
}

void DatabaseCtrl::addInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) {
	warehouseDB->addInventory(product, warehouse);
}

void DatabaseCtrl::addWarehouse(BusinessLayer::Warehouse warehouse) {
	warehouseDB->addWarehouse(warehouse);
}

std::vector<BusinessLayer::Salesperson> DatabaseCtrl::getSalespeople() {
	return salespersonDB->getSalespeople();
}

void DatabaseCtrl::setCommissionRate(BusinessLayer::Salesperson salesperson) {
	salespersonDB->setCommissionRate(salesperson);
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getProducts() {
	return productDB->getProducts();
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getOtherProducts(BusinessLayer::Warehouse warehouse) {
	return warehouseDB->getOtherProducts(warehouse);
}

BusinessLayer::Product DatabaseCtrl::getProductDetails(BusinessLayer::Product product) {
	return productDB->getProductDetails(product);
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getLowStock() {
	return productDB->getLowStock();
}

void DatabaseCtrl::createProduct(BusinessLayer::Product product) {
	productDB->createProduct(product);
}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getOInvoices() {
	return invoiceDB->getOInvoices();
}

BusinessLayer::Invoice DatabaseCtrl::getOInvoiceDetails(BusinessLayer::Invoice openInvoice) {
	return invoiceDB->getOInvoiceDetails(openInvoice);
}

void DatabaseCtrl::payInvoice(BusinessLayer::Invoice openInvoice) {
	invoiceDB->payInvoice(openInvoice);
}

void DatabaseCtrl::updateProduct(BusinessLayer::Product product) {
	productDB->updateProduct(product);
}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getCInvoices() {
	return invoiceDB->getCInvoices();
}

BusinessLayer::Invoice DatabaseCtrl::getCInvoiceDetails(BusinessLayer::Invoice closedInvoice) {
	return invoiceDB->getCInvoiceDetails(closedInvoice);
}

void DatabaseCtrl::addSalesperson(BusinessLayer::Salesperson salesperson) {
	salespersonDB->addSalesperson(salesperson);
}

void DatabaseCtrl::addOInvoice(BusinessLayer::Invoice openInvoice) {
	invoiceDB->addOInvoice(openInvoice);
}

void DatabaseCtrl::reset() {
	dbHelper->reset();
}