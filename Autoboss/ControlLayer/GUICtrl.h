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
		std::string CreatePassword();
		void EnterPassword(std::string);
		std::string MainMenu();
		void WarehouseSelection() {}
		void Inventory(/*warehouse param*/) {}
		void AddProduct() {}
		void AddWarehouse() {}
		void LowStock() {}
		void OInvoices() {}
		void PayInvoice() {}
		void CreateInvoice() {}
		void CInvoices() {}
		void CreateProduct() {}
		void ProductStats() {}
		void ProductDetails() {}
		void UpdateProduct() {}
		void Salespeople() {}
		void AddSalesperson() {}

		/*
		Layer Logic
		*/
	};
}
#define GUICTRL_H
#endif
