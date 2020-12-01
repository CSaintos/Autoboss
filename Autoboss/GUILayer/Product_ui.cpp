// Product_ui.cpp
#ifndef PRODUCT_UI_H
#include"Product_ui.h"
#endif

using namespace GUILayer;
using namespace BusinessLayer;
using namespace std;

Product_ui::Product_ui()
{}

BusinessLayer::Product Product_ui::AddProduct(std::vector<BusinessLayer::Product> v)
{
	int choice, amount;
	cout << "******************************************************" << endl;
	cout << "********************Add Product***********************" << endl;

	for (size_t i = 0; i < v.size(); ++i) {
		cout << (i+1) << v[i].getName() <<"........"<< v[i].getQuantity() << endl;
	}
	cout << "Pleases input the numeric representation of the desired product:" << endl;
	cin >> choice;
	cout << "Desired total amount:" << endl;
	cin >> amount;

	v[choice - 1].setQuantity(amount);
	return BusinessLayer::Product();
}

BusinessLayer::Product Product_ui::CreateProduct()
{
	string name;
	int prodID;
	int quantity = 0;
	string manufacturer, description;
	double Price, Cost;
	cout << "******************************************************" << endl;
	cout << "******************Product Creation Menu***************" << endl;

	cout << "Please input Product Name:" << endl;
	std::getline( cin, name);
	cout << "Please input Product ID:" << endl;
	cin >> prodID;
	cout << "Please input Product Price:" << endl;
	cin >> Price;
	cout << "Please input Product Cost:" << endl;
	cin >> Cost;
	cout << "Please input the Product Manufactor:" << endl;
	std::getline( cin, manufacturer);
	cout << "Please input a brief description of the Product:" << endl;
	std::getline( cin, description);
	
	
	Product newProduct( name, prodID, Price, Cost, quantity, manufacturer, quantity, description);
	return newProduct;
	
}

void Product_ui::productDetail(BusinessLayer::Product x)
{
	cout << "**********************************************************" << endl;
	cout << "******************" << x.getName() << " Details!*******************" << endl;
	cout << "Product ID:..." << x.getProductID() << endl;
	cout << "Product Manufacturer:..." << x.getManufacturer() << endl;
	cout << "Product Description:.." << x.getDescription() << endl;
	cout << "Product Sales Price:....$" << x.getPrice() << endl;
	cout << "Product Cost:....$" << x.getCost() << endl;
	cout << "Product Quantity:...." << x.getQuantity() << endl;
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
string Product_ui::ProductStats(std::vector<BusinessLayer::Product> v)
{
	string response;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << (i + 1) << v[i].getName() << endl;
	}
	cout << "**********************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	
	cout << "1.View Details" << endl;
	cout << "2.Back to Main Menu" << endl;
	std::getline( cin , response);
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
BusinessLayer::Product Product_ui::ChooseProduct(std::vector<BusinessLayer::Product> x)
{
	string response = ProductStats(x);
	string ans;
	cout << "Choose a Product to view details:" << endl;
	std::getline( cin, ans);
	int repo = std::stoi(ans);
	return x.at(repo);

}

void Product_ui::LowStock(std::vector<BusinessLayer::Product>x)
{
	cout << "***************************************************************" << endl;
	cout << "**********************Low Product List*************************" << endl;
	
	for ( size_t i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << x[i].getName() << endl;
	}
}
string Product_ui::Inventory(vector <BusinessLayer::Product> x)
{
	string response;
	cout << "**********************************************************" << endl;
	cout << "**********************Inventory List**********************" << endl;
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << x[i].getName() << endl;
	}
	cout << "**********************************************************" << endl;
	cout << "*************************Action Menu**********************" << endl;
	cout << "1. Back to Warehouse Selection\n2. Stock Inventory" << endl;
	std::getline(cin, response);
	
	return response;
}