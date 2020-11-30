// Invoice_ui.cpp
#ifndef INVOICE_UI_H
#include "Invoice_ui.h"
#endif

using namespace GUILayer;
using namespace std;

Invoice_ui::Invoice_ui()
{}

string Invoice_ui::OInvoices(vector<BusinessLayer::Invoice> x)
{
	string response;
	cout << "*****************************************************************" << endl;
	cout << "**********************Open Invoices*************************" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) <<"Invoice " << x.at(i).getInvoiceNumber() << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	cout << "1.View Open Invoice Details" << endl;
	cout << "2.Pay Invoice" << endl;
	cout << "3.Create Invoie" << endl;
	cout << "4.Back to Main Menu" << endl;
	cin >> response;
	return response;
}

BusinessLayer::Invoice Invoice_ui::ChooseOInvoice(std::vector<BusinessLayer::Invoice> x)
{
	string choice;
		cout << "Please Select Invoice:";
		cin >> choice;
		int selection = std::stoi(choice);
		selection = selection - 1;
	
	
	return x.at(selection);
}

void Invoice_ui::OInvoiceDetails(BusinessLayer::Invoice x)
{
	int items = x.getProductsOrdered().size();
	bool discount = x.getDiscountApplied();
	vector <BusinessLayer::Product> inventory = x.getProductsOrdered();
	cout << "*****************************************************************" << endl;
	cout << "**********************"<<x.getInvoiceNumber()<<" Invoice Details*************************" << endl;
	cout << "Invoice Number:" << x.getInvoiceNumber() << "........Date:" << x.getOrderDate() << endl;
	cout << "Sales Representative ID: " << x.getSalesRepID() << ".......Close Date: " << x.getCloseDate();
	cout << "Ship to:" << x.getShipTo() << ".......Bill to:" << x.getBillTo() << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	for (int i = 0; i < items; i++)
	{
		cout << (i + 1) << "." << inventory.at(i).getName() << endl;
	}
	cout << "Discount Applied: " << boolalpha << discount << ".......Discoutn Rate: " << x.getDiscountRate() << "%" << endl;
	cout << "Delivery Charge: $" << x.getDeliveryCharge() << ".......Interest Rate: " << x.getInterestRate() << "%" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "Total: $" << x.getTotalAmount() << "\n-$" << x.getAmountPaid() << "\n-------------" << endl;
	cout << "$" << x.getCurrentAmount() << ".......Total Due" << endl;



}

BusinessLayer::Invoice Invoice_ui::PayInvoice(std::vector<BusinessLayer::Invoice> x)
{
	double payment;
	string answer;
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << "." << x.at(i).getInvoiceNumber() << endl;

	}
	cout << "******************************************************" << endl;
	cout << "Please select an invoice:" << endl;
	cin >> answer;
	int choi = std::stoi(answer);
	choi = choi - 1;
	cout << "******************************************************" << endl;
	cout << "********************Pay Invoice***********************" << endl;
	cout << "Invoice "<<x.at(choi).getInvoiceNumber()<<"'s current balance is : $" << x.at(choi).getCurrentAmount() << endl;
	cout << "Please input payment amount:\n$";
	cin >> payment;
	x.at(choi).Payment(payment);
	return x.at(choi);
}

BusinessLayer::Invoice Invoice_ui::CreateInvoice()
{
	
	int invoiceNum, poNum, salesRepID, InterestApplied;
	string billto, shipto, orderdate, closeDate;
	double totalAmount, deliveryCharge, amountPaid;
	bool discountApplied;
	float interestRate, discountRate;
	vector<BusinessLayer::Product> productsOrdered = vector<BusinessLayer::Product>();
	cout << "*********************************************************" << endl;
	cout << "********************New Invoice <3***********************" << endl;
	cout << "\nPlease input Invoice Number:" << endl;
	cin >> invoiceNum;
	
	cout << "Please input Invoice Order Date:" << endl;
	cin >> orderdate;
	cout << "Please input Invoice CLOSE date:" << endl;
	cin >> closeDate;
	cout << "Please input Billing Address:" << endl;
	cin >> billto;
	cout << "Please input Shipping Address:" << endl;
	cin >> shipto;
	cout << "Please input PO Number:" << endl;
	cin >> poNum;
	cout << "Please input Sales Representative ID:" << endl;
	cin >> salesRepID;
	cout << "Please input Interest Rate:" << endl;
	cin >> interestRate;
	cout << "Please input Interest Applied:" << endl;
	cin >> InterestApplied;
	cout << "Discount Applied? true or false ";
	cin >> discountApplied;
	cout << "Please input Discount Rate:" << endl;
	cin >> discountRate;
	cout << "Please input Delivery Charge:" << endl;
	cin >> deliveryCharge;
	cout << "Please input TOTAL AMOUNT DUE:" << endl;
	cin >> totalAmount;
	cout << "Please input amount paid:" << endl;
	cin >> amountPaid;
	 
	 BusinessLayer::Invoice newInvoice( 
		 productsOrdered,
		 invoiceNum,poNum,
		 interestRate,
		 discountRate,
		 totalAmount,
		 deliveryCharge,
		 discountApplied,
		 "", // bill to // FIXME
		 "", // ship to // FIXME
		 "", // order Date... Leave this one to the control layer
		 amountPaid,
		 "", // close date... control layer
		 0, // sales rep id... needs fixing by control layer... will do
		 0 // interest applied, leave this zero
	 );
	 return newInvoice;

}

string Invoice_ui::CInvoices(std::vector<BusinessLayer::Invoice>x)
{
	string response;
	cout << "*****************************************************************" << endl;
	cout << "**********************Closed Invoices*************************" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << "Invoice " << x.at(i).getInvoiceNumber() << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	cout << "1.View Close Invoice Details" << endl;
	cout << "2.Back to Main Menu" << endl;
	cin >> response;
	return response;
}

BusinessLayer::Invoice Invoice_ui::ChooseCInvoice(std::vector<BusinessLayer::Invoice> x)
{
	string choice;
	cout << "Please Select a Closed Invoice:";
	cin >> choice;
	int selection = std::stoi(choice);
	selection = selection - 1;


	return x.at(selection);
}

void Invoice_ui::CInvoiceDetails(BusinessLayer::Invoice x)
{
	int items = x.getProductsOrdered().size();
	bool discount = x.getDiscountApplied();
	vector <BusinessLayer::Product> inventory = x.getProductsOrdered();
	cout << "*************************THIS IS PAID IN FULL********************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "**********************" << x.getInvoiceNumber() << " Invoice Details*************************" << endl;
	cout << "Invoice Number:" << x.getInvoiceNumber() << "........Date:" << x.getOrderDate() << endl;
	cout << "Sales Representative ID: " << x.getSalesRepID() << ".......Close Date: " << x.getCloseDate();
	cout << "Ship to:" << x.getShipTo() << ".......Bill to:" << x.getBillTo() << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	for (int i = 0; i < items; i++)
	{
		cout << (i + 1) << "." << inventory.at(i).getName() << endl;
	}
	cout << "Discount Applied: " << boolalpha << discount << ".......Discoutn Rate: " << x.getDiscountRate() << "%" << endl;
	cout << "Delivery Charge: $" << x.getDeliveryCharge() << ".......Interest Rate: " << x.getInterestRate() << "%" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "Total: $" << x.getTotalAmount() << "\n-$" << x.getAmountPaid() << "\n-------------" << endl;
	cout << "$" << x.getCurrentAmount() << ".......Total Due" << endl;
	cout << "*******************THIS IS PAID IN FULL**************************" << endl;
}
