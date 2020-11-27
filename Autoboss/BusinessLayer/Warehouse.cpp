// Warehouse.cpp
#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif

using namespace std;
using namespace BusinessLayer;



Warehouse::Warehouse(): mInventory(),mWarehouseID(), mEmail(), mAddress(), mPhoneNumber() {}
Warehouse::Warehouse(vector<Product> inv, int wID, string email, string address, int phoneNumber) : mInventory(inv),
	mWarehouseID(wID), mEmail(email), mAddress(address), mPhoneNumber(phoneNumber) 
{}

void Warehouse::appendInventory(vector<Product>& v, Product& p) {
	v.push_back(p);
}

vector<Product> Warehouse::getInventory() const {
	return mInventory;
}
<<<<<<< HEAD
int const Warehouse::getWarehouseID() const {
=======

int Warehouse::getWarehouseID() const {
>>>>>>> 714b4217127f2291be36e237c94dd596c01b2ab6
	return mWarehouseID;
}

string Warehouse::getEmail() const {
	return mEmail;
}

int Warehouse::getPhoneNumber() const {
	return mPhoneNumber;
}

string Warehouse::getAddress() const {
	return mAddress;
}