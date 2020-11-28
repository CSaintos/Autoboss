// Main.cpp
#ifndef MAIN_H
#include "Main.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;
using namespace BusinessLayer;
using namespace DatabaseLayer;
using namespace std;

int main(int argc, char* argv[]) {
	Main ctrl;
	ctrl.InstantiateControllers();

	// tester code
	if (ctrl.RunTesters()) {
		ctrl.CloseControllers();
		return 0;
	}

	// application code
	string date = ctrl.businessCtrl->getDate();
	ctrl.databaseCtrl->setCurrentDate(date);
	string password = ctrl.databaseCtrl->getPassword();

	if (password == "0") {
		password = ctrl.guiCtrl->CreatePassword();
		if (password == "") password = "0"; // temp
		ctrl.databaseCtrl->setCurrentDate(date);
	}
	else {
		ctrl.guiCtrl->EnterPassword(password);
	}

	ctrl.CloseControllers();
	return 0;
}

void Main::InstantiateControllers() {
	guiCtrl = GUICtrl::GetInstance();
	businessCtrl = BusinessCtrl::GetInstance();
	databaseCtrl = DatabaseCtrl::GetInstance();

	databaseCtrl->openDB();
}

void Main::CloseControllers() {
	databaseCtrl->closeDB();

	delete(guiCtrl);
	delete(businessCtrl);
	delete(databaseCtrl);
}

bool Main::RunTesters() {
	cout << "Which test would you like to run? (b)usiness, (d)atabase, (g)ui, (n)one" << endl;
	string input;
	cin >> input;
	if (input == "b") {
		businessCtrl->test();
		return true;
	}
	else if (input == "d") {
		databaseCtrl->test();
		return true;
	}
	else if (input == "g") {
		guiCtrl->test();
		return true;
	}
	else {
		cout << "Invalid input" << endl;
		return false;
	}
}