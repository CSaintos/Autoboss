// Product_db.cpp
#ifndef PRODUCT_DB_H
#include "Product_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;
using namespace std;

//Product(string productName, int ProductID, double Price, double Cost, int Quantity, string Manufacturer)

Product_db::Product_db()
{}

//Not done since I need some Questions answered lol
std::vector<Product> Product_db::getInventory(Warehouse wh) {
	std::vector<std::vector<std::string>> details = helper.sqlexec("SELECT * FROM ProductDetails WHERE warehouseID = " + std::to_string(wh.getWarehouseID()) + ";");
	/*So question here: is there an equal amount of elements between product details and products? Difficult to fill out / construct
	a product when I'm unsure on how to access the product amount/in stock*/
	//std::vector<std::vector<std::string>> prod = helper.sqlexec("SELECT * FROM Products WHERE warehouseID = " + std::to_string(wh.getWarehouseID()) + ";");
	//std::vector<std::vector<std::string>>::iterator itr2 = prod.begin();
	std::vector<Product> inventory;
	
	//prod = warehouseID, productID, quantityinstock
	//details = productID, productName, manufacturer, description, msrp, cost
	for (std::vector<std::vector<std::string>>::iterator itr1 = details.begin(); itr1 != details.end(); itr1++) {
		std::vector<std::string> detailContents = *itr1;
		//std::vector<std::string> prodContents = *itr2;
		/*So Warehouse, Invoice, and Salespersons use the one line code that you wanted me to do lol 
		I'm doing it differently here in product so you can kind of see why I think it's cleaner this way? ish?
		Let me know which one you think is easier to read and I'll make the changes necessary. Thanks!*/
		/*string ProductID = detailContents[0];
		string productName = detailContents[1];
		double Price = ;
		double Cost = ;
		int Quantity = ;
		string Manufacturer = ;
		inventory.push_back(Product(productName, ProductID, Price, Cost, Quantity, Manufacturer));
		if (itr2 != prod.end()) {
			itr2++;
		}*/

	}
	prodList = inventory;
	return inventory;
	
}

//Not done; same issue as the one above
/*
To reiterate my issue:
I'm supposed to return a vector of products, still trying to figure out if I need to actually select both or just one
(Both as in prod deets and just products) it's all easily done though*/
std::vector<Product> Product_db::getAllProducts() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM Products");
	std::vector<std::vector<std::string>>::iterator itr;
	std::vector<Product> inventory;

	//*itr = PONumber, billTo, shipTo, amountPaid
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		//inventory.push_back(<InsertProductConstructorHere>);
		inventory.push_back(Product(contents[1], //str productName
			std::stoi(contents[0]), //productID
			std::stod(contents[4]), //double Price
			std::stod(contents[5]), //double Cost
			0, //int quantity
			contents[2], //str manufacturer
			0, //int quantity ordered
			contents[3] //string descr
		));

			/*string productName, int productID, double Price, double Cost,
			int Quantity, string Manufacturer, int QuantityOrdered, string desription)*/
	}
	prodList = inventory;
	return inventory;
}

std::vector<Product> Product_db::getLowStock() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM Products WHERE quantityInStock < 5");
	std::vector<Product> inventory;

	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		inventory.push_back(Product(contents[1], //str productName
			std::stoi(contents[0]), //productID
			std::stod(contents[4]), //double Price
			std::stod(contents[5]), //double Cost
			0, //int quantity
			contents[2], //str manufacturer
			0, //int quantity ordered
			contents[3] //string descr
		));
	}
	prodList = inventory;
	return inventory;
}

void Product_db::addProduct(Warehouse wh, Product prod, int quantity) {
	helper.sqlexec("UPDATE Products SET quantityInStock = (quantityInStock + " + std::to_string(quantity) + ") WHERE productID = " + std::to_string(prod.getProductID()) + " and warehouseID = " + std::to_string(wh.getWarehouseID()) + ";");
	//Select Products.id from products, where warehouse id = null and productid = productid returns "0"
} //as in add more STONKS

//Simply creates product, so there's still none in stock until it's added
void Product_db::createProduct(Product prod) {
	std::ostringstream query;
	query << "INSERT INTO ProductDetails(productID, productName, manufacturer, [description], MSRP, cost) ";
	query << "VALUES(";
	query << std::to_string(prod.getProductID()) + ", '";
	query << prod.getName() + "', '";
	query << prod.getManufacturer() + "', '";
	query << prod.getDescription() + "', ";
	query << std::to_string(prod.getPrice()) + ", ";
	query << std::to_string(prod.getCost()) + ")";
	helper.sqlexec(query.str());
}

//Shouldn't this return a product?
void Product_db::getProductDetails(Product prod) {
//Product Product_db::getProductDetails(Product prod) {
	std::ostringstream query;
	query << "SELECT * FROM ProductDetails WHERE productID = ";
	query << std::to_string(prod.getProductID()) + ")";
	std::vector<std::vector<std::string>> temp = helper.sqlexec(query.str());
	std::vector<Product> inventory;
	//details = productID, productName, manufacturer, description, msrp, cost
	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		inventory.push_back(Product(contents[1], //str productName
			std::stoi(contents[0]), //productID
			std::stod(contents[4]), //double Price
			std::stod(contents[5]), //double Cost
			0, //int quantity
			contents[2], //str manufacturer
			0, //int quantity ordered
			contents[3] //string descr
			));
		//return inventory[0];
	}
}

void Product_db::updateProduct(Product prod){
	std::ostringstream query;
	query << "UPDATE ProductDetails ";
	query << "SET productName = '" + prod.getName() + "', ";
	query << "manufacturer = '" + prod.getManufacturer() + "', ";
	query << "description = '" + prod.getDescription() + ", ";
	query << "MSRP = " + std::to_string(prod.getPrice()) + ", ";
	query << "cost = " + std::to_string(prod.getCost()) + ", ";
	query << "WHERE productID = " + std::to_string(prod.getProductID());
	helper.sqlexec(query.str());
}

void Product_db::test()	{

}