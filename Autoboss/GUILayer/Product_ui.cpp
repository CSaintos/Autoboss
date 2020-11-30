// Product_ui.cpp
#ifndef PRODUCT_UI_H
#include"Product_ui.h"
#endif

using namespace GUILayer;
using namespace BusinessLayer;
using namespace std;

Product_ui::Product_ui()
{}

BusinessLayer::Product AddProduct(std::vector<BusinessLayer::Product> v)
{
	int choice, amount;
	cout << "******************************************************" << endl;
	cout << "********************Add Product***********************" << endl;

	for (int i = 0; i < v.size(); ++i) {
		cout << (i+1) << v.at(i).getName() <<"........"<< v.at(i).getQuantity() << endl;
	}
	cout << "Choose your product:" << endl;
	cin >> choice;
	cout << "Desired total amount:" << endl;
	cin >> amount;

	v.at(choice - 1).setQuantity(amount);

}

BusinessLayer::Product CreateProduct()
{
	string name;
	int prodID;
	int quantity = 0;
	string manufactor;
	double Price, Cost;
	cout << "**********************************************************" << endl;
	cout << "******************Product Creation Menu*******************" << endl;

	cout << "Please input Product Name:" << endl;
	cin >> name;
	cout << "Please input Product ID:" << endl;
	cin >> prodID;
	cout << "Please input Product Price:" << endl;
	cin >> Price;
	cout << "Please input Product Cost:" << endl;
	cin >> Cost;
	cout << "Please input the Product Manufactor" << endl;
	cin >> manufactor;
	
	
	Product newProduct(name, prodID, Price, Cost, quantity, manufactor, quantity);
	return newProduct;
	
}

void productDetail(BusinessLayer::Product x)
{
	cout << "**********************************************************" << endl;
	cout << "******************" << x.getName() << " Details!*******************" << endl;
	cout << "Product ID:..." << x.getProductID() << endl;
	cout << "Product Manufacturer:..." << x.getManufacturer() << endl;
	cout << "Product Sales Price:...$" << x.getPrice() << endl;
	cout << "Product Cost:....$" << x.getCost() << endl;
	cout << "Product Quantity:..." << x.getQuantity() << endl;
}

BusinessLayer::Product UpdateProduct(std::vector<BusinessLayer::Product> x)
{
	int choice, choice2;
	cout << "**********************************************************" << endl;
	cout << "**********************Products****************************" << endl;
	
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << ". " << x.at(i).getName() << endl;
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
			x.at(choice).setPrice(newPrice);
			break;
		case 2:
			double newCost;
			cout << "Please input new Product Cost:" << endl;
			cin >> newCost;
			x.at(choice).setCost(newCost);
			break;
		case 3:
			int newQua;
			cout << "Please input Product's new Total Quantiiy:" << endl;
			cin >> newQua;
			x.at(choice).setQuantity(newQua);
			break;
		case 4:
			break;
		default:
			cout << "We do not recognize that answer please try again." << endl;
		}
		choice2 = updateSelection();
	}

	return x.at(choice);
	

}
string ProductStats(std::vector<BusinessLayer::Product> v)
{
	string response;
	for (int i = 0; i < v.size(); i++)
	{
		cout << (i + 1) << v.at(i).getName() << endl;
	}
	cout << "**********************************************************" << endl;
	cout << "**********************Action Menu*************************" << endl;
	cout << "**********************************************************" << endl;
	cout << "1.View Details" << endl;
	cout << "2.Back to Main Menu" << endl;
	cin >> response;
	return response;
}

int updateSelection()
{
	int ans;
	cout << "**********************************************************" << endl;
	cout << "******************Product Update Menu*******************" << endl;
	cout << "1. Update Sales Price		2. Update Product Cost " << endl;
	cout << "3. Update Quantity			4.Return" << endl;
	cin >> ans;

	return ans;
}
BusinessLayer::Product ChooseProduct(std::vector<BusinessLayer::Product> x)
{
	string response = ProductStats(x);
	string ans;
	cout << "Choose a Product to view details:" << endl;
	cin >> ans;
	int repo = std::stoi(ans);
	return x.at(repo);

}