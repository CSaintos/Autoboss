#include "Product.h"
using namespace std;

using namespace BusinessLayer;

//<<<<<<< Updated upstream
//=======
Product::Product(string productName, int ProductID, double Price, double Cost, int Quantity, string Manufacturer):
 mProductName(productName), mprice(Price), mcost(Cost), mManufacturer(Manufacturer), mquantityInStock(Quantity){}
//>>>>>>> Stashed changes

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
	mproductID = p;
}
void Product::setQuantity(int q) {
	mquantityInStock = q;
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
	return getPrice() - getCost();
}
int Product::getQuantity() const{
	return mquantityInStock;
}

int Product::getProductID() const {
	return mproductID;
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