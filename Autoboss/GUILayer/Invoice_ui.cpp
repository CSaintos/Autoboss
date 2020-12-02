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

BusinessLayer::Invoice Invoice_ui::CreateInvoice(vector<BusinessLayer::Product> allInventory, vector<BusinessLayer::Salesperson> salespeople) {
	vector<BusinessLayer::Product> productsOrdered;
	BusinessLayer::Product productTemp;
	string billto = "", shipto = "", choice = "", choice2 = "", dummy = "";
	vector<string> choices;
	int invoiceNum = 0, salesRepID = 0, quantity = 0;
	double totalAmount = 0.0, deliveryCharge = 0.0;
	float interestRate = 0.0f, discountRate = 0.0f;

	cout << "*********************Salespeople**********************" << endl;

	for (auto itr = salespeople.begin(); itr != salespeople.end(); ++itr) {
		cout << "EmployeeID: " << to_string(itr->getEmployeeID()) << " | "
			<< "Name: " << itr->getEmployeeName() << endl;
		choices.push_back(to_string(itr->getEmployeeID()));
	}

	cout << "******************************************************" << endl;

	do {
		cout << "Please select employeeID which made the sale, select 0 to exit" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	cout << endl;

	if (choice == "0") {
		return BusinessLayer::Invoice();
	}

	salesRepID = stoi(choice);

	choices.clear();

	cout << "***********************Products***********************" << endl;

	for (auto itr = allInventory.begin(); itr != allInventory.end(); ++itr) {
		cout << fixed;
		cout << setprecision(2);
		cout << "Product ID: " << to_string(itr->getProductID()) << " | "
			<< "Name: " << itr->getName() << " | "
			<< "Manufacturer: " << itr->getManufacturer() << " | "
			<< "Sale Price: " << itr->getPrice() << " | "
			<< "Quantity in stock: " << to_string(itr->getQuantity()) << endl;
		choices.push_back(to_string(itr->getProductID()));
	}

	cout << "******************************************************" << endl;
	cout << "1. Add product to invoice" << endl;
	cout << "2. Continue to payment details" << endl;
	cout << "3. Cancel new invoice" << endl;

	do {
		cout << "Please make a selection:" << endl;
		getline(cin, choice);

		if (choice == "1") {
			do {
				cout << "Select product ID to add to invoice, select 0 to exit:" << endl;
				getline(cin, choice2);
			} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

			if (choice != "0") {
				for (auto itr = allInventory.begin(); itr != allInventory.end(); ++itr) {
					if (to_string(itr->getProductID()) == choice2) {
						productTemp = *itr;
						allInventory.erase(itr); // product is added. don't add again
						break;
					}
				}

				do {
					if (quantity > productTemp.getQuantity()) {
						cout << "Quantity inputed exceeds amount in stock" << endl;
					}

					cout << "Input quantity to order:";
				} while (!(cin >> quantity) && (quantity > productTemp.getQuantity()));

				getline(cin, dummy); // catch cin error

				productTemp.setQuantityOrdered(quantity);
				
				productsOrdered.push_back(productTemp);
			}
		} else if (false) {
			// something else is bound to happen here and I'm not excited to write the code
		}

	} while (choice != "2" && choice != "3");

	cout << endl;

	if (choice == "3") {
		return BusinessLayer::Invoice();
	}

	choices.clear();

	cout << "*******************Invoice Creation*******************" << endl;

	do {
		cout << "Please input invoice number:" << endl;
	} while (!(cin >> invoiceNum));
	getline(cin, dummy);

	do {
		cout << "Please input interest rate percentage:" << endl;
	} while (!(cin >> interestRate));
	interestRate = interestRate / 100;
	getline(cin, dummy);

	do {
		cout << "Please input discount rate percentage:" << endl;
	} while (!(cin >> discountRate));
	discountRate = discountRate / 100;
	getline(cin, dummy);

	do {
		cout << "Would the customer like delivery? (y)/(n)" << endl;
		getline(cin, choice);
	} while (choice != "y" && choice != "n");

	if (choice == "y") {
		cout << "Please input Shipping Address:" << endl;
		std::getline(cin, shipto);

		do {
			cout << "Please input Delivery Charge:" << endl;
		} while (!(cin >> deliveryCharge));
		getline(cin, dummy);
	}

	cout << "Please input billing address:" << endl;
	getline(cin, billto);

	cout << endl;

	cout << "****************Review Invoice Details****************" << endl;
	cout << "Products Ordered:" << endl;

	for (auto itr = productsOrdered.begin(); itr != productsOrdered.end(); ++itr) {
		cout << fixed;
		cout << setprecision(2);
		cout << "Product ID: " << to_string(itr->getProductID()) << " | "
			<< "Name: " << itr->getName() << " | "
			<< "Price each: " << itr->getPrice() << " | "
			<< "Quantity ordered: " << to_string(itr->getQuantityOrdered()) << " | "
			<< "Price: " << (itr->getPrice() * itr->getQuantityOrdered()) << endl;
		totalAmount = totalAmount + (itr->getPrice() * itr->getQuantityOrdered());
	}

	cout << "Subtotal: " << totalAmount << endl;
	cout << "Tax: " << (totalAmount * 0.0) << endl; // F*** I fogot about this
	cout << "Delivery Charge: " << deliveryCharge << endl;

	totalAmount = totalAmount + (totalAmount * 0.0) + deliveryCharge;

	cout << "TOTAL: " << totalAmount << endl;
	cout << "Sales Representative ID:" << to_string(salesRepID) << endl;
	cout << "Billing Address: " << billto << endl;
	cout << "Shipping Address: " << shipto << endl;
	cout << "Interest Rate: " << (interestRate * 100) << endl;
	cout << "Discount Rate: " << (discountRate * 100) << endl;
	cout << "Invoice Number: " << to_string(invoiceNum) << endl;

	cout << "******************************************************" << endl;
	
	cout << "1. Confirm invoice creation" << endl;
	cout << "2. Cancel invoice creation" << endl;

	do {
		cout << "Please make a selection:" << endl;
		getline(cin, choice);
	} while (choice != "1" && choice != "2");

	if (choice == "2") {
		return BusinessLayer::Invoice();
	}

	 BusinessLayer::Invoice newInvoice( 
		 productsOrdered,
		 invoiceNum,
		 0,
		 interestRate,
		 discountRate,
		 totalAmount,
		 deliveryCharge,
		 false,
		 billto, // bill to
		 shipto, // ship to
		 "", // order Date... Leave this one to the control layer
		 0.0,
		 "", // close date... control layer
		 salesRepID, // sales rep id... needs fixing by control layer... will do
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
