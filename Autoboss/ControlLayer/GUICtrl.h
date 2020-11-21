#pragma once
#include "GUIHelper.h"
#include "Invoice_ui.h"
#include "MainMenu_ui.h"
#include "Password_ui.h"
#include "Product_ui.h"
#include "Salesperson_ui.h"
#include "Warehouse_ui.h"
#include <memory>

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
		/*
		Layer Logic
		*/
	};
}