// GUICtrl.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif
#ifndef INVOICE_UI_H
#include "Invoice_ui.h"
#endif
#ifndef MAINMENU_UI_H
#include "MainMenu_ui.h"
#endif
#ifndef PASSWORD_UI_H
#include "Password_ui.h"
#endif
#ifndef PRODUCT_UI_H
#include "Product_ui.h"
#endif
#ifndef SALESPERSON_UI_H
#include "Salesperson_ui.h"
#endif
#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif
#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif
#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif

#ifndef MEMORY
#include <memory>
#define MEMORY
#endif
#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

#ifndef GUICTRL_H
namespace ControlLayer {
	class GUICtrl {
	protected:
		GUICtrl();

		static GUICtrl* guiCtrl;

		std::unique_ptr<GUILayer::GUIHelper> guiHelper;
		std::unique_ptr<GUILayer::Invoice_ui> invoiceUI;
		std::unique_ptr<GUILayer::MainMenu_ui> mainmenuUI;
		std::unique_ptr<GUILayer::Password_ui> passwordUI;
		std::unique_ptr<GUILayer::Product_ui> productUI;
		std::unique_ptr<GUILayer::Salesperson_ui> salespersonUI;
		std::unique_ptr<GUILayer::Warehouse_ui> warehouseUI;
	private:
	public:
		/*
		Singleton Logic
		*/
			// Can't be cloneable
		GUICtrl(GUICtrl& other) = delete;
			// Can't be assignable
		void operator=(const GUICtrl&) = delete;
			// Gets GUICtr singleton object
		static GUICtrl* GetInstance();

		/*
		Initialization Logic
		*/
		void test();
		/*
		Main Logic
		*/
		std::string CreatePassword();
		void EnterPassword(std::string);
		std::string MainMenu();
		std::string WarehouseSelection(std::vector<BusinessLayer::Warehouse>);
		BusinessLayer::Warehouse SelectWarehouse(std::vector<BusinessLayer::Warehouse>);
		std::string Inventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product StockInventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product AddInventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Warehouse AddWarehouse();
		void LowStock(std::vector<BusinessLayer::Product>);
		std::string OInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice>);
		void OInvoiceDetails(BusinessLayer::Invoice);
		BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice CreateInvoice(std::vector<BusinessLayer::Product>, std::vector<BusinessLayer::Salesperson>);
		std::string CInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseCInvoice(std::vector<BusinessLayer::Invoice>);
		void CInvoiceDetails(BusinessLayer::Invoice);
		BusinessLayer::Product CreateProduct();
		std::string ProductStats(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product ChooseProduct(std::vector<BusinessLayer::Product>);
		void ProductDetails(BusinessLayer::Product);
		BusinessLayer::Product UpdateProduct(std::vector<BusinessLayer::Product>);
		std::string Salespeople(std::vector<BusinessLayer::Salesperson>);	
		BusinessLayer::Salesperson SetCommission(std::vector<BusinessLayer::Salesperson>);
		BusinessLayer::Salesperson AddSalesperson();
		std::string Settings();
		/*
		Layer Logic
		*/
	};
}
#define GUICTRL_H
#endif
