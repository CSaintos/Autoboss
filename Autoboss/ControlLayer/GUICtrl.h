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

		READ ME FIRST 
		for those that say "lmk if any questions", that is bc some details are TBD. 
		I would leave those ^ todo methods last, but you are free to get started on them as well.
		THANK YOU
		*/
		std::string CreatePassword();
		void EnterPassword(std::string);
		std::string MainMenu(); // prompts user a main menu and must select on option in main menu, it returns that option as string *
		std::string WarehouseSelection(std::vector<BusinessLayer::Warehouse>); // outputs warehouses. Prompts user to choose "back to main menu", or "select warehouse". Returns choice *
		BusinessLayer::Warehouse SelectWarehouse(std::vector<BusinessLayer::Warehouse>); // prompts user to select a warehouse out of the ones listed from WarehouseSelection(), returns warehouse chosen
		std::string Inventory(std::vector<BusinessLayer::Product>); // outputs Inventory for a selected warehouse. Prompts user to choose "back to warehouse selection", or "stock inventory". returns choice
		BusinessLayer::Product AddProduct(std::vector<BusinessLayer::Product>); // Prompts user to select which product to stock up on and how much. Returns chosen product with updated quantity in stock.Done
		BusinessLayer::Warehouse AddWarehouse(); // Prompts user to create a new warehouse. Returns newly created warehouse
		void LowStock(std::vector<BusinessLayer::Product>); // outputs low stock products. They are already checked for low stock, therefore display all products.
		std::string OInvoices(std::vector<BusinessLayer::Invoice>); // outputs open invoices. Prompts user to choose "view open invoice details", "pay invoice", "create invoice", or "back to main menu". Returns choice.
		BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice>); // prompts user to choose which open invoice to view it's details, open invoices should already be outputed with OInvoices(). Returns chosen invoice.
		void OInvoiceDetails(BusinessLayer::Invoice); // outputs all details for open invoice, such as products, cost, total cost, tax, ... lmk if any questions.
		BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>); // prompts user to choose which invoice to pay. Prompts user how much to pay. Returns invoice with updated payment amount.
		BusinessLayer::Invoice CreateInvoice(); // prompts user to create invoice. returns newly created invoice
		std::string CInvoices(std::vector<BusinessLayer::Invoice>); // outputs closed invoices. Prompts user to choose "view closed invoice details", or "back to main menu". Returns choice
		BusinessLayer::Invoice ChooseCInvoice(std::vector<BusinessLayer::Invoice>); // prompts user to choose which closed invoice to view it's details, closed invoices should already be outputed with CInvoices(). Returns chosen invoice.
		void CInvoiceDetails(BusinessLayer::Invoice); // outputs all details for closed invoice, such as products, cost, total cost, tax, ... lmk if any questions.
		//product
		BusinessLayer::Product CreateProduct(); // prompts user to create a product. Do not prompt for quantity. Returns newly created product. DONE
		std::string ProductStats(std::vector<BusinessLayer::Product>); // outputs products. Prompts user to "view product details", or "back to main menu". Returns choice.DONE
		BusinessLayer::Product ChooseProduct(std::vector<BusinessLayer::Product>); // Prompts user to choose which product to view it's details, products should already be outputed with ProductStats(). Returns chosen product.
		void ProductDetails(BusinessLayer::Product); // outputs all details for product, such as name, manufacturer, sale price, ... lmk if any questions.DONE
		BusinessLayer::Product UpdateProduct(std::vector<BusinessLayer::Product>); // outputs products. prompts user to choose which product to update. Prompts what details to update. user determines when done updating. returns updated product.DONE
		
		//salesperon
		std::string Salespeople(std::vector<BusinessLayer::Salesperson>); // outputs salespeople. Prompts user to choose "set commission rate", "add salesperson", "or back to main menu". Returns choice.	
		BusinessLayer::Salesperson SetCommission(std::vector<BusinessLayer::Salesperson>); // Prompts user to select which saleperson to edit commission rate, salepeople should already be outputed with Salespeople(). Retunrs salesperson with updated commission rate.
		BusinessLayer::Salesperson AddSalesperson(); // Prompts user to create new salesperson. Returns newly created salesperson. Yes you created a salesperson; therefore, you created LIFE. :)

		/*
		Layer Logic
		*/
	};
}
#define GUICTRL_H
#endif
