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
		std::string CreatePassword(); // prompts user to create password and returns the password string
		void EnterPassword(std::string); // prompts user to enter password
		std::string MainMenu(); // prompts user a main menu and must select on option in main menu, it returns that option as string
		std::string WarehouseSelection(std::vector<BusinessLayer::Warehouse>); // outputs warehouses. Prompts user to choose "back to main menu", or "select warehouse"
		BusinessLayer::Warehouse SelectWarehouse(std::vector<BusinessLayer::Warehouse>); // prompts user to select a warehouse out of the ones listed from WarehouseSelection(), returns warehouse chosen
		std::string Inventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product AddProduct(std::vector<BusinessLayer::Product>);
		BusinessLayer::Warehouse AddWarehouse();
		void LowStock(std::vector<BusinessLayer::Product>);
		std::string OInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice>);
		void OInvoiceDetails(BusinessLayer::Invoice);
		BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice CreateInvoice();
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

		/*
		Layer Logic
		*/
	};
}
#define GUICTRL_H
#endif
