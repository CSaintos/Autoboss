#include "Product_bi.h"

using namespace BusinessLayer;

Product_bi::Product_bi(double Price, double Cost, double Profit, std::string Name, int Quantity)
	: price(Price), cost(Cost), profit(Profit), name(Name),quantity(Quantity){}

void Product_bi::setPrice(double p) {
	price = p;
}

double Product_bi::getPrice() const {
	return price;
}