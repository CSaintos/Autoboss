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
		inList.push_back(
			Invoice(
				std::vector<Product>(),
				0, //Invoice Number
				std::stoi(contents[0]), //PONumber
				0.0, // InterestRate
				0.0, // discount rate
				0.0, // Total Amount 
				0.0, // Delivery Charge
				(bool)0, // Discount Applied
				contents[1], // Bill To
				contents[2], // shipTo
				"", //Orderdate
				std::stod(contents[3]), // amount paid
				"", // close date
				0, // sales rep id
				0 // interest applied
			)
		);
	}
	return inList;
}

std::vector<Invoice> Invoice_db::getCInvoices()	{
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM ClosedInvoices");
	std::vector<Invoice> inList;

	//*itr = PONumber ; closeDate
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents= *itr1;
		inList.push_back(
			Invoice(
				std::vector<Product>(),
				0, //Invoice Number
				std::stoi(contents[0]), //PONumber
				0.0, // InterestRate
				0.0, // discount rate
				0.0, // Total Amount 
				0.0, // Delivery Charge
				(bool)0, // Discount Applied
				"", // Bill To
				"", // shipTo
				"", // Orderdate
				0.0, // amount paid
				"", // close date
				0, // sales rep id
				0 // interest applied
			)
		);
	}

	return inList;
}

void Invoice_db::payInvoice(Invoice inv, int payment) {
	std::ostringstream query;
	query << "UPDATE OpenInvoices SET amountPaid = (amountPaid + ";
	query << std::to_string(inv.getAmountPaid());
	query << ") WHERE PONumber = ";
	query << std::to_string(inv.getPONumber()) << ";";
	helper.sqlexec(query.str());
}

void Invoice_db::createInvoice(Invoice inv) {
	std::ostringstream query;
	query << "INSERT INTO Invoices(PONumber, invoiceNum, interestRate, discountRate, totalAmount, orderDate, deliveryCharge, interestApplied, discountApplied, salesRep) "; 
	query << "VALUES(";
	query << std::to_string(inv.getPONumber()) + ", ";
	query << std::to_string(inv.getInvoiceNumber()) + ", ";
	query << std::to_string(inv.getInterestRate()) + ", ";
	query << std::to_string(inv.getDiscountRate()) + ", ";
	query << std::to_string(inv.getTotalAmount()) + ", ";
	query << inv.getOrderDate() + ", ";
	query << std::to_string(inv.getDeliveryCharge()) + ", ";
	query << std::to_string(inv.getInterestApplied()) + ", " ;
	query << std::to_string(inv.getDiscountApplied()) + ")";//+ ", ";
	//query << std::to_string(salesRep) + ")"); //needs a sales representative
	helper.sqlexec(query.str());
}

void Invoice_db::test()	{

}