// Invoice_db.cpp
#ifndef INVOICE_DB_H
#include "Invoice_db.h"
#endif

using namespace DatabaseLayer;

Invoice_db::Invoice_db()
{}

std::vector<BusinessLayer::Invoice> Invoice_db::getOInvoices() {
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	std::vector<Invoice> oinvoices;

	query << "SELECT oi.[PONumber], i.[totalAmount], i.[orderDate], oi.[amountPaid] ";
	query << "FROM dbo.OpenInvoices oi ";
	query << "JOIN dbo.Invoices i ";
	query << "ON oi.PONumber = i.PONumber ";
	query << "ORDER BY i.[orderDate] DESC";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		oinvoices.push_back(
			BusinessLayer::Invoice(
				std::vector<BusinessLayer::Product>(), // products
				0, // invoice number
				std::stoi(contents[0]), // PO number
				0.0f, // interest rate
				0.0f, // discount rate
				std::stod(contents[1]), // total Amount
				0.0, // delivery Charge
				(bool)0, // discount applied
				"", // bill To
				"", // ship to
				contents[2], // order date
				std::stod(contents[3]), // amount paid
				"", // close date
				0, // salesperson ID
				0 // interest applied
			)
		);
	}

	return oinvoices;
}

BusinessLayer::Invoice Invoice_db::getOInvoiceDetails(BusinessLayer::Invoice openInvoice) {
	if (openInvoice.getPONumber() != 0) {
		std::vector<std::vector<std::string>> temp;
		std::vector<std::vector<std::string>> temp2;
		std::ostringstream query;
		std::ostringstream query2;
		std::vector<BusinessLayer::Product> products;
		BusinessLayer::Invoice updatedOInvoice;

		query << "SELECT oi.PONumber, i.invoiceNum, i.interestRate, i.discountRate, i.totalAmount, ";
		query << "i.orderDate, i.deliveryCharge, i.interestApplied, i.discountApplied, i.salesRep, oi.billTo, oi.shipTo, oi.amountPaid ";
		query << "FROM dbo.OpenInvoices oi ";
		query << "JOIN dbo.Invoices i ";
		query << "ON oi.PONumber = i.PONumber ";
		query << "WHERE oi.PONumber = " + std::to_string(openInvoice.getPONumber());

		query2 << "SELECT od.[productID], od.[quantityOrdered], pd.[productName], ";
		query2 << "pd.[manufacturer], pd.[description], pd.[MSRP], pd.[cost] ";
		query2 << "FROM dbo.OrderDetails od ";
		query2 << "JOIN dbo.ProductDetails pd ";
		query2 << "ON od.productID = pd.productID ";
		query2 << "WHERE PONumber = " + std::to_string(openInvoice.getPONumber());

		temp = dbHelper->sqlexec(query.str());
		temp2 = dbHelper->sqlexec(query2.str());

		for (auto itr = temp2.begin(); itr != temp2.end(); ++itr) {
			auto contents = *itr;
			products.push_back(
				BusinessLayer::Product(
					contents[2],
					std::stoi(contents[0]),
					std::stod(contents[5]),
					std::stod(contents[6]),
					0,
					contents[3],
					std::stoi(contents[1]),
					contents[4]
				)
			);
		}

		if (temp.size() == 0) {
			return BusinessLayer::Invoice();
		}

		updatedOInvoice = BusinessLayer::Invoice(
			products, // products ordered
			std::stoi(temp[0][1]), // invoice num
			openInvoice.getPONumber(), // po num
			std::stof(temp[0][2]), // interest rate
			std::stof(temp[0][3]), // discount rate
			std::stod(temp[0][4]), // total amount // NEEDS REVIEW
			std::stod(temp[0][6]), // delivery charge
			(bool)std::stoi(temp[0][8]), // discount applied
			temp[0][10], // bill to
			temp[0][11], // ship to
			temp[0][5], // order date
			std::stod(temp[0][12]), // amount paid
			"", // close date
			std::stoi(temp[0][9]), // sales rep ID
			std::stoi(temp[0][7]) // interest applied
		);

		return updatedOInvoice;
	}
	else {
		return BusinessLayer::Invoice();
	}
}

