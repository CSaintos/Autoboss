// Invoice_db.cpp
#ifndef INVOICE_DB_H
#include "Invoice_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;
using namespace std;

Invoice_db::Invoice_db()
{}

std::vector<Invoice> Invoice_db::getOInvoices() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM OpenInvoices");
	std::vector<Invoice> inList;

	//*itr = PONumber, billTo, shipTo, amountPaid
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		//inList.push_back(<InsertInvoiceConstructorHere>);
		inList.push_back(Invoice(std::vector<Product>(),
			0, //Invoice Number
			std::stoi(contents[0]), //PONumber
			2.0, //InterestRate
			500, //Total Amount 
			// HELP ME THE FUCK OUT HERE = Create a "double amountPaid" = contents[3]
			0, //Delivery Charge
			0, //Discount Applied
			contents[1], //Bill To
			contents[2], //String shipTo
			"2020-12-25")); //Orderdate
			//Invoice(vector<Product> productsOrdered, int invoiceNum, int poNum, float interestRate,
//	double totalAmount, double deliveryCharge, bool discountApplied, string billTo, string ShipTo,
//	string orderDate)
	}
	openInvoices = inList;
	return openInvoices;
}

std::vector<Invoice> Invoice_db::getCInvoices()	{
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM ClosedInvoices");
	std::vector<Invoice> inList;

	//*itr = PONumber ; closeDate
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		//inList.push_back(<InsertInvoiceConstructorHere>);
	}
	closedInvoices = inList;
	return closedInvoices;
}

void Invoice_db::payInvoice(Invoice inv, int payment) {
	/*pseudo code gang cause invoice.cpp/h isn't complete lol
	Tested and done with SQL Query, it works; again I'd like to reiterate possibly moving from vector<vector<string>> to void; or we could just make
	a new one that's pretty much copy/paste of SQLexec for none-data retrieval options like updates/removing/adding? I 
	think that's a better option than the one I proposed in Warehouses*/
	//int PO = inv.getPONumber; 
	//helper.sqlexec("UPDATE OpenInvoices SET amountPaid = (amountPaid + " + std::to_string(payment) + ") WHERE PONumber = " + std::to_string(PO) + ";");
}

void Invoice_db::createInvoice(Invoice inv) {
	/*PSEUDOCODE GANG*/
	//helper.sqlexec("INSERT INTO Invoices(PONumber, invoiceNum, interestRate, discountRate, totalAmount, orderDate, deliveryCharge, interestApplied, discountApplied, salesRep) VALUES(" 
	//	+ std::to_string(inv.getPoNum) + ", " + std::to_string(inv.getinvoicenum) + ", " + std::to_string(getintrate)
	//	+ ", " + std::to_string(getdiscrate) + ", " + std::to_string(gettotalamt) + ", " + inv.getorderdate + ", " + std::to_string(getdelivcharge) + ", "
	//	+ std::to_string(getIntApplied) + ", " + std::to_string(discApplied) + ", " + std::to_string(salesRep) + ");");

	//helper.sqlexec("INSERT INTO OpenInvoices(PONumber, billTo, shipTo, amountPaid) VALUES(" + std::to_string() + ", '" + getBillTo + "', '" + shipTo + "', " + std::to_string(amountpaid) + ");");

}
//void addOInvoice(/*invoice to be added*/) {} //adds a new invoice
//vector getCInvoices() {} //return all closed invoices
//vector getOInvoices() {} //return all open invoices vector<invoice>

void Invoice_db::test()	{

}