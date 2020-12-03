// Salesperson_ui.cpp
#ifndef SALESPERSON_UI_H
#include"Salesperson_ui.h"
#endif

using namespace GUILayer;
using namespace BusinessLayer;
using namespace std;

Salesperson_ui::Salesperson_ui()
{}

BusinessLayer::Salesperson Salesperson_ui::AddSalesperson() {
	std::string employeeName;
	double commRate;

	cout << "******************************************************" << endl;
	cout << "********************Add Salesperson*******************" << endl;
	cout << "Please enter Employee Name:" << endl;
	std::getline(cin, employeeName);

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Input Employee Commision Rate Percentage:" << endl;
		cin >> commRate;
	} while (cin.fail());
	

	BusinessLayer::Salesperson newSalesperson(
		vector<BusinessLayer::Invoice>(), 
		0, 
		((float)commRate/100), 
		employeeName, 
		0.0, 
		0.0
	);
		
	return newSalesperson;
}

BusinessLayer::Salesperson Salesperson_ui::SetCommission(vector<BusinessLayer::Salesperson> salespeople) {
	vector<string> choices;
	string choice;
	float rate;

	for (auto itr = salespeople.begin(); itr != salespeople.end(); ++itr) {
		choices.push_back(to_string(itr->getEmployeeID()));
	}

	do {
		cout << "Please choose employee ID to set commission rate:" << endl;
		getline(cin, choice);
	} while (none_of(choices.begin(), choices.end(), [choice](string s) { return choice == s; }));

	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please set new rate for employee chosen:" << endl;
		cin >> rate;
	} while (cin.fail());

	for (auto itr = salespeople.begin(); itr != salespeople.end(); ++itr) {
		if (to_string(itr->getEmployeeID()) == choice) {
			itr->setCommisionRate(rate / 100);
			return *itr; // bad code
		}
	}

	return BusinessLayer::Salesperson(); // bad code
}

string Salesperson_ui::Salespeople(std::vector<BusinessLayer::Salesperson> salespeople) {
	string choice;

	cout << "******************************************************" << endl;
	cout << "******************Salesperson Roster******************" << endl;
	for (auto itr = salespeople.begin(); itr != salespeople.end(); ++itr) {
		int idSS = 7 - to_string(itr->getEmployeeID()).size();
		int nameSS = 30 - itr->getEmployeeName().size();
		cout << fixed;
		cout << setprecision(2);
		cout << "ID: " << to_string(itr->getEmployeeID()) << setw(idSS) << " | "
			<< "Name: " << itr->getEmployeeName() << setw(nameSS) << " | "
			<< "Rate: %" << (itr->getCommisionRate() * 100) << endl;
	}

	cout << "******************************************************" << endl;
	cout << "1. Set Commission Rate" << endl;
	cout << "2. Add Salesperson" << endl;
	cout << "3. Back to Main Menu" << endl;

	do {
		cout << "Please input choice:" << endl;
		getline(cin, choice);
	} while (choice != "1" && choice != "2" && choice != "3");

	return choice;

}