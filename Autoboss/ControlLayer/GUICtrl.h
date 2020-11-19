#pragma once
#include "GUIHelper.h"
#include "Invoice_ui.h"
#include "MainMenu_ui.h"
#include "Password_ui.h"
#include "Product_ui.h"
#include "Salesperson_ui.h"
#include "Warehouse_ui.h"

namespace ControlLayer {
	class GUICtr {
	protected:
		GUICtr();
		static GUICtr* guiCtr;
	private:
	public:
		// Can't be cloneable
		GUICtr(GUICtr& other) = delete;
		// Can't be assignable
		void operator=(const GUICtr&) = delete;
		// Gets GUICtr singleton object
		static GUICtr* GetInstance();

		/*
		Business Logic
		*/
	};
}