// Invoice_ui.cpp
#ifndef INVOICE_UI_H
#include"Invoice_ui.h"
#endif

using namespace GUILayer;
using namespace std;

Invoice_ui::Invoice_ui()
{}

string OInvoices(vector<BusinessLayer::Invoice> x)
{
	string response;
	cout << "*****************************************************************" << endl;
	cout << "**********************Open Invoices*************************" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << x.at(i).getOrderDate() << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	cout << "1.View Open Invoice Details" << endl;
	cout << "2.Pay Invoice" << endl;
	cout << "3.Back to Main Menu" << endl;
	cin >> response;
	return response;
}

BusinessLayer::Invoice ChooseOInvoice(std::vector<BusinessLayer::Invoice> x)
{
	string choice;
		cout << "Please Select Invoice:";
		cin >> choice;
		int selection = std::stoi(choice);
		selection = selection - 1;
	
	
	return x.at(selection);
}

void OInvoiceDetails(BusinessLayer::Invoice)
{
}

BusinessLayer::Invoice PayInvoice(std::vector<BusinessLayer::Invoice>)
{
	return BusinessLayer::Invoice();
}

BusinessLayer::Invoice CreateInvoice()
{
	return BusinessLayer::Invoice();
}

string CInvoices(std::vector<BusinessLayer::Invoice>)
{
	return string();
}

BusinessLayer::Invoice ChooseCInvoice(std::vector<BusinessLayer::Invoice>)
{
	return BusinessLayer::Invoice();
}

void InvoiceDetails(BusinessLayer::Invoice)
{
}
