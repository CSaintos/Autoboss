// Invoice_db.h
#pragma once

#ifndef DBHELPER_H
#include "DBHelper.h"
#endif

#ifndef INVOICE_H
#include "Invoice.h"
#endif 

using BusinessLayer::Invoice;

#ifndef INVOICE_DB_H
namespace DatabaseLayer {
	class Invoice_db {
	private:
		DBHelper* dbHelper = nullptr;
	public:
		Invoice_db();

		std::vector<Invoice> getOInvoices();
		BusinessLayer::Invoice getOInvoiceDetails(BusinessLayer::Invoice);
		void payInvoice(BusinessLayer::Invoice);
		std::vector<Invoice> getCInvoices();
		BusinessLayer::Invoice getCInvoiceDetails(BusinessLayer::Invoice);
		void addOInvoice(BusinessLayer::Invoice);
		void test();
	};
}
#define INVOICE_DB_H
#endif