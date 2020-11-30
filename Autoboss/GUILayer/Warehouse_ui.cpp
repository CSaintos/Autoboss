// Warehouse_ui.cpp
#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif

using namespace GUILayer;
using namespace std;
Warehouse_ui::Warehouse_ui()
{}
string Warehouse_selection()
{	
	string response;
	cout << "******************************************************" << endl;
	cout << "******************************************************" << endl;
	cout << "1. Select WareHouse\n" <<"2.Back to Main Menu" << endl;
	cout << "Please make a selection:" << endl;
	cin >> response;
	return response;
	

}

BusinessLayer::Warehouse GUILayer::Warehouse_ui::AddWarehouse()
{
	vector<BusinessLayer::Product> inventory;
	int warehouseID;
	string email, address, phoneNumber;
	
	cout << "******************************************************" << endl;
	cout << "******************Add WareHouse***********************" << endl;
	cout << "******************************************************" << endl;
	cout << "Please input email:" << endl;
	cin >> email;
	cout << "Please input address:" << endl;
	cin >> address;
	cout << "Please input phone number:" << endl;
	cin >> phoneNumber;
	return BusinessLayer::Warehouse(inventory, warehouseID, email, address, phoneNumber);
}
BusinessLayer::Warehouse Warehouse_Selection(vector<BusinessLayer::Warehouse> x)
{
	cout << "******************************************************" << endl;
	cout << "**************Warehouse Selection Menu****************" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << "WareHouse " << (i + 1) << endl;
	}
	string answer = Warehouse_selection();
	int repo = std::stoi(answer);
	return x.at(repo - 1);
}