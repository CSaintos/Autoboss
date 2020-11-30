// Salesperson_ui.cpp
#ifndef SALESPERSON_UI_H
#include"Salesperson_ui.h"
#endif

using namespace GUILayer;
using namespace BusinessLayer;
using namespace std;

Salesperson_ui::Salesperson_ui()
{}

BusinessLayer::Salesperson Salesperson_ui::AddSalesperson()
{
	int employeeID;
	float commRate;
	std::string employeeName;
	std::vector<BusinessLayer::Invoice> soldList;
	double totalComAmount = 0;
	double totalSalesAmount = 0;

	//BusinessLayer::Salesperson newSalesperson;
	cout << "******************************************************" << endl;
	cout << "********************Add Salesperson!******************" << endl;
	cout << "Please enter Employee Name:" << endl;
	cin >> employeeName;
	cout << "Input Employee Id:" << endl;
	cin  >> employeeID;
	cout << "Input Employee Commision Rate:"<<endl;
	cin >> commRate;
	cout << "Input Employee Current Total Commission Amount:" << endl;
	cin >> totalComAmount;
	cout << "Input Emplyee Current Total Sales Amount:" << endl;
	cin >> totalSalesAmount;

	BusinessLayer::Salesperson newSalesperson(soldList, employeeID, commRate, employeeName, totalComAmount, totalSalesAmount);
		
	return newSalesperson;
}

void Salesperson_ui::SetCommission(BusinessLayer::Salesperson x)
{
	float update;
	cout << "*****************************************************************" << endl;
	cout << "********************Salesperson Commison Update******************" << endl;
	cout << "Please input new commison rate:" << endl;
	cin >> update;
	x.setCommisionRate(update);
}

string Salesperson_ui::Salespeople(std::vector<BusinessLayer::Salesperson> x)
{
	string response;
	cout << "*****************************************************************" << endl;
	cout << "**********************Salesperson Roster*************************" << endl;
	for (int i = 0; i < x.size(); i++)
	{
		cout << (i + 1) << ". " << x.at(i).getEmployeeName() << endl;

	}

	cout << "*****************************************************************" << endl;
	cout << "************************Action Menu:***********************" << endl;
	cout << "1. Set Commission Rate" << endl;
	cout << "2. Add Salesperson" << endl;
	cout << "3. Back to Main Menu" << endl;
	cout << "*****************************************************************" << endl;
	cout << "************************Choose Action:***********************" << endl;
	cin >> response;

	return response;

}