// Invoice_ui.cpp
#ifndef INVOICE_UI_H
#include "Invoice_ui.h"
#endif

using namespace GUILayer;
using namespace std;

Invoice_ui::Invoice_ui()
{}

string Invoice_ui::OInvoices(vector<BusinessLayer::Invoice> oinvoices) {
	string choice;

	cout << "******************************************************" << endl;
	cout << "*******************Open Invoices**********************" << endl;

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		cout << fixed;
		cout << setprecision(2);
		cout << "PO Num: " << to_string(itr->getPONumber()) << " | "
			<< "Total Amount: " << itr->getTotalAmount() << " | "
			<< "Order Date: " << itr->getOrderDate() << endl;
	}

	cout << "******************************************************" << endl;;
	cout << "1. View Open Invoice Details" << endl;
	cout << "2. Pay Invoice" << endl;
	cout << "3. Create Invoie" << endl;
	cout << "4. Back to Main Menu" << endl;

	do {
		cout << "Please input choice:" << endl;
		std::getline(cin, choice);
	} while (choice != "1" && choice != "2" && choice != "3" && choice != "4");

	return choice;
}

BusinessLayer::Invoice Invoice_ui::ChooseOInvoice(std::vector<BusinessLayer::Invoice> oinvoices) {
	vector<string> choices;
	string choice;

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		choices.push_back(to_string(itr->getPONumber()));
	}

	do {
		cout << "Please input PO Number, select 0 to exit:" << endl;
		std::getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	if (choice == "0") {
		return BusinessLayer::Invoice();
	}

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		if (to_string(itr->getPONumber()) == choice) {
			return *itr;
		}
	}

	return BusinessLayer::Invoice();
}

void Invoice_ui::OInvoiceDetails(BusinessLayer::Invoice oinvoice) {
	if (oinvoice.getPONumber() != 0) {
		vector<BusinessLayer::Product> products = oinvoice.getProductsOrdered();

		cout << "******************************************************" << endl;
		cout << "********************Invoice Details*******************" << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << "PO Number: " << to_string(oinvoice.getPONumber()) << endl;
		cout << "Invoice Number: " << to_string(oinvoice.getInvoiceNumber()) << endl;
		cout << "Interest Rate: %" << (oinvoice.getInterestRate() * 100) << endl;
		cout << "Discount Rate: %" << (oinvoice.getDiscountRate() * 100) << endl;
		cout << "Sale Total: $" << oinvoice.getTotalAmount() << endl;
		cout << "Order Date: " << oinvoice.getOrderDate() << endl;
		cout << "Delivery Charge: $" << oinvoice.getDeliveryCharge() << endl;
		cout << "Sales Representative ID: " << to_string(oinvoice.getSalesRepID()) << endl;
		cout << "***********************Products***********************" << endl;

		for (auto itr = products.begin(); itr != products.end(); ++itr) {
			cout << fixed;
			cout << setprecision(2);
			cout << "ID: " << to_string(itr->getProductID()) << " | "
				<< "Name: " << itr->getName() << " | "
				<< "Price Each: $" << itr->getPrice() << " | "
				<< "Quantity Ordered: " << to_string(itr->getQuantityOrdered()) << endl;
		}

		cout << "******************************************************" << endl;
	}
	cout << endl;
}

BusinessLayer::Invoice Invoice_ui::PayInvoice(std::vector<BusinessLayer::Invoice> oinvoices)
{
	BusinessLayer::Invoice payedInvoice;
	vector<string> choices;
	string choice;
	double payment;

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		choices.push_back(to_string(itr->getPONumber()));
	}
	do {
		cout << "Please select an invoice PO Number, select 0 to exit:" << endl;
		cin >> choice;
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	if (choice == "0") {
		return BusinessLayer::Invoice();
	}

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		if (to_string(itr->getPONumber()) == choice) {
			payedInvoice = *itr;
			break;
		}
	}

	do {
		cout << "Please input payment amount: " << endl;
	} while (!(cin >> payment));
	
	getline(cin, choice); // catch space error

	payedInvoice.setAmountPaid(payment);

	return payedInvoice;
}

BusinessLayer::Invoice Invoice_ui::CreateInvoice(vector<BusinessLayer::Product> allInventory) {
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
	std::getline(cin, orderdate);
	cout << "Please input Invoice CLOSE date:" << endl;
	std::getline(cin, closeDate);
	cout << "Please input Billing Address:" << endl;
	std::getline( cin, billto);
	cout << "Please input Shipping Address:" << endl;
	std::getline(cin, shipto);
	cout << "Please input PO Number:" << endl;
	cin >> poNum;
	cout << "Please input Sales Representative ID:" << endl;
	cin >> salesRepID;
	cout << "Please input Interest Rate:" << endl;
	cin >> interestRate;
	cout << "Please input Interest Applied:" << endl;
	cin >> InterestApplied;
	cout << "Discount Applied? (Input 1 for true or Input 0 for false )";
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
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << "Invoice " << x[i].getInvoiceNumber() << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	cout << "1.View Close Invoice Details" << endl;
	cout << "2.Back to Main Menu" << endl;
	std::getline(cin, response);
	return response;
}

BusinessLayer::Invoice Invoice_ui::ChooseCInvoice(std::vector<BusinessLayer::Invoice> x)
{
	string choice;
	cout << "Please Select a Closed Invoice:";
	cin >> choice;
	int selection = std::stoi(choice);
	selection = selection - 1;


	return x[selection];
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
	cout << "Discount Applied: " << boolalpha << discount << ".......Discount Rate: " << x.getDiscountRate() << "%" << endl;
	cout << "Delivery Charge: $" << x.getDeliveryCharge() << ".......Interest Rate: " << x.getInterestRate() << "%" << endl;
	cout << "*****************************************************************" << endl;
	cout << "*****************************************************************" << endl;
	cout << "Total: $" << x.getTotalAmount() << "\n-$" << x.getAmountPaid() << "\n-------------" << endl;
	cout << "$" << x.getCurrentAmount() << ".......Total Due" << endl;
	cout << "*******************THIS IS PAID IN FULL**************************" << endl;
}
