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
			int idSS = 7 - to_string(itr->getProductID()).size();
			int nameSS = 30 - itr->getName().size();
			cout << fixed;
			cout << setprecision(2);
			cout << "ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
				<< "Name: " << itr->getName() << setw(nameSS) << " | "
				<< "Price Each: $" << itr->getPrice() << " | "
				<< "Quantity Ordered: " << to_string(itr->getQuantityOrdered()) << endl;
		}

		cout << "******************************************************" << endl;
	}
	cout << endl;
}

BusinessLayer::Invoice Invoice_ui::PayInvoice(std::vector<BusinessLayer::Invoice> oinvoices) {
	BusinessLayer::Invoice payedInvoice;
	vector<string> choices;
	string choice;
	double payment;

	for (auto itr = oinvoices.begin(); itr != oinvoices.end(); ++itr) {
		choices.push_back(to_string(itr->getPONumber()));
	}
	do {
		cout << "Please select an invoice PO Number, select 0 to exit:" << endl;
		getline(cin, choice);
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input payment amount: " << endl;
		cin >> payment;
	} while (cin.fail());
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
		int idSS = 7 - to_string(itr->getEmployeeID()).size();
		cout << "EmployeeID: " << to_string(itr->getEmployeeID()) << setw(idSS) << " | "
			<< "Name: " << itr->getEmployeeName() << endl;
		choices.push_back(to_string(itr->getEmployeeID()));
	}

	cout << "******************************************************" << endl;

	do {
		cout << "Please select employeeID which made the sale, select 0 to exit" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	if (choice == "0") {
		return BusinessLayer::Invoice();
	}

	salesRepID = stoi(choice);

	do {
		choices.clear();

		cout << endl;
		cout << "***********************Products***********************" << endl;

		for (auto itr = allInventory.begin(); itr != allInventory.end(); ++itr) {
			int idSS = 7 - to_string(itr->getProductID()).size();
			int nameSS = 30 - itr->getName().size();
			int manuSS = 20 - itr->getManufacturer().size();
			int priceSS = 7 - to_string(itr->getPrice()).size();
			cout << fixed;
			cout << setprecision(2);
			cout << "Product ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
				<< "Name: " << itr->getName() << setw(nameSS) << " | "
				<< "Manufacturer: " << itr->getManufacturer() << setw(manuSS) << " | "
				<< "Sale Price: " << itr->getPrice() << setw(priceSS) << " | "
				<< "Quantity in stock: " << to_string(itr->getQuantity()) << endl;
			choices.push_back(to_string(itr->getProductID()));
		}

		cout << "******************************************************" << endl;
		cout << "1. Add product to invoice" << endl;
		cout << "2. Continue to payment details" << endl;
		cout << "3. Cancel new invoice" << endl;
		cout << "Please make a selection:" << endl;
		getline(cin, choice);

		if (choice == "1") {
			do {
				cout << "Select product ID to add to invoice, select 0 to exit:" << endl;
				getline(cin, choice2);
			} while (none_of(choices.begin(), choices.end(), [choice2](string s) { return s == choice2; }) && choice2 != "0");

			if (choice2 != "0") {
				for (auto itr = allInventory.begin(); itr != allInventory.end(); ++itr) {
					if (to_string(itr->getProductID()) == choice2) {
						productTemp = *itr;
						allInventory.erase(itr); // product is added. don't add again
						break;
					}
				}

				do {
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} else if (quantity > productTemp.getQuantity()) {
						cout << "Quantity inputed exceeds amount in stock" << endl;
					}
					cout << "Input quantity to order:" << endl;
					cin >> quantity;
				} while (cin.fail() || (quantity > productTemp.getQuantity()));
				getline(cin, dummy); // catch cin error

				productTemp.setQuantityOrdered(quantity);
				
				productsOrdered.push_back(productTemp);
			}
		} else if (false) {
			// something else is bound to happen here and I'm not excited to write the code
		}

	} while ((choice != "2" || productsOrdered.size() == 0) && choice != "3");

	cout << endl;

	if (choice == "3") {
		return BusinessLayer::Invoice();
	}

	choices.clear();

	cout << "*******************Invoice Creation*******************" << endl;

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input invoice number:" << endl;
		cin >> invoiceNum;
	} while (cin.fail());
	getline(cin, dummy);

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input interest rate percentage:" << endl;
		cin >> interestRate;
	} while (cin.fail());
	interestRate = interestRate / 100;
	getline(cin, dummy);

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input discount rate percentage:" << endl;
		cin >> discountRate;
	} while (cin.fail());
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
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please input Delivery Charge:" << endl;
			cin >> deliveryCharge;
		} while (cin.fail());
		getline(cin, dummy);
	}

	cout << "Please input billing address:" << endl;
	getline(cin, billto);

	cout << endl;

	cout << "****************Review Invoice Details****************" << endl;
	cout << "Products Ordered:" << endl;

	for (auto itr = productsOrdered.begin(); itr != productsOrdered.end(); ++itr) {
		int idSS = 7 - to_string(itr->getProductID()).size();
		int nameSS = 30 - itr->getName().size();
		int quantitySS = 9 - to_string(itr->getQuantityOrdered()).size();
		int priceEachSS = 9 - to_string(itr->getPrice()).size();
		cout << fixed;
		cout << setprecision(2);
		cout << "Product ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
			<< "Name: " << itr->getName() << setw(nameSS) << " | "
			<< "Price each: " << itr->getPrice() << setw(priceEachSS) << " | "
			<< "Quantity ordered: " << to_string(itr->getQuantityOrdered()) << setw(quantitySS) << " | "
			<< "Price: " << (itr->getPrice() * itr->getQuantityOrdered()) << endl;
		totalAmount = totalAmount + (itr->getPrice() * itr->getQuantityOrdered());
	}

	cout << "Subtotal: " << totalAmount << endl;
	cout << "Tax: " << (totalAmount * 0.0) << endl; // I fogot about this
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
		 0, // po number, database layer
		 interestRate,
		 discountRate,
		 totalAmount,
		 deliveryCharge,
		 false,
		 billto,
		 shipto,
		 "", // order Date... Leave this one to the control layer
		 0.0,
		 "", // close date... control layer
		 salesRepID,
		 0 // interest applied, database layer
	 );

	 return newInvoice;
}

string Invoice_ui::CInvoices(std::vector<BusinessLayer::Invoice> cinvoices) {
	string choice;

	cout << "******************************************************" << endl;
	cout << "*******************Closed Invoices********************" << endl;

	for (auto itr = cinvoices.begin(); itr != cinvoices.end(); ++itr) {
		cout << "PO Number: " << to_string(itr->getPONumber()) << " | "
			<< "Close date: " << itr->getCloseDate() << endl;
	}

	cout << "******************************************************" << endl;
	
	cout << "1. View Close Invoice Details" << endl;
	cout << "2. Back to Main Menu" << endl;

	do {
		cout << "Please make a selection:" << endl;
		getline(cin, choice);
	} while (choice != "1" && choice != "2");
	
	cout << endl;

	return choice;
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
