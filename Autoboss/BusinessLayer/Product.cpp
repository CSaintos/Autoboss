#include "Product.h"
using namespace std;

using namespace BusinessLayer;

Product::Product() : 
	mProductName(""), mprice(0.0), mcost(0.0), mManufacturer(""), mquantityInStock(0), mproductID(0)
{}

Product::Product(string productName, int ProductID, double Price, double Cost,
	double Profit, int Quantity, string Manufacturer):
 mProductName(productName), mprice(Price), mcost(Cost),
	mManufacturer(Manufacturer), mquantityInStock(Quantity), mproductID(ProductID) 
{}

void Product::setPrice(double p) {
	mprice = p;
}
void Product::setDescription(string s) {
	mDescription = s;
}

double Product::getPrice() const {
	return mprice;
}
double Product::getCost() const {
	return mcost;
}
double Product::getProfit() const {
	return getPrice() - getCost();
}
