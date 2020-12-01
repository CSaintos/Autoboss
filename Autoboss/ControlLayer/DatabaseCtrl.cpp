// DatabaseCtr.cpp
#ifndef DATABASECTRL_H
#include "DatabaseCtrl.h"
#endif

using namespace DatabaseLayer;
using namespace ControlLayer;

DatabaseCtrl::DatabaseCtrl() :
	dbHelper(std::make_unique<DBHelper>()),
	invoiceDB(std::make_unique<Invoice_db>()),
	productDB(std::make_unique<Product_db>()),
	salespersonDB(std::make_unique<Salesperson_db>()),
	warehouseDB(std::make_unique<Warehouse_db>())
{}

DatabaseCtrl* DatabaseCtrl::databaseCtrl = nullptr;

DatabaseCtrl* DatabaseCtrl::GetInstance() {
	if (databaseCtrl == nullptr) {
		databaseCtrl = new DatabaseCtrl();
	}
	return databaseCtrl;
}

void DatabaseCtrl::openDB() {
	dbHelper->openDB();
}

void DatabaseCtrl::closeDB() {
	dbHelper->closeDB();
}

void DatabaseCtrl::test() {
	dbHelper->test();
	invoiceDB->test();
	productDB->test();
	salespersonDB->test();
	warehouseDB->test();
}

void DatabaseCtrl::setCurrentDate(std::string date) {
	std::ostringstream query;
	query << "UPDATE dbo.CurrentDate ";
	query << "SET [Date] = " << "'" + date + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::string DatabaseCtrl::getCurrentDate() {
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	
	query << "SELECT [Date] ";
	query << "FROM dbo.CurrentDate ";
	query << "WHERE [Id] = 1";

	temp = dbHelper->sqlexec(query.str());

	return temp[0][0];
}

std::string DatabaseCtrl::getPassword() {
	std::vector<std::vector<std::string>> vectorString;
	vectorString = dbHelper->sqlexec("SELECT [Password] FROM dbo.Credentials WHERE [Id] = 1");
	return vectorString[0][0];
}

void DatabaseCtrl::setPassword(std::string password) {
	std::ostringstream query;
	query << "UPDATE dbo.Credentials ";
	query << "SET [Password] = " << "'" + password + "'" << " ";
	query << "WHERE [Id] = 1";
	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Warehouse> DatabaseCtrl::getWarehouses() { // TODO KINDA
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM Warehouses");
	std::vector<BusinessLayer::Warehouse> warehouseList;
	std::vector<Product> inv;
	
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		warehouseList.push_back(Warehouse(inv, std::stoi(contents[0]), contents[2], contents[1], contents[3]));
	}

	return warehouseList;
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getInventory(BusinessLayer::Warehouse warehouse) { // TODO KINDA
	std::vector<BusinessLayer::Product> products;
	std::vector<std::vector<std::string>> inventory;
	std::ostringstream query;

	query << "SELECT p.productID, pd.productName, p.quantityInStock ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.productID = pd.productID ";
	query << "WHERE p.warehouseID = " + std::to_string(warehouse.getWarehouseID());
	inventory = dbHelper->sqlexec(query.str());

	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				std::stoi(contents[2]),
				"",
				""
			)
		);
	}

	return products;
}

void DatabaseCtrl::stockInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) { // TODO KINDA
	std::ostringstream query;

	query << "UPDATE dbo.Products ";
	query << "SET [quantityInStock] = [quantityInStock] + " + std::to_string(product.getQuantity()) + " ";
	query << "WHERE productID = " + std::to_string(product.getProductID()) + " AND ";
	query << "warehouseID = " + std::to_string(warehouse.getWarehouseID());

	dbHelper->sqlexec(query.str());
}

void DatabaseCtrl::addInventory(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) { // TODO
	std::ostringstream query;

	query << "INSERT INTO dbo.Products ";
	query << "([warehouseID], [productID], [quantityInStock]) ";
	query << "VALUES (";
	query << std::to_string(warehouse.getWarehouseID()) + ", ";
	query << std::to_string(product.getProductID()) + ", ";
	query << std::to_string(product.getQuantity()) + ")";

	dbHelper->sqlexec(query.str());
}

void DatabaseCtrl::addWarehouse(BusinessLayer::Warehouse warehouse) { // TODO KINDA
	std::ostringstream query;

	query << "INSERT INTO ";
	query << "dbo.Warehouses([warehouseID], [address], [email], [phoneNumber]) ";
	query << "VALUES (";
	query << std::to_string(warehouse.getWarehouseID()) + ", '";
	query << warehouse.getAddress() + "', '";
	query << warehouse.getEmail() + "', '";
	query << warehouse.getPhoneNumber() + "')";

	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Salesperson> DatabaseCtrl::getSalespeople() { // TODO KINDA
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM dbo.SalesPeople");
	std::vector<std::vector<std::string>>::iterator itr;
	std::vector<Salesperson> empList;

	//*itr = EmployeeID, commission rate, name, total commission, total sales amount
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		empList.push_back(Salesperson(std::vector<Invoice>(), // sold list
			std::stoi(contents[0]), // employee ID
			std::stof(contents[1]), // commission rate
			contents[2], // employee name
			std::stod(contents[3]), // total commission
			std::stod(contents[4]))); // total sales
	}

	return empList;
}

