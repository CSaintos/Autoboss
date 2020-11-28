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
		ctrl.databaseCtrl->setPassword(password);
	}
	else {
		ctrl.guiCtrl->EnterPassword(password);
	}

	string choice;
	do {
		choice = ctrl.guiCtrl->MainMenu();
		if (choice == "0") { // commission
			do {
				vector<Salesperson> salespeople = ctrl.databaseCtrl->getSalespeople();
				choice = ctrl.guiCtrl->Salespeople(salespeople);
				if (choice == "0") { // set commission rate
					Salesperson salesperson = ctrl.guiCtrl->SetCommission(salespeople);
					ctrl.databaseCtrl->setCommissionRate(salesperson);
				}
			} while (choice != "0"); // back to main menu
		} else if (choice == "0") { // warehouse selection
			do {
				vector<Warehouse> warehouses = ctrl.databaseCtrl->getWarehouses();
				choice = ctrl.guiCtrl->WarehouseSelection(warehouses);
				if (choice == "0") { // select warehouse
					Warehouse warehouse = ctrl.guiCtrl->SelectWarehouse(warehouses);
					do {
						vector<Product> products = ctrl.databaseCtrl->getInventory(warehouse);
						choice = ctrl.guiCtrl->Inventory(products);
						if (choice == "0") { // stock inventory
							Product product = ctrl.guiCtrl->AddProduct(products);
							ctrl.databaseCtrl->addProduct(product, warehouse);
						}
					} while (choice != "0"); // back to warehouse selection
				} else if (choice == "0") { // add new warehouse
					Warehouse warehouse = ctrl.guiCtrl->AddWarehouse();
					ctrl.databaseCtrl->addWarehouse(warehouse);
				}
			} while (choice != "0"); // back to main menu
		} else if (choice == "0") { // product statistics
			do {
				vector<Product> products = ctrl.databaseCtrl->getProducts();
			} while (choice != "0"); // back to main menu
		} else if (choice == "0") { // warnings

		} else if (choice == "0") { // create product

		} else if (choice == "0") { // open invoice list

		} else if (choice == "0") { // update product

		} else if (choice == "0") { // closed invoice list

		}
	} while (choice != "0"); // quit

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
		return false;
	}
}