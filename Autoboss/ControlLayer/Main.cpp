// Main.cpp
#ifndef MAIN_H
#include "Main.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;
using namespace BusinessLayer;
using namespace DatabaseLayer;
using namespace std;

// // // // // // // //
wxIMPLEMENT_APP(Main);
// // // // // // // //

bool Main::OnInit() {
	InstantiateControllers();

	//guiCtrl->test();

	// tester code
	/*if (RunTesters()) {
		CloseControllers();
		return true;
	}*/

	// pseudo code : the story of main (short story)
	// OnAwake()
	string currentDate = businessCtrl->getDate();
	databaseCtrl->setCurrentDate(currentDate);
	string password = databaseCtrl->getPassword();
	// OnStart()
	if (password == "0") {
		guiCtrl->displayCreatePassword();
		databaseCtrl->setPassword();
	}
	else {
		guiCtrl->displayPassword();
	}

	//guiCtrl->displayMainMenu();
	//while (false /*User does not exit*/) {}
	//switch (NULL) {
	//case 0: // user selects warehouse
	//	databaseCtrl->getWarehouses();
	//	guiCtrl->displayWarehouseSelection();
	//	switch (NULL) {
	//	case 0: // user selects a warehouse
	//		databaseCtrl->getInventory(); // get inventory for said warehouse
	//		guiCtrl->displayInventory();
	//		switch (NULL) {
	//		case 0: // user selects add product
	//			guiCtrl->displayAddProduct();
	//			databaseCtrl->addProduct();
	//			break;
	//		}
	//		break;
	//	case 1: // user selects add new warehouse
	//		guiCtrl->displayAddWarehouse();
	//		databaseCtrl->addWarehouse();
	//		break;
	//	}
	//case 1: // user selects warnings
	//	databaseCtrl->getLowStock();
	//	guiCtrl->displayLowStock();
	//	break;
	//case 2: // user selects open invoices
	//	databaseCtrl->getOInvoices();
	//	guiCtrl->displayOInvoices();
	//	switch (NULL) {
	//	case 0: // user selects pay invoice
	//		guiCtrl->displayPayInvoice();
	//		databaseCtrl->payInvoice();
	//		break;
	//	case 1: // user selects add invoice
	//		databaseCtrl->getProducts();
	//		databaseCtrl->getSalespeople();
	//		guiCtrl->displayCreateInvoice();
	//		databaseCtrl->addOInvoice();
	//		break;
	//	}
	//case 3: // user selects closed invoices
	//	databaseCtrl->getCInvoices();
	//	guiCtrl->displayCInvoices();
	//	break;
	//case 4: // user selects create product
	//	guiCtrl->displayCreateProduct();
	//	databaseCtrl->createProduct();
	//	break;
	//case 5: // user selects product stats
	//	databaseCtrl->getProducts();
	//	guiCtrl->displayProductStats();
	//	switch (NULL) {
	//	case 0: // user selects specific product
	//		databaseCtrl->getProductDetails();
	//		guiCtrl->displayProductDetails();
	//		switch (NULL) {
	//		case 0: // user selects update product
	//			guiCtrl->displayUpdateProduct();
	//			databaseCtrl->updateProduct();
	//			break;
	//		}
	//		break;
	//	}
	//	break;
	//case 6: // user selects commissions
	//	databaseCtrl->getSalespeople();
	//	guiCtrl->displaySalespeople();
	//	switch (NULL) {
	//	case 0: // user selects add salesperson
	//		guiCtrl->displayAddSalesperson();
	//		databaseCtrl->addSalesperson();
	//		break;
	//	case 1: // user selects adjust commission
	//		//guiCtrl->displaySetCommissionRate();
	//		databaseCtrl->setCommissionRate();
	//		break;
	//	}
	//	break;
	//case 7: // user selects settings
	//	break;
	//}

	CloseControllers();
	return true;
}

int main(int argc, char* argv[]) {
	Main ctrl;
	ctrl.InstantiateControllers();

	// tester code
	if (ctrl.RunTesters()) {
		ctrl.CloseControllers();
		return 0;
	}

	ctrl.CloseControllers();
	return 0;
}

Main::Main()
{}

Main::~Main()
{}

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