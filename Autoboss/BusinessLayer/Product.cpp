#include "Product.h"
using namespace std;

using namespace BusinessLayer;

Product::Product(string productName, int ProductID, double Price, double Cost,
	double Profit, int Quantity, string Manufacturer):
 mProductName(productName), mprice(Price), mcost(Cost),
	mManufacturer(Manufacturer), mquantityInStock(Quantity){}

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
