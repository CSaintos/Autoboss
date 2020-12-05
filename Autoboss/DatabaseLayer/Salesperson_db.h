// Salesperson_db.h
#pragma once

#ifndef DBHELPER_H
#include "DBHelper.h"
#endif
#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif
#ifndef INVOICE_H
#include "Invoice.h"
#endif

#ifndef SALESPERSON_DB_H
namespace DatabaseLayer {
	class Salesperson_db {
	private:
		DBHelper* dbHelper = nullptr;
	public:
		Salesperson_db();

		std::vector<BusinessLayer::Salesperson> getSalespeople();
		void setCommissionRate(BusinessLayer::Salesperson);
		void addSalesperson(BusinessLayer::Salesperson);
		void test();
	};
}
#define SALESPERSON_DB_H
#endif