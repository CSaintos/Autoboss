// Product.cpp

#include "Product.h"
#include <string>
using namespace std;
using namespace BusinessLayer;
 


Product::Product() : mProductName(), mProductID(),mprice(), mcost(), mManufacturer(), mQuantityInStock(), mQuantityOrdered() {}

Product::Product(string productName, int productID, double Price, double Cost, int Quantity, string Manufacturer):
 mProductName(productName),mProductID(productID), mprice(Price), mcost(Cost), mManufacturer(Manufacturer),
	mQuantityInStock(Quantity), mQuantityOrdered(), mDescription() {}


Product::Product(string productName, int productID, double Price, double Cost,
	int Quantity, string Manufacturer, int QuantityOrdered):
	mProductName(productName), mprice(Price), mProductID(productID),mcost(Cost), mManufacturer(Manufacturer), mQuantityInStock(Quantity),
	mQuantityOrdered(QuantityOrdered),mDescription(){}




void Product::setPrice(double p) {
	mprice = p;
}

void Product::setDescription(string s) {
	mDescription = s;
}

void Product::setCost(double c){
	mcost = c;
}

void Product::setProductID(int p) {
	mProductID = p;
}

void Product::setQuantity(int q) {
	mQuantityInStock = q;
}

void Product::setproductName(string p) {
	mProductName = p;
}

double Product::getPrice() const {
	return mprice;
}

double Product::getCost() const {
	return mcost;
}

double Product::getProfit() const {
	return 100 * ((getPrice() - getCost())/getPrice());
}

int Product::getQuantity() const{
	return mQuantityInStock;
}

int Product::getProductID() const {
	return mProductID;
}

string Product::getDescription() const {
	return mDescription;
}

string Product::getManufacturer() const {
	return mManufacturer;
}

string Product::getName() const{
	return mProductName;
}