void Invoice_db::payInvoice(BusinessLayer::Invoice openInvoice) {
	if (openInvoice.getPONumber() != 0) {
		std::vector<std::vector<std::string>> temp;
		std::ostringstream query;
		std::ostringstream query2;
		std::ostringstream query3;
		std::ostringstream query4;
		double amountPaid;
		double totalAmount;

		query << "UPDATE dbo.OpenInvoices ";
		query << "SET [amountPaid] = [amountPaid] + " + std::to_string(openInvoice.getAmountPaid()) + " ";
		query << "WHERE [PONumber] = " + std::to_string(openInvoice.getPONumber());

		dbHelper->sqlexec(query.str());

		query2 << "SELECT oi.amountPaid, i.totalAmount ";
		query2 << "FROM dbo.OpenInvoices oi ";
		query2 << "JOIN dbo.Invoices i ";
		query2 << "ON oi.PONumber = i.PONumber ";
		query2 << "WHERE i.PONumber = " + std::to_string(openInvoice.getPONumber());

		temp = dbHelper->sqlexec(query2.str());

		amountPaid = std::stod(temp[0][0]);
		totalAmount = std::stod(temp[0][1]);

		if (!(amountPaid < totalAmount)) {
			query3 << "DELETE FROM dbo.OpenInvoices ";
			query3 << "WHERE PONumber = " << std::to_string(openInvoice.getPONumber());

			dbHelper->sqlexec(query3.str());

			query4 << "INSERT INTO dbo.ClosedInvoices ";
			query4 << "([PONumber], [closeDate]) ";
			query4 << "VALUES (";
			query4 << std::to_string(openInvoice.getPONumber()) + ", '";
			query4 << dbHelper->getCurrentDate() + "')";

			dbHelper->sqlexec(query4.str());
		}
	}
}

std::vector<BusinessLayer::Invoice> Invoice_db::getCInvoices() {
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	std::vector<Invoice> inList;

	query << "SELECT ci.PONumber, ci.closeDate, i.totalAmount ";
	query << "FROM dbo.ClosedInvoices ci ";
	query << "JOIN dbo.Invoices i ";
	query << "ON ci.PONumber = i.PONumber ";
	query << "ORDER BY i.totalAmount ASC";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); itr++) {
		auto contents = *itr;
		inList.push_back(
			BusinessLayer::Invoice(
				std::vector<BusinessLayer::Product>(),
				0, //Invoice Number
				std::stoi(contents[0]), //PONumber
				0.0f, //InterestRate
				0.0f, // DiscountRate
				std::stod(contents[2]), //Total Amount 
				0.0, //Delivery Charge
				false, //Discount Applied
				"", // Bill To
				"", // ShipTo
				"", //Orderdate
				0.0, // amount paid
				contents[1], // close date
				0, // salesRep ID
				0 // interest applied
			)
		);
	}

	return inList;
}

BusinessLayer::Invoice Invoice_db::getCInvoiceDetails(BusinessLayer::Invoice closedInvoice) {
	if (closedInvoice.getPONumber() != 0) {
		std::vector<std::vector<std::string>> temp;
		std::vector<std::vector<std::string>> temp2;
		std::ostringstream query;
		std::ostringstream query2;
		std::vector<BusinessLayer::Product> products;
		BusinessLayer::Invoice updatedCInvoice;

		query << "SELECT ci.[PONumber], ci.[closeDate], i.[invoiceNum], i.[interestRate], ";
		query << "i.[discountRate], i.[totalAmount], i.[orderDate], i.[deliveryCharge], i.[interestApplied], ";
		query << "i.[discountApplied], i.[salesRep] ";
		query << "FROM dbo.ClosedInvoices ci ";
		query << "JOIN dbo.Invoices i ";
		query << "ON ci.PONumber = i.PONumber ";
		query << "WHERE ci.PONumber = " + std::to_string(closedInvoice.getPONumber());

		query2 << "SELECT od.[productID], od.[quantityOrdered], pd.[productName], ";
		query2 << "pd.[manufacturer], pd.[description], pd.[MSRP], pd.[cost] ";
		query2 << "FROM dbo.OrderDetails od ";
		query2 << "JOIN dbo.ProductDetails pd ";
		query2 << "ON od.productID = pd.productID ";
		query2 << "WHERE PONumber = " + std::to_string(closedInvoice.getPONumber());

		temp = dbHelper->sqlexec(query.str());
		temp2 = dbHelper->sqlexec(query2.str());

		for (auto itr = temp2.begin(); itr != temp2.end(); ++itr) {
			auto contents = *itr;
			products.push_back(
				BusinessLayer::Product(
					contents[2],
					std::stoi(contents[0]),
					std::stod(contents[5]),
					std::stod(contents[6]),
					0,
					contents[3],
					std::stoi(contents[1]),
					contents[4]
				)
			);
		}

		updatedCInvoice = BusinessLayer::Invoice(
			products, // products ordered
			std::stoi(temp[0][2]), // invoice num
			closedInvoice.getPONumber(), // po num
			std::stof(temp[0][3]), // interest rate
			std::stof(temp[0][4]), // discount rate
			std::stod(temp[0][5]), // total amount // NEEDS REVIEW
			std::stoi(temp[0][7]), // delivery charge
			(bool)std::stoi(temp[0][9]), // discount applied
			"", // bill to
			"", // ship to
			temp[0][6], // order date
			0.0, // amount paid
			temp[0][1], // close date
			std::stoi(temp[0][10]), // sales rep ID
			std::stoi(temp[0][9]) // interest applied
		);

		return updatedCInvoice;
	}
	else {
		return BusinessLayer::Invoice();
	}
}

