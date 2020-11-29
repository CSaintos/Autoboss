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
	double totalComAmount;
	

	BusinessLayer::Salesperson newSalesperson;
	cout << "******************************************************" << endl;
	cout << "********************Add Salesperson!******************" << endl;
	cout << "\nInput Employee Id:" << endl;
	cin >> employeeID;
	//cout << ""

}