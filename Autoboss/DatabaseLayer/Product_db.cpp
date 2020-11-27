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
	}
	prodList = inventory;
	return inventory;
}

std::vector<Product> Product_db::getLowStock() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM Products WHERE quantityInStock < 5");
	std::vector<Product> inventory;

	for (std::vector<std::vector<std::string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		std::vector<std::string> contents = *itr1;
		//inventory.push_back(<InsertProductConstructorHere>);
	}
	prodList = inventory;
	return inventory;
}

void Product_db::addProduct(Warehouse wh, Product prod, int quantity) {
	helper.sqlexec("UPDATE Products SET quantityInStock = (quantityInStock + " + std::to_string(quantity) + ") WHERE productID = " + std::to_string(prod.getProductID()) + " and warehouseID = " + std::to_string(wh.getWarehouseID()) + ";");
} //as in add more STONKS

//Simply creates product, so there's still none in stock until it's added
void Product_db::createProduct(Product prod) {
	string ProductID = std::to_string(prod.getProductID());
	string productName = prod.getName();
	string MSRP = std::to_string(prod.getPrice());
	string Cost = std::to_string(prod.getCost());
	string Manufacturer = prod.getManufacturer();
	string descr = prod.getDescription();
	helper.sqlexec("INSERT INTO ProductDetails(productID, productName, manufacturer, [description], MSRP, cost) VALUES(" + ProductID + ", '" + productName + "', '" + Manufacturer + "', '" + descr + "', " + MSRP + ", " + Cost + ");");
	//Now that I think about it, add product is an update. I'm thinking I might as well add 0 products into every warehouse just to make it simple
	//Though I don't know how I'd do that in a for loop and not hardcode it lol If you got ideas I'd appreciate it, thanks
}

//I'm unsure of what to return here. It's not supposed to be void
//I know I'm getting product details, but what obj am I returning?
void Product_db::getProductDetails(Product prod) {
	helper.sqlexec("SELECT * FROM ProductDetails WHERE productID = " + std::to_string(prod.getProductID()) + ");");
}

void Product_db::updateProduct(Product prod){
	helper.sqlexec("UPDATE ProductDetails SET productName = " + prod.getName() + ", manufacturer = " + prod.getManufacturer() + ", description = " + prod.getDescription() + ", MSRP = " + std::to_string(prod.getPrice()) + ", cost = " + std::to_string(prod.getCost()) + " WHERE productID = " + std::to_string(prod.getProductID()) + ";");
}