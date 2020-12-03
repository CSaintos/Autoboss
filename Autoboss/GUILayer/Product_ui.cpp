// Product_ui.cpp
#ifndef PRODUCT_UI_H
#include"Product_ui.h"
#endif

using namespace GUILayer;
using namespace BusinessLayer;
using namespace std;

Product_ui::Product_ui()
{}

BusinessLayer::Product Product_ui::StockInventory(std::vector<BusinessLayer::Product> inventory) {
	vector<string> choices;
	string choice;
	int quantity;

	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		choices.push_back(to_string(itr->getProductID()));
	}

	do {
		cout << "Please choose product ID to stock up on:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }));

	do {
		cout << "Please enter amount to stock up on:" << endl;
	} while (!(cin >> quantity));

	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		if (to_string(itr->getProductID()) == choice) {
			itr->setQuantity(quantity);
			return *itr; // bad code
		}
	}

	return BusinessLayer::Product(); // if all else fails... ik bad code... too lazy to fix
}

BusinessLayer::Product Product_ui::AddInventory(std::vector<BusinessLayer::Product> products) { // TODO
	vector<string> choices;
	string choice;

	cout << "******************************************************" << endl;
	cout << "***************Add Product to Inventory***************" << endl;

	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		int idSS = 7 - to_string(itr->getProductID()).size();
		cout << "ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
			<< "Name: " << itr->getName() << endl;
		choices.push_back(to_string(itr->getProductID()));
	}

	cout << "******************************************************" << endl;

	do {
		cout << "Please input product ID to add product in warehouse inventory:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }));
	
	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		if (to_string(itr->getProductID()) == choice) {
			return *itr;
		}
	}

	return BusinessLayer::Product(); // if all else fails
}

BusinessLayer::Product Product_ui::CreateProduct() {
	string name, manufacturer, description;
	double price, cost;

	cout << "******************************************************" << endl;
	cout << "******************Product Creation Menu***************" << endl;

	cout << "Please input Product Name:" << endl;
	getline(cin, name);

	do {
		cout << "Please input Product Price:" << endl;
	} while (!(cin >> price));

	do {
		cout << "Please input Product Cost:" << endl;
	} while (!(cin >> cost));

	getline(cin, manufacturer); // catch cin error
	cout << "Please input the Product Manufacturer:" << endl;
	getline(cin, manufacturer);
	cout << "Please input a brief description of the Product:" << endl;
	getline(cin, description);
	
	BusinessLayer::Product newProduct( 
		name, 
		0, 
		price, 
		cost, 
		0, 
		manufacturer, 
		0, 
		description
	);

	return newProduct;
}

void Product_ui::productDetail(BusinessLayer::Product x)
{
	cout << "**********************************************************" << endl;
	cout << "**********************Product Details*********************" << endl;
	cout << "Product Name:........... " << x.getName() << endl;
	cout << "Product ID:............. " << x.getProductID() << endl;
	cout << "Product Manufacturer:... " << x.getManufacturer() << endl;
	cout << "Product Description:.... " << x.getDescription() << endl;
	cout << "Product Sales Price:.... $" << x.getPrice() << endl;
	cout << "Product Cost:........... $" << x.getCost() << endl;
}

BusinessLayer::Product Product_ui::UpdateProduct(std::vector<BusinessLayer::Product> x)
{
	int choice, choice2;
	cout << "**********************************************************" << endl;
	cout << "**********************Products****************************" << endl;
	
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << ". " << x[i].getName() << endl;
	}
	cout << "Choose your product:" << endl;
	cin >> choice;


	choice2 = updateSelection();
	while (choice2 != 4)
	{
		switch (choice2) {
		case 1:
		 double  newPrice;
			cout << "Please input new Product Price:" << endl;
			cin >> newPrice;
			x[ choice-1 ].setPrice(newPrice);
			break;
		case 2:
			double newCost;
			cout << "Please input new Product Cost:" << endl;
			cin >> newCost;
			x[ choice-1 ].setCost(newCost);
			break;
		case 3:
			int newQua;
			cout << "Please input Product's new Total Quantiiy:" << endl;
			cin >> newQua;
			x [ choice-1 ].setQuantity(newQua);
			break;
		case 4:
			break;
		default:
			cout << "We do not recognize that answer please try again." << endl;
		}
		choice2 = updateSelection();
	}

	return x[choice -1];

}
string Product_ui::ProductStats(std::vector<BusinessLayer::Product> products) {
	string response;

	cout << "**********************************************************" << endl;
	cout << "********************List of Products**********************" << endl;
	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		int idSS = 7 - to_string(itr->getProductID()).size();
		cout << "ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
			<< "Name: " << itr->getName() << endl;
	}

	cout << "**********************************************************" << endl;
	cout << "1. View Details" << endl;
	cout << "2. Back to Main Menu" << endl;

	do {
		cout << "Please input choice:" << endl;
		getline(cin, response);
	} while (response != "1" && response != "2");
	cout << endl;
	
	return response;
}

int Product_ui::updateSelection()
{
	int ans;
	cout << "**********************************************************" << endl;
	cout << "******************Product Update Menu*******************" << endl;
	cout << "1. Update Sales Price		2. Update Product Cost " << endl;
	cout << "3. Update Quantity			4.Return" << endl;
	cin >> ans;

	return ans;
}
BusinessLayer::Product Product_ui::ChooseProduct(std::vector<BusinessLayer::Product> products) {
	vector<string> choices;
	string choice;

	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		choices.push_back(to_string(itr->getProductID()));
	}

	do {
		cout << "Choose a product ID to view details:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }));

	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		if (to_string(itr->getProductID()) == choice) {
			return *itr;
		}
	}

	return BusinessLayer::Product();
}

void Product_ui::LowStock(std::vector<BusinessLayer::Product> lowStock)
{
	cout << "******************************************************" << endl;
	cout << "*******************Low Stock List*********************" << endl;
	
	for (auto itr = lowStock.begin(); itr != lowStock.end(); ++itr) {
		int idSS = 7 - to_string(itr->getProductID()).size();
		int nameSS = 30 - itr->getName().size();
		cout << "ID: " << to_string(itr->getProductID()) << setw(idSS) << " | "
			<< "Name: " << itr->getName() << setw(nameSS) << " | "
			<< "Quantity: " << to_string(itr->getQuantity()) << endl;
	}
	cout << "******************************************************" << endl;

	cout << endl;
}

string Product_ui::Inventory(vector<BusinessLayer::Product> inventory)
{
	string response;
	int idS = 7;
	int nameS = 30;

	cout << "**********************************************************" << endl;
	cout << "**********************Inventory List**********************" << endl;
	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		int idSS = idS - to_string(itr->getProductID()).size();
		int nameSS = nameS - itr->getName().size();

		cout << "ID: " << to_string(itr->getProductID()) << setw(idSS) << " | " 
		<< "Name: " << itr->getName() << setw(nameSS) << " | "
		<< "Quantity: " << to_string(itr->getQuantity()) << endl;
	}
	cout << "**********************************************************" << endl;
	cout << "1. Back to Warehouse Selection " << endl;
	cout << "2. Stock Inventory" << endl;
	cout << "3. Add Inventory" << endl;
	do {
		cout << "Please make a selection:" << endl;
		std::getline(cin, response);
	} while (response != "1" && response != "2" && response != "3");
	
	return response;
}