void Invoice_db::addOInvoice(BusinessLayer::Invoice openInvoice) { // FIXME
	if (openInvoice.getSalesRepID() != 0) {
		std::vector<BusinessLayer::Product> productsOrdered = openInvoice.getProductsOrdered();
		std::vector<std::vector<std::string>> temp;
		std::ostringstream query;
		std::ostringstream query2;
		int PONumber = 0, quantity, diff;

		query << "SELECT MAX([PONumber]) ";
		query << "FROM dbo.Invoices";

		temp = dbHelper->sqlexec(query.str());

		if (temp.size() > 0) {
			PONumber = std::stoi(temp[0][0]);
		}

		query.str("");
		query.clear();

		query << "INSERT INTO dbo.Invoices ";
		query << "([PONumber], [invoiceNum], [interestRate], [discountRate], [totalAmount], ";
		query << "[orderDate] , [deliveryCharge], [interestApplied], [discountApplied], [salesRep]) ";
		query << "VALUES (";
		query << std::to_string(PONumber + 1) + ", ";
		query << std::to_string(openInvoice.getInvoiceNumber()) + ", ";
		query << std::to_string(openInvoice.getInterestRate()) + ", ";
		query << std::to_string(openInvoice.getDiscountRate()) + ", ";
		query << std::to_string(openInvoice.getTotalAmount()) + ", '";
		query << dbHelper->getCurrentDate() + "', ";
		query << std::to_string(openInvoice.getDeliveryCharge()) + ", ";
		query << std::to_string(openInvoice.getInterestApplied()) + ", ";
		query << std::to_string((int)openInvoice.getDiscountApplied()) + ", ";
		query << std::to_string(openInvoice.getSalesRepID()) + ")";

		query2 << "INSERT INTO dbo.OpenInvoices ";
		query2 << "([PONumber], [billTo], [shipTo], [amountPaid]) ";
		query2 << "VALUES (";
		query2 << std::to_string(PONumber + 1) + ", '";
		query2 << openInvoice.getBillTo() + "', '";
		query2 << openInvoice.getShipTo() + "', ";
		query2 << std::to_string(openInvoice.getAmountPaid()) + ")";

		dbHelper->sqlexec(query.str());
		dbHelper->sqlexec(query2.str());

		query.str("");
		query2.str("");
		query.clear();
		query2.clear();

		for (auto itr = productsOrdered.begin(); itr != productsOrdered.end(); ++itr) {
			query << "INSERT INTO dbo.OrderDetails ";
			query << "([PONumber], [productID], [quantityOrdered]) ";
			query << "VALUES (";
			query << std::to_string(PONumber + 1) + ", ";
			query << std::to_string(itr->getProductID()) + ", ";
			query << std::to_string(itr->getQuantityOrdered()) + ")";

			query2 << "SELECT [warehouseID], [quantityInStock] ";
			query2 << "FROM dbo.Products ";
			query2 << "WHERE [productID] = " + std::to_string(itr->getProductID());

			dbHelper->sqlexec(query.str());
			temp = dbHelper->sqlexec(query2.str());

			query.str("");
			query2.str("");
			query.clear();
			query2.clear();

			quantity = itr->getQuantityOrdered();

			for (auto itr2 = temp.begin(); itr2 != temp.end() && quantity != 0; ++itr2) {
				auto contents = *itr2;

				query.str("");
				query.clear();

				if (std::stoi(contents[1]) > quantity) {
					diff = std::stoi(contents[1]) - quantity;
					quantity = 0;
				}
				else {
					quantity = quantity - std::stoi(contents[1]);
					diff = 0;
				}

				query << "UPDATE dbo.Products ";
				query << "SET quantityInStock = " + std::to_string(diff) + " ";
				query << "WHERE warehouseID = " + contents[0] + " ";
				query << "AND productID = " + std::to_string(itr->getProductID());

				dbHelper->sqlexec(query.str());
			}
		}
	}
}

void Invoice_db::test()	{}