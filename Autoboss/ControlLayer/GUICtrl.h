// GUICtrl.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif
#ifndef INVOICE_UI_H
#include "Invoice_ui.h"
#endif
#ifndef MAINMENU_H
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

#ifndef MEMORY
#include <memory>
#define MEMORY
#endif

#ifndef GUICTRL_H
namespace ControlLayer {
	class GUICtrl {
	protected:
		GUICtrl();

		static GUICtrl* guiCtrl;

		std::unique_ptr<GUILayer::GUIHelper> guiHelper;
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
		void displayCreatePassword() {}
		void displayPassword() {}
		void displayMainMenu() {}
		void displayWarehouseSelection() {}
		void displayInventory(/*warehouse param*/) {}
		void displayAddProduct() {}
		void displayAddWarehouse() {}
		void displayLowStock() {}
		void displayOInvoices() {}
		void displayPayInvoice() {}
		void displayCreateInvoice() {}
		void displayCInvoices() {}
		void displayCreateProduct() {}
		void displayProductStats() {}
		void displayProductDetails() {}
		void displayUpdateProduct() {}
		void displaySalespeople() {}
		void displayAddSalesperson() {}

		/*
		Layer Logic
		*/
	};
}
#define GUICTRL_H
#endif
