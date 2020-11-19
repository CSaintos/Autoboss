#pragma once
#include "BIZHelper.h"
#include "Invoice_bi.h"
#include "Product_bi.h"
#include "Profits_bi.h"
#include "Salesperson_bi.h"
#include "Warehouse_bi.h"

namespace ControlLayer {
	class BusinessCtrl {
	protected:
		BusinessCtrl();
		static BusinessCtrl* businessCtrl;
	private:
	public:
		// Can't be cloneable
		BusinessCtrl(BusinessCtrl& other) = delete;
		// Can't be assignable
		void operator=(const BusinessCtrl&) = delete;
		// Gets BusinessLayer singleton object
		static BusinessCtrl* GetInstance();

		/*
		Business Logic
		*/
	};
}