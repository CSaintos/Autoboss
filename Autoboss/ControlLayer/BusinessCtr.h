#pragma once
#include "BIZHelper.h"
#include "Invoice_bi.h"
#include "Product_bi.h"
#include "Profits_bi.h"
#include "Salesperson_bi.h"
#include "Warehouse_bi.h"

namespace ControlLayer {
	class BusinessCtr {
	protected:
		BusinessCtr();
		static BusinessCtr* businessCtr;
	private:
	public:
		// Can't be cloneable
		BusinessCtr(BusinessCtr& other) = delete;
		// Can't be assignable
		void operator=(const BusinessCtr&) = delete;
		// Gets BusinessLayer singleton object
		static BusinessCtr* GetInstance();

		/*
		Business Logic
		*/
	};
}