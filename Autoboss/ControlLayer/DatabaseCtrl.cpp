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
		warehouseList.push_back(Warehouse(inv, std::stoi(contents[0]), contents[1], contents[2], contents[3]));
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
	query << "WHERE p.warehouseID = " + warehouse.getWarehouseID();
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
				""
			)
		);
	}

	return products;
}

void DatabaseCtrl::addProduct(BusinessLayer::Product product, BusinessLayer::Warehouse warehouse) { // TODO KINDA
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
		empList.push_back(Salesperson(std::vector<Invoice>(),
			std::stoi(contents[0]),
			std::stod(contents[1]),
			contents[2],
			std::stod(contents[3]),
			std::stod(contents[4])));
	}

	return empList;
}

void DatabaseCtrl::setCommissionRate(BusinessLayer::Salesperson salesperson) { // TODO KINDA
	std::ostringstream query;
	query << "UPDATE SalesPeople SET commissionRate = ";
	query << std::to_string(salesperson.getCommisionRate());
	query << " WHERE employeeID = ";
	query << std::to_string(salesperson.getEmployeeID());
	dbHelper->sqlexec(query.str());
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getProducts() { // TODO
	return std::vector<BusinessLayer::Product>();
}

BusinessLayer::Product DatabaseCtrl::getProductDetails(BusinessLayer::Product product) { // TODO
	return BusinessLayer::Product();
}

std::vector<BusinessLayer::Product> DatabaseCtrl::getLowStock() { // TODO KINDA
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
				""
			)
		);
	}

	return lowStock;
}

void DatabaseCtrl::createProduct(BusinessLayer::Product product) { // TODO

}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getOInvoices() { // TODO KINDA NEEDS REVIEW
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM OpenInvoices");
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
			0, //Delivery Charge
			0, //Discount Applied
			contents[1], //Bill To
			contents[2], //String shipTo
			"2020-12-25", //Orderdate
			std::stod(contents[3]), // amount paid
			"2020-12-25", //closeDate
			0)); // salesperson ID
	}
	return inList;
}

BusinessLayer::Invoice DatabaseCtrl::getOInvoiceDetails(BusinessLayer::Invoice openInvoice) { // TODO
	return BusinessLayer::Invoice();
}

void DatabaseCtrl::payInvoice(BusinessLayer::Invoice openInvoice) { // TODO

}

void DatabaseCtrl::updateProduct(BusinessLayer::Product product) { // TODO

}

std::vector<BusinessLayer::Invoice> DatabaseCtrl::getCInvoices() { // TODO KINDA
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM ClosedInvoices");
	std::vector<Invoice> inList;

	//*itr = PONumber ; closeDate
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		inList.push_back(Invoice(std::vector<Product>(),
			0, //Invoice Number
			std::stoi(contents[0]), //PONumber
			0.0f, //InterestRate
			30000000, //Total Amount 
			132, //Delivery Charge
			0, //Discount Applied
			"Trump", // Bill To
			"Los Angeles", // ShipTo
			"2020-11-28", //Orderdate
			30000000.0, // amount paid
			contents[1], // close date
			0)); // salesperson ID
	}

	return inList;
}

BusinessLayer::Invoice DatabaseCtrl::getCInvoiceDetails(BusinessLayer::Invoice closedInvoice) { // TODO
	return BusinessLayer::Invoice();
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

void DatabaseCtrl::addOInvoice(BusinessLayer::Invoice openInvoice) { // TODO

}