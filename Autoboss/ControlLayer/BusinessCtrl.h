// BusinessCtrl.h
#pragma once

#ifndef BIZHELPER_H
#include "BIZHelper.h"
#endif
#ifndef INVOICE_H
#include "Invoice.h"
#endif
#ifndef PRODUCT_H
#include "Product.h"
#endif
#ifndef PROFITS_H
#include "Profits.h"
#endif
#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif
#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif

#ifndef STRING
#include <string>
#define STRING
#endif
#ifndef SSTREAM
#include <sstream>
#define SSTREAM
#endif
#ifndef MEMORY
#include <memory>
#define MEMORY
#endif
#ifndef CTIME
#include <ctime>
#define CTIME
#endif

#ifndef BUSINESSCTRL_H
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
		std::string getDate();
		/*
		Layer Logic
		*/
	};
}
#define BUSINESSCTRL_H
#endif BUSINESSCTRL_H