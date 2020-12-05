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
	cout << "*********************Warehouses***********************" << endl;
	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		int idSS = 7 - to_string(itr->getWarehouseID()).size();
		cout << "WarehouseID: " << to_string(itr->getWarehouseID()) << setw(idSS) << " | ";
		cout << "Address: " << itr->getAddress() << endl;
	}
	cout << "******************************************************" << endl;
	cout << "1. Select Warehouse" << endl;
	cout << "2. Add New Warehouse" << endl;
	cout << "3. Back to Main Menu" << endl;
	do {
		cout << "Please enter a choice selection:" << endl;
		getline(cin, response);
	} while (response != "1" && response != "2" && response != "3");
	
	return response;
}

BusinessLayer::Warehouse Warehouse_ui::AddWarehouse() {
	vector<BusinessLayer::Product> inventory = vector<BusinessLayer::Product>();
	string email, address, phoneNumber;
	
	cout << "******************************************************" << endl;
	cout << "******************Add WareHouse***********************" << endl;
	
	cout << "Please input email:" << endl;
	getline(cin, email);
	cout << "Please input address:" << endl;
	getline(cin, address);
	cout << "Please input phone number:" << endl;
	getline(cin, phoneNumber);

	return BusinessLayer::Warehouse(inventory, 0, email, address, phoneNumber);
}

BusinessLayer::Warehouse Warehouse_ui::SelectWarehouse(vector<BusinessLayer::Warehouse> warehouses)
{
	string selection;
	vector<string> warehouseIDs;
	BusinessLayer::Warehouse selectedWarehouse;

	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		warehouseIDs.push_back(to_string(itr->getWarehouseID()));
	}

	do {
		cout << "Please input the warehouse ID for selection, select 0 to exit:" << endl;
		getline(cin, selection);
	} while (none_of(warehouseIDs.begin(), warehouseIDs.end(), [selection](string s) {return s == selection;}) && selection != "0");
	cout << endl;

	if (selection == "0") {
		return BusinessLayer::Warehouse();
	}

	for (auto itr = warehouses.begin(); itr != warehouses.end(); ++itr) {
		if (to_string(itr->getWarehouseID()) == selection) {
			selectedWarehouse = *itr;
		}
	}

	return selectedWarehouse;
}