void DatabaseCtrl::setCommissionRate(BusinessLayer::Salesperson salesperson) { // TODO KINDA
	std::ostringstream query;

	query << "UPDATE SalesPeople "; 
	query << "SET commissionRate = ";
	query << std::to_string(salesperson.getCommisionRate());
	query << " WHERE employeeID = ";
	query << std::to_string(salesperson.getEmployeeID());

	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getProducts() { // TODO KINDA
	std::vector<std::vector<std::string>> temp;
	std::vector<BusinessLayer::Product> products;
	std::ostringstream query;

	query << "SELECT [productID], [productName] ";
	query << "FROM dbo.ProductDetails";

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				0,
				"",
				""
			)
		);
	}

	return products;
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getOtherProducts(BusinessLayer::Warehouse warehouse) { // TODO KINDA
	std::vector<std::vector<std::string>> temp;
	std::vector<BusinessLayer::Product> products;
	std::ostringstream query;

	query << "SELECT pd2.[productID], [productName] ";
	query << "FROM dbo.ProductDetails pd2 ";
	query << "EXCEPT ";
	query << "SELECT p.[productID], pd.[productName] ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.[productID] = pd.[productID] ";
	query << "WHERE p.[warehouseID] = " + std::to_string(warehouse.getWarehouseID());

	temp = dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		products.push_back(
			BusinessLayer::Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				0,
				"",
				""
			)
		);
	}

	return products;
}

