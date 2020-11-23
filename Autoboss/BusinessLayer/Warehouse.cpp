#include "Warehouse.h"

using namespace std;
using namespace BusinessLayer;

Warehouse::Warehouse(vector<Product> inv, int wID,/* string email, string address,*/ int phoneNumber) : mInventory(inv),
	mWarehouseID(wID),/* mEmail(email), mAddress(address),*/ mPhoneNumber(phoneNumber) 
{}

void Warehouse::appendInventory(vector<Product>& v, Product& p) {
	v.push_back(p);
}

vector<Product> Warehouse::getInventory() const {
	return mInventory;
}

int Warehouse::getWarehouseID() const {
	return mWarehouseID;
}

//string Warehouse::getEmail() const {
//	return mEmail;
//}

int Warehouse::getPhoneNumber() const {
	return mPhoneNumber;
}

//string Warehouse::getAddress() const {
//	return mAddress;
//}