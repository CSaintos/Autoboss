#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef INVOICE_H
#include "Invoice.h"
#endif

#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif

#ifndef INVOICE_UI_H
namespace GUILayer {
	class Invoice_ui {
	private:
	public:
		Invoice_ui();
		string OInvoices(vector<BusinessLayer::Invoice> x);
		BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice>);
		void OInvoiceDetails(BusinessLayer::Invoice);
		BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice CreateInvoice();
		string CInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseCInvoice(std::vector<BusinessLayer::Invoice>);
		void InvoiceDetails(BusinessLayer::Invoice);
	};
}
#define INVOICE_UI_H
#endif