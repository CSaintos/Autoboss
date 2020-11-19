#pragma once
#include "BIZHelper.h"
#include "Invoice.h"
#include "Product.h"
#include "Profits.h"
#include "Salesperson.h"
#include "Warehouse.h"

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