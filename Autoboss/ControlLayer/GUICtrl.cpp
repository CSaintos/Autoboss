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

std::string GUICtrl::Inventory(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->Inventory(products);
}

BusinessLayer::Product GUICtrl::StockInventory(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->StockInventory(products);
}

BusinessLayer::Product GUICtrl::AddInventory(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->AddInventory(products);
}

BusinessLayer::Warehouse GUICtrl::AddWarehouse() { // TODO
	return warehouseUI->AddWarehouse();
}

std::string GUICtrl::Salespeople(std::vector<BusinessLayer::Salesperson> salespeople) { // TODO
	return salespersonUI->Salespeople(salespeople);
}

BusinessLayer::Salesperson GUICtrl::SetCommission(std::vector<BusinessLayer::Salesperson> salespeople) {
	return salespersonUI->SetCommission(salespeople);
}

std::string GUICtrl::ProductStats(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->ProductStats(products);
}

BusinessLayer::Product GUICtrl::ChooseProduct(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->ChooseProduct(products);
}

void GUICtrl::ProductDetails(BusinessLayer::Product product) { // TODO
	productUI->productDetail(product);
}

void GUICtrl::LowStock(std::vector<BusinessLayer::Product> products) { // TODO
	productUI->LowStock(products);
}

BusinessLayer::Product GUICtrl::CreateProduct() { // TODO
	return productUI->CreateProduct();
}

std::string GUICtrl::OInvoices(std::vector<BusinessLayer::Invoice> openInvoices) { // TODO
	return invoiceUI->OInvoices(openInvoices);
}

BusinessLayer::Invoice GUICtrl::ChooseOInvoice(std::vector<BusinessLayer::Invoice> openInvoices) { // TODO
	return invoiceUI->ChooseOInvoice(openInvoices);
}

void GUICtrl::OInvoiceDetails(BusinessLayer::Invoice openInvoice) { // TODO
	invoiceUI->OInvoiceDetails(openInvoice);
}

BusinessLayer::Invoice GUICtrl::PayInvoice(std::vector<BusinessLayer::Invoice> invoicePayment) { // TODO
	return invoiceUI->PayInvoice(invoicePayment);
}

BusinessLayer::Product GUICtrl::UpdateProduct(std::vector<BusinessLayer::Product> products) { // TODO
	return productUI->UpdateProduct(products);
}

std::string GUICtrl::CInvoices(std::vector<BusinessLayer::Invoice> closedInvoices) { // TODO
	return invoiceUI->CInvoices(closedInvoices);
}

BusinessLayer::Invoice GUICtrl::ChooseCInvoice(std::vector<BusinessLayer::Invoice> closedInvoices) { // TODO
	return invoiceUI->ChooseCInvoice(closedInvoices);
}

void GUICtrl::CInvoiceDetails(BusinessLayer::Invoice closedInvoice) { // TODO
	invoiceUI->CInvoiceDetails(closedInvoice);
}

BusinessLayer::Salesperson GUICtrl::AddSalesperson() { // Done
	return salespersonUI->AddSalesperson();
}

BusinessLayer::Invoice GUICtrl::CreateInvoice(std::vector<BusinessLayer::Product> allInventory) { // TODO
	return invoiceUI->CreateInvoice(allInventory);
}