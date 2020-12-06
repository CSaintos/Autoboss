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
	string choice, dummy;
	int quantity;

	for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
		choices.push_back(to_string(itr->getProductID()));
	}

	do {
		cout << "Please choose product ID to stock up on:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }));

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter amount to stock up on:" << endl;
		cin >> quantity;
	} while (cin.fail());
	getline(cin, dummy);

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
	string name, manufacturer, description, dummy;
	double price, cost;

	cout << "******************************************************" << endl;
	cout << "******************Product Creation Menu***************" << endl;

	cout << "Please input Product Name:" << endl;
	getline(cin, name);

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input Product Price:" << endl;
		cin >> price;
	} while (cin.fail());
	getline(cin, dummy);

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please input Product Cost:" << endl;
		cin >> cost;
	} while (cin.fail());
	getline(cin, dummy);

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

void Product_ui::productDetail(BusinessLayer::Product product) {
	if (product.getProductID() != 0) {
		cout << "**********************************************************" << endl;
		cout << "**********************Product Details*********************" << endl;
		cout << "Product Name:........... " << product.getName() << endl;
		cout << "Product ID:............. " << product.getProductID() << endl;
		cout << "Product Manufacturer:... " << product.getManufacturer() << endl;
		cout << "Product Description:.... " << product.getDescription() << endl;
		cout << "Product Sales Price:.... $" << product.getPrice() << endl;
		cout << "Product Cost:........... $" << product.getCost() << endl;
	}
	cout << endl;
}

BusinessLayer::Product Product_ui::UpdateProduct(std::vector<BusinessLayer::Product> products) {
	BusinessLayer::Product updateProduct;
	vector<string> choices;
	string choice, name, dummy;
	bool choiceFound = false;
	double money;

	cout << "******************************************************" << endl;
	cout << "**********************Products************************" << endl;
	
	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		cout << fixed;
		cout << setprecision(2);
		cout << "ID: " << to_string(itr->getProductID()) << " | "
			<< "Name: " << itr->getName() << " | "
			<< "Sale price: " << itr->getPrice() << " | "
			<< "Cost: " << itr->getCost() << endl;
		choices.push_back(to_string(itr->getProductID()));
	}

	do {
		cout << "Choose your product ID, select 0 to exit:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	if (choice == "0") {
		return BusinessLayer::Product();
	}

	for (auto itr = products.begin(); itr != products.end() && !choiceFound; ++itr) {
		if (to_string(itr->getProductID()) == choice) {
			choiceFound = true;
			updateProduct = *itr;
		}
	}

	cout << endl;

	do {
		cout << "******************************************************" << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << "ID: " << to_string(updateProduct.getProductID()) << " | "
			<< "Name: " << updateProduct.getName() << " | "
			<< "Sale price: " << updateProduct.getPrice() << " | "
			<< "Cost: " << updateProduct.getCost() << endl;
		cout << "******************************************************" << endl;
		cout << "1. Update Name" << endl;
		cout << "2. Update Sale Price" << endl;
		cout << "3. Update Cost" << endl;
		cout << "4. Confirm Update" << endl;
		cout << "5. Cancel Update" << endl;
		cout << "Please input the numeric value of your selection:" << endl;
		getline(cin, choice);

		if (choice == "1") {
			cout << "Please enter a new name for the product:" << endl;
			getline(cin, name);
			updateProduct.setproductName(name);
		} else if (choice == "2") {
			do {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please set a new sale price:" << endl;
				cin >> money;
			} while (cin.fail());
			getline(cin, dummy);

			updateProduct.setPrice(money);
		} else if (choice == "3") {
			do {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please set a new cost:" << endl;
				cin >> money;
			} while (cin.fail());
			getline(cin, dummy);

			updateProduct.setCost(money);
		}

	} while (choice != "4" && choice != "5");

	if (choice == "5") {
		return BusinessLayer::Product();
	} else {
		return updateProduct;
	}
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
		cout << "Please input the numeric value of your selection:" << endl;
		getline(cin, response);
	} while (response != "1" && response != "2");
	cout << endl;
	
	return response;
}

BusinessLayer::Product Product_ui::ChooseProduct(std::vector<BusinessLayer::Product> products) {
	vector<string> choices;
	string choice;

	for (auto itr = products.begin(); itr != products.end(); ++itr) {
		choices.push_back(to_string(itr->getProductID()));
	}

	do {
		cout << "Choose a product ID to view details, select 0 to exit:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return s == choice; }) && choice != "0");

	if (choice == "0") {
		return BusinessLayer::Product();
	}

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
	cout << "1. Stock Inventory" << endl;
	cout << "2. Add Inventory" << endl;
	cout << "3. Back to Warehouse Selection" << endl;
	do {
		cout << "Please enter the numeric value of your selection:" << endl;
		getline(cin, response);
	} while (response != "1" && response != "2" && response != "3");
	
	return response;
}