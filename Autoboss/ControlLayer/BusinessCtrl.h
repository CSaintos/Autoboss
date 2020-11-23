// BusinessCtrl.h
#pragma once

#include "BIZHelper.h"
//#include "Invoice.h"
//#include "Product.h"
//#include "Profits.h"
//#include "Salesperson.h"
//#include "Warehouse.h"

#include <memory>

namespace ControlLayer {
	class BusinessCtrl {
	protected:
		BusinessCtrl();

		static BusinessCtrl* businessCtrl;

		std::unique_ptr<BusinessLayer::BIZHelper> bizHelper;
	private:
	public:
		/*
		Singleton Logic
		*/
			// Can't be cloneable
		BusinessCtrl(BusinessCtrl& other) = delete;
			// Can't be assignable
		void operator=(const BusinessCtrl&) = delete;
			// Gets BusinessLayer singleton object
		static BusinessCtrl* GetInstance();

		/*
		Initialization Logic
		*/
		void test();
		/*
		Main Logic
		*/
		void getDate() {}
		/*
		Layer Logic
		*/
	};
}