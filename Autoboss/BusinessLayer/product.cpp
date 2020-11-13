#include "Product.h"
Product::Product(double Price, double Cost, double Profit, std::string Name, int Quantity): price(Price), cost(Cost), profit(Profit), name(Name),quantity(Quantity){}
void Product::setPrice(double p) {
	price = p;
}
double Product::getPrice() const {
	return price;
}