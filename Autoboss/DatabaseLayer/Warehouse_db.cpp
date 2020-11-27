// Warehouse_db.cpp
#ifndef WAREHOUSE_DB_H
#include "Warehouse_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;
using namespace std;

Warehouse_db::Warehouse_db()
{}

//idk this feels redundant I could just have this under getWarehouses, what do you think
void Warehouse_db::createWHList() {
	std::vector<std::vector<std::string>> temp = helper.sqlexec("SELECT * FROM Warehouses");
	std::vector<Warehouse> whList;

	/*THESE ARE TEMPORARY VALUES UNTIL FURTHER NOTICE/FIXED
	I say tempo because I don't have inventory yet and phoneNumber is an int in BusinessLayer (I think
	it should be a string, to follow the Warehouses table unless we switch varchar to int 
	even then I think it should be a string it's a phone number)*/
	vector<Product> inv;
	int phoneNumber = 0;
	//End temp values

	for (vector<vector<string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		vector<string> contents = *itr1;
		whList.push_back(Warehouse(inv, std::stoi(contents[0]), contents[1], contents[2], phoneNumber));
	}
	
	warehouseList = whList;
}

std::vector<BusinessLayer::Warehouse> Warehouse_db::getWarehouses() {
	createWHList();	
	return warehouseList;
}

//Gives a query failure but it works if ran directly as a new query so the query is right
//but this was why I think sqlexec should've been void, and a private variable called
//sqlretrieveddata (idk change the name lol) would be the vector<vector<string>> and we'd have a getter for that 
//I didn't wanna do it without letting you know first 
void Warehouse_db::addWarehouse(BusinessLayer::Warehouse wh)	{
	//Phonenumber is not a string should be tho, I think
	helper.sqlexec("INSERT INTO Warehouses (warehouseID, address, email, phoneNumber) VALUES(" + std::to_string(wh.getWarehouseID()) + ", '" + wh.getAddress() + "', '" + wh.getEmail() + "', 'wh.getPhoneNumber');");
}

