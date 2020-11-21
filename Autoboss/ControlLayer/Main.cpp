#include "Main.h"

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

	// pseudo code : the story of main (short story)
	ctrl.businessCtrl->getDate();
	ctrl.databaseCtrl->setCurrentDate();
	ctrl.databaseCtrl->getPassword();
	if (false /*password is null*/) {
		ctrl.guiCtrl->displayCreatePassword();
		ctrl.databaseCtrl->setPassword();
	} else {
		ctrl.guiCtrl->displayPassword();
	}
	ctrl.guiCtrl->displayMainMenu();
	while (false /*User does not exit*/) {}
	switch (NULL) {
	case 0: // user selects warehouse
		ctrl.databaseCtrl->getWarehouses();
		ctrl.guiCtrl->displayWarehouseSelection();
		switch (NULL) {
		case 0: // user selects a warehouse
			ctrl.databaseCtrl->getInventory(); // get inventory for said warehouse
			ctrl.guiCtrl->displayInventory();
			switch (NULL) {
			case 0: // user selects add product
				ctrl.guiCtrl->displayAddProduct();
				ctrl.databaseCtrl->addProduct();
				break;
			}
			break;
		case 1: // user selects add new warehouse
			ctrl.guiCtrl->displayAddWarehouse();
			ctrl.databaseCtrl->addWarehouse();
			break;
		}
	case 1: // user selects warnings
		ctrl.databaseCtrl->getLowStock();
		ctrl.guiCtrl->displayLowStock();
		break;
	case 2: // user selects open invoices
		ctrl.databaseCtrl->getOInvoices();
		ctrl.guiCtrl->displayOInvoices();
		switch (NULL) {
		case 0: // user selects pay invoice
			ctrl.guiCtrl->displayPayInvoice();
			ctrl.databaseCtrl->payInvoice();
			break;
		case 1: // user selects add invoice
			ctrl.databaseCtrl->getProducts();
			ctrl.databaseCtrl->getSalespeople();
			ctrl.guiCtrl->displayCreateInvoice();
			ctrl.databaseCtrl->addOInvoice();
			break;
		}
	case 3: // user selects closed invoices
		ctrl.databaseCtrl->getCInvoices();
		ctrl.guiCtrl->displayCInvoices();
		break;
	case 4: // user selects create product
		ctrl.guiCtrl->displayCreateProduct();
		ctrl.databaseCtrl->createProduct();
		break;
	case 5: // user selects product stats
		ctrl.databaseCtrl->getProducts();
		ctrl.guiCtrl->displayProductStats();
	}
	/*
	*	case user selects product stats:
	*		Get Products from database
	*		Display Product statistics
	*			case user selects specific product
	*				Get product details from database
	*				Display product details
	*					case user selects update product
	*						Display update product
	*						Update product details in database
	*	case user selects commissions:
	*		Get Salespeople from database
	*		Display Salespeople/commission
	*			case user selects add salesperson:
	*				Display Add salesperson
	*				Add salesperson to database
	*			case user selects adjust commission:
	*				Display Set commission rate
	*				Update Commission rates on salespeople in database
	*	case user selects settings:
	* Disconnect Database
	*/

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
	else if (input == "n") {
		return false;
	}
	else {
		cout << "Invalid input" << endl;
		return false;
	}
}