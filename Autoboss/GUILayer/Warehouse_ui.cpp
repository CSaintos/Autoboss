// Warehouse_ui.cpp
#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif



using namespace GUILayer;
using namespace std;

Warehouse_ui::Warehouse_ui()
{}

string Warehouse_ui::WarehouseSelection(vector<BusinessLayer::Warehouse> warehouses)
{	
	string response;

	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		cout << "WarehouseID: " << to_string(itr->getWarehouseID()) << " | ";
		cout << "Address: " << itr->getAddress() << endl;
	}
	cout << "******************************************************" << endl;
	cout << "1. Select Warehouse" << endl;
	cout << "2. Add New Warehouse" << endl;
	cout << "3. Back to Main Menu" << endl;
	cout << "Please input numeric value:" << endl;
	std::getline( std::cin, response);

	return response;
}

BusinessLayer::Warehouse Warehouse_ui::AddWarehouse()
{
	vector<BusinessLayer::Product> inventory;
	int warehouseID = 10; // let me fix this. I didn't provide with enough info, mb.
	string email, address, phoneNumber;
	
	cout << "******************************************************" << endl;
	cout << "******************Add WareHouse***********************" << endl;
	
	cout << "Please input email:" << endl;
	std::getline( std::cin, email);
	cout << "Please input address:" << endl;
	std::getline( std::cin, address);
	cout << "Please input phone number:" << endl;
	std::getline( std::cin, phoneNumber);
	return BusinessLayer::Warehouse(inventory, warehouseID, email, address, phoneNumber);
}

BusinessLayer::Warehouse Warehouse_ui::SelectWarehouse(vector<BusinessLayer::Warehouse> warehouses)
{
	string selection;
	vector<string> warehouseIDs;
	BusinessLayer::Warehouse selectedWarehouse;

	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		warehouseIDs.push_back(to_string(itr->getWarehouseID()));
	}

	cout << "Please input the warehouse ID for selection:" << endl;

	do {
		getline(cin, selection);
	} while (none_of(warehouseIDs.begin(), warehouseIDs.end(), [selection](string s) {return s == selection;}));

	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		if (to_string(itr->getWarehouseID()) == selection) {
			selectedWarehouse = *itr;
		}
	}

	return selectedWarehouse;
}