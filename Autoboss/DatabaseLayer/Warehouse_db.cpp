// Warehouse_db.cpp
#ifndef WAREHOUSE_DB_H
#include "Warehouse_db.h"
#endif

using namespace DatabaseLayer;
using namespace BusinessLayer;
using namespace std;

Warehouse_db::Warehouse_db() : 
	dbHelper(std::make_unique<DatabaseLayer::DBHelper>())
{}

std::vector<BusinessLayer::Warehouse> Warehouse_db::getWarehouses() {
	std::vector<std::vector<std::string>> temp = dbHelper->sqlexec("SELECT * FROM Warehouses");
	std::vector<BusinessLayer::Warehouse> warehouseList;
	/* phoneNumber is supposed to be string
	we do NOT want to have to insert product inventory*/
	vector<Product> inv;
	// end temp values

	for (vector<vector<string>>::iterator itr1 = temp.begin(); itr1 != temp.end(); itr1++) {
		vector<string> contents = *itr1;
		warehouseList.push_back(Warehouse(inv, std::stoi(contents[0]), contents[1], contents[2], contents[3]));
	}

	return warehouseList;
}

//Gives a query failure but it works if ran directly as a new query so the query is right
//but this was why I think sqlexec should've been void, and a private variable called
//sqlretrieveddata (idk change the name lol) would be the vector<vector<string>> and we'd have a getter for that 
//I didn't wanna do it without letting you know first 
void Warehouse_db::addWarehouse(BusinessLayer::Warehouse wh)	{
	//Phonenumber is not a string should be tho, I think
	ostringstream query;
	query << "INSERT INTO ";
	query << "dbo.Warehouses([warehouseID], [address], [email], [phoneNumber]) ";
	query << "VALUES (";
	query << std::to_string(wh.getWarehouseID()) + ", '";
	query << wh.getAddress() + "', '";
	query << wh.getEmail() + "', '";
	query << wh.getPhoneNumber() + "')";
	cout << query.str();
	dbHelper->sqlexec(query.str());
	//cout << "INSERT INTO dbo.Warehouses ([warehouseID], [address], [email], [phoneNumber]) VALUES (" + std::to_string(wh.getWarehouseID()) + ", '" + wh.getAddress() + "', '" + wh.getEmail() + "', 'wh.getPhoneNumber')" << endl;
	//dbHelper->sqlexec("INSERT INTO dbo.Warehouses ([warehouseID], [address], [email], [phoneNumber]) VALUES (" + std::to_string(wh.getWarehouseID()) + ", '" + wh.getAddress() + "', '" + wh.getEmail() + "', 'wh.getPhoneNumber')");
}

void Warehouse_db::test() {

}
