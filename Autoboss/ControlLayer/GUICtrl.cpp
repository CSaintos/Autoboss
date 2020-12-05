// GUICtrl.cpp
#ifndef GUICTRL_H
#include "GUICtrl.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;

GUICtrl::GUICtrl() : 
	guiHelper(std::make_unique<GUIHelper>()),
	invoiceUI(std::make_unique<Invoice_ui>()),
	mainmenuUI(std::make_unique<MainMenu_ui>()),
	passwordUI(std::make_unique<Password_ui>()),
	productUI(std::make_unique<Product_ui>()),
	salespersonUI(std::make_unique<Salesperson_ui>()),
	warehouseUI(std::make_unique<Warehouse_ui>())
{}

GUICtrl* GUICtrl::guiCtrl = nullptr;

GUICtrl* GUICtrl::GetInstance() {
	if (guiCtrl == nullptr) {
		guiCtrl = new GUICtrl();
	}
	return guiCtrl;
}

void GUICtrl::test() {
	guiHelper->test();
}

std::string GUICtrl::CreatePassword() {
	return passwordUI->CreatePassword();
}

void GUICtrl::EnterPassword(std::string password) {
	passwordUI->EnterPassword(password);
}

std::string GUICtrl::MainMenu() {
	return mainmenuUI->Display();
}

std::string GUICtrl::WarehouseSelection(std::vector<BusinessLayer::Warehouse> warehouses) {
	return warehouseUI->WarehouseSelection(warehouses);
}

BusinessLayer::Warehouse GUICtrl::SelectWarehouse(std::vector<BusinessLayer::Warehouse> warehouses) {
	return warehouseUI->SelectWarehouse(warehouses);
}

std::string GUICtrl::Inventory(std::vector<BusinessLayer::Product> products) {
	return productUI->Inventory(products);
}

BusinessLayer::Product GUICtrl::StockInventory(std::vector<BusinessLayer::Product> products) {
	return productUI->StockInventory(products);
}

BusinessLayer::Product GUICtrl::AddInventory(std::vector<BusinessLayer::Product> products) {
	return productUI->AddInventory(products);
}

BusinessLayer::Warehouse GUICtrl::AddWarehouse() {
	return warehouseUI->AddWarehouse();
}

std::string GUICtrl::Salespeople(std::vector<BusinessLayer::Salesperson> salespeople) {
	return salespersonUI->Salespeople(salespeople);
}

BusinessLayer::Salesperson GUICtrl::SetCommission(std::vector<BusinessLayer::Salesperson> salespeople) {
	return salespersonUI->SetCommission(salespeople);
}

std::string GUICtrl::ProductStats(std::vector<BusinessLayer::Product> products) {
	return productUI->ProductStats(products);
}

BusinessLayer::Product GUICtrl::ChooseProduct(std::vector<BusinessLayer::Product> products) {
	return productUI->ChooseProduct(products);
}

void GUICtrl::ProductDetails(BusinessLayer::Product product) {
	productUI->productDetail(product);
}

void GUICtrl::LowStock(std::vector<BusinessLayer::Product> products) {
	productUI->LowStock(products);
}

BusinessLayer::Product GUICtrl::CreateProduct() {
	return productUI->CreateProduct();
}

std::string GUICtrl::OInvoices(std::vector<BusinessLayer::Invoice> openInvoices) {
	return invoiceUI->OInvoices(openInvoices);
}

BusinessLayer::Invoice GUICtrl::ChooseOInvoice(std::vector<BusinessLayer::Invoice> openInvoices) {
	return invoiceUI->ChooseOInvoice(openInvoices);
}

void GUICtrl::OInvoiceDetails(BusinessLayer::Invoice openInvoice) {
	invoiceUI->OInvoiceDetails(openInvoice);
}

BusinessLayer::Invoice GUICtrl::PayInvoice(std::vector<BusinessLayer::Invoice> invoicePayment) {
	return invoiceUI->PayInvoice(invoicePayment);
}

BusinessLayer::Product GUICtrl::UpdateProduct(std::vector<BusinessLayer::Product> products) {
	return productUI->UpdateProduct(products);
}

std::string GUICtrl::CInvoices(std::vector<BusinessLayer::Invoice> closedInvoices) {
	return invoiceUI->CInvoices(closedInvoices);
}

BusinessLayer::Invoice GUICtrl::ChooseCInvoice(std::vector<BusinessLayer::Invoice> closedInvoices) {
	return invoiceUI->ChooseCInvoice(closedInvoices);
}

void GUICtrl::CInvoiceDetails(BusinessLayer::Invoice closedInvoice) {
	invoiceUI->CInvoiceDetails(closedInvoice);
}

BusinessLayer::Salesperson GUICtrl::AddSalesperson() {
	return salespersonUI->AddSalesperson();
}

BusinessLayer::Invoice GUICtrl::CreateInvoice(std::vector<BusinessLayer::Product> allInventory, std::vector<BusinessLayer::Salesperson> salespeople) {
	return invoiceUI->CreateInvoice(allInventory, salespeople);
}

std::string GUICtrl::Settings() {
	return mainmenuUI->Settings();
}