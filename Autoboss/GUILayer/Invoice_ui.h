#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif
#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif
#ifndef INVOICE_H
#include "Invoice.h"
#endif
#ifndef PRODUCT_H
#include "Product.h"
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
		
		std::string OInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice>);
		void OInvoiceDetails(BusinessLayer::Invoice);
		BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice CreateInvoice(std::vector<BusinessLayer::Product>, std::vector<BusinessLayer::Salesperson>);
		std::string CInvoices(std::vector<BusinessLayer::Invoice>);
		BusinessLayer::Invoice ChooseCInvoice(std::vector<BusinessLayer::Invoice>);
		void CInvoiceDetails(BusinessLayer::Invoice);
	};
}
#define INVOICE_UI_H
#endif