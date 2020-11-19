#include "Product.h"

using namespace BusinessLayer;

Product::Product(std::string Name, int productID, double Price, double Cost, int Quantity)
	: price(Price), cost(Cost), productName(Name),quantity(Quantity){}

void Product::setPrice(double p) {
	price = p;
}

double Product::getPrice() const {
	return price;
}