BusinessLayer::Product DatabaseCtrl::getProductDetails(BusinessLayer::Product product) { // TODO
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;
	BusinessLayer::Product updatedProduct;

	query << "SELECT * ";
	query << "FROM dbo.ProductDetails ";
	query << "WHERE [productID] = " + std::to_string(product.getProductID());

	temp = dbHelper->sqlexec(query.str());

	updatedProduct = BusinessLayer::Product(
		temp[0][1],
		std::stoi(temp[0][0]),
		std::stoi(temp[0][4]),
		std::stoi(temp[0][5]),
		0,
		temp[0][2],
		temp[0][3]
	);

	return updatedProduct;
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getLowStock() { // TODO KINDA NEEDS REVIEW
	std::vector<BusinessLayer::Product> lowStock;
	std::vector<std::vector<std::string>> temp;
	std::ostringstream query;

	query << "SELECT p.productID, pd.productName, SUM(p.quantityInStock) ";
	query << "FROM dbo.Products p ";
	query << "JOIN dbo.ProductDetails pd ";
	query << "ON p.productID = pd.productID ";
	query << "GROUP BY p.productID, pd.productName ";
	query << "HAVING SUM(p.quantityInStock) < 5"; // FIXME

	dbHelper->sqlexec(query.str());

	for (auto itr = temp.begin(); itr != temp.end(); ++itr) {
		auto contents = *itr;
		lowStock.push_back(
			Product(
				contents[1],
				std::stoi(contents[0]),
				0.0,
				0.0,
				std::stoi(contents[2]),
				"",
				""
			)
		);
	}

	return lowStock;
}

void DatabaseCtrl::createProduct(BusinessLayer::Product product) { // TODO KINDA
	std::ostringstream query;

	query << "INSERT INTO dbo.ProductDetails (";
	query << "[productID], [productName], [manufacturer], ";
	query << "[description], [MSRP], [cost]) ";
	query << "VALUES (";
	query << std::to_string(product.getProductID()) + ", '";
	query << product.getName() + "', '";
	query << product.getManufacturer() + "', '";
	query << product.getDescription() + "', ";
	query << std::to_string(product.getPrice()) + ", ";
	query << std::to_string(product.getCost()) + ")";

	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getOInvoices() { // TODO KINDA NEEDS REVIEW
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM OpenInvoices");
	std::vector<Invoice> inList;

	//*itr = PONumber, billTo, shipTo, amountPaid
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		inList.push_back(
			Invoice(
				std::vector<Product>(), // products
				0, // invoice number
				std::stoi(contents[0]), // PO number
				0.0f, // interest rate
				0.0f, // discount rate
				0.0, // total Amount
				0.0, // delivery Charge
				(bool)0, // discount applied
				contents[1], // bill To
				contents[2], // ship to
				"", // order date
				std::stod(contents[3]), // amount paid
				"", // close date
				0, // salesperson ID
				0 // interest applied
			)
		);
	}

	return inList;
}

BusinessLayer::Invoice DatabaseCtrl::getOInvoiceDetails(BusinessLayer::Invoice openInvoice) { // TODO KINDA NEEDS REVIEW
	std::vector<std::vector<std::string>> temp;
	std::vector<std::vector<std::string>> temp2;
	std::ostringstream query;
	std::ostringstream query2;
	std::vector<BusinessLayer::Product> products;
	BusinessLayer::Invoice updatedOInvoice;

	query << "SELECT oi.PONumber, i.invoiceNum, i.interestRate, i.discountRate, i.totalAmount, ";
	query << "i.orderDate, i.deliveryCharge, i.interestApplied, i.discountApplied, i.salesRep, oi.shipTo, oi.amountPaid ";
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

	updatedOInvoice = BusinessLayer::Invoice(
		products, // products ordered
		std::stoi(temp[0][1]), // invoice num
		openInvoice.getPONumber(), // po num
		std::stof(temp[0][2]), // interest rate
		std::stof(temp[0][3]), // discount rate
		std::stod(temp[0][4]), // total amount // NEEDS REVIEW
		std::stoi(temp[0][6]), // delivery charge
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

void DatabaseCtrl::payInvoice(BusinessLayer::Invoice openInvoice) { // TODO KINDA NEEDS REVIEW
	std::ostringstream query;

	query << "UPDATE dbo.OpenInvoices ";
	query << "SET [amountPaid] = [amountPaid] + " + std::to_string(openInvoice.getAmountPaid()) + " ";
	query << "WHERE [PONumber] = " + std::to_string(openInvoice.getPONumber());

	dbHelper->sqlexec(query.str());
}

void DatabaseCtrl::updateProduct(BusinessLayer::Product product) { // TODO KINDA
	std::ostringstream query;

	query << "UPDATE dbo.ProductDetails ";
	query << "SET [productName] = '" + product.getName() + "', ";
	query << "[manufacturer] = '" + product.getManufacturer() + "', ";
	query << "[description] = '" + product.getDescription() + "', ";
	query << "[MSRP] = " + std::to_string(product.getPrice()) + ", ";
	query << "[cost] = " + std::to_string(product.getCost()) + " ";
	query << "WHERE [productID] = " + std::to_string(product.getProductID());

	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getCInvoices() { // TODO KINDA NEEDS REVIEW
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM ClosedInvoices");
	std::vector<Invoice> inList;

	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		inList.push_back(
			Invoice(
				std::vector<Product>(),
				0, //Invoice Number
				std::stoi(contents[0]), //PONumber
				0.0f, //InterestRate
				0.0f, // DiscountRate
				0.0, //Total Amount 
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

BusinessLayer::Invoice DatabaseCtrl::getCInvoiceDetails(BusinessLayer::Invoice closedInvoice) { // TODO KINDA NEEDS REVIEW
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

void DatabaseCtrl::addSalesperson(BusinessLayer::Salesperson salesperson) { // TODO KINDA
	std::ostringstream query;

	query << "INSERT INTO SalesPeople(employeeID, commissionRate, [name], totalCommission, totalSalesAmount) ";
	query << "VALUES(";
	query << std::to_string(salesperson.getEmployeeID()) + ", ";
	query << std::to_string(salesperson.getCommisionRate()) + ", '";
	query << salesperson.getEmployeeName() + "', ";
	query << std::to_string(salesperson.getTotalCommission()) + ", ";
	query << std::to_string(salesperson.getTotalSalesAmount()) + ")";

	dbHelper->sqlexec(query.str());
}

void DatabaseCtrl::addOInvoice(BusinessLayer::Invoice openInvoice) { // TODO KINDA NEEDS REVIEW
	std::ostringstream query;
	std::ostringstream query2;

	query << "INSERT INTO dbo.Invoices ";
	query << "([PONumber], [invoiceNum], [interestRate], [discountRate], [totalAmount], ";
	query << "[orderDate] , [deliveryCharge], [interestApplied], [discountApplied], [salesRep]) ";
	query << "VALUES (";
	query << std::to_string(openInvoice.getPONumber()) + ", ";
	query << std::to_string(openInvoice.getInvoiceNumber()) + ", ";
	query << std::to_string(openInvoice.getInterestRate()) + ", ";
	query << std::to_string(openInvoice.getDiscountRate()) + ", ";
	query << std::to_string(openInvoice.getTotalAmount()) + ", '"; // This needs to be calculated somewhere. not here
	query << getCurrentDate() + "', "; // This needs to be updated somewhere, not here.
	query << std::to_string(openInvoice.getDeliveryCharge()) + ", ";
	query << std::to_string(openInvoice.getInterestApplied()) + ", ";
	query << std::to_string((int)openInvoice.getDiscountApplied()) + ", ";
	query << std::to_string(openInvoice.getSalesRepID()) + ")";

	query2 << "INSERT INTO dbo.OpenInvoices ";
	query2 << "([PONumber], [billTo], [shipTo], [amountPaid]) ";
	query2 << "VALUES (";
	query2 << std::to_string(openInvoice.getPONumber()) + ", '";
	query2 << openInvoice.getBillTo() + "', '";
	query2 << openInvoice.getShipTo() + "', ";
	query2 << std::to_string(openInvoice.getAmountPaid()) + ")";

	dbHelper->sqlexec(query.str());
	dbHelper->sqlexec(query2.str());
}