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
		std::vector<Invoice> openInvoices;
		std::vector<Invoice> closedInvoices;
		DBHelper helper;
	public:
		Invoice_db();
		std::vector<Invoice> getOInvoices();
		std::vector<Invoice> getCInvoices();
		void payInvoice(Invoice inv, int payment);
		void createInvoice(Invoice inv);
	};
}
#define INVOICE_DB_H
#endif