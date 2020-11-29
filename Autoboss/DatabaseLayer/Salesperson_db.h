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

using BusinessLayer::Salesperson;

#ifndef SALESPERSON_DB_H
namespace DatabaseLayer {
	class Salesperson_db {
	private:
		std::vector<Salesperson> employees;
		DBHelper helper;
	public:
		Salesperson_db();
		std::vector<Salesperson> getSalespeople();
		void addSalesperson(Salesperson emp);
		void setCommissionRate(Salesperson emp, double newRate);
		void test();
	};
}
#define SALESPERSON_DB_H
#endif