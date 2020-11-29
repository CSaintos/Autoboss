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
		if (choice == "1") { // commission
			do {
				vector<Salesperson> salespeople = ctrl.databaseCtrl->getSalespeople();
				choice = ctrl.guiCtrl->Salespeople(salespeople);
				if (choice == "0") { // set commission rate
					Salesperson salesperson = ctrl.guiCtrl->SetCommission(salespeople);
					ctrl.databaseCtrl->setCommissionRate(salesperson);
				} else if (choice == "0") { // add salesperson
					Salesperson salesperson = ctrl.guiCtrl->AddSalesperson();
					ctrl.databaseCtrl->addSalesperson(salesperson);
				}
			} while (choice != "0"); // back to main menu
		} else if (choice == "2") { // warehouse selection
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
		} else if (choice == "3") { // product statistics
			vector<Product> products = ctrl.databaseCtrl->getProducts();
			do {
				choice = ctrl.guiCtrl->ProductStats(products);
				if (choice == "0") { // product details
					Product product = ctrl.guiCtrl->ChooseProduct(products);
					product = ctrl.databaseCtrl->getProductDetails(product);
					ctrl.guiCtrl->ProductDetails(product);
				}
			} while (choice != "0"); // back to main menu
		} else if (choice == "4") { // warnings
			vector<Product> products = ctrl.databaseCtrl->getLowStock();
			ctrl.guiCtrl->LowStock(products);
		} else if (choice == "5") { // create product
			Product product = ctrl.guiCtrl->CreateProduct();
			ctrl.databaseCtrl->createProduct(product);
		} else if (choice == "6") { // open invoice list
			do {
				vector<Invoice> openInvoices = ctrl.databaseCtrl->getOInvoices();
				choice = ctrl.guiCtrl->OInvoices(openInvoices);
				if (choice == "0") { // open invoice details
					Invoice openInvoice = ctrl.guiCtrl->ChooseOInvoice(openInvoices);
					openInvoice = ctrl.databaseCtrl->getOInvoiceDetails(openInvoice);
					ctrl.guiCtrl->OInvoiceDetails(openInvoice);
				} else if (choice == "0") { // pay invoice
					Invoice openInvoice = ctrl.guiCtrl->PayInvoice(openInvoices);
					ctrl.databaseCtrl->payInvoice(openInvoice);
				} else if (choice == "0") { // create invoice
					Invoice openInvoice = ctrl.guiCtrl->CreateInvoice();
					ctrl.databaseCtrl->addOInvoice(openInvoice);
				}
			} while (choice != "0");
		} else if (choice == "7") { // update product
			vector<Product> products = ctrl.databaseCtrl->getProducts();
			Product product = ctrl.guiCtrl->UpdateProduct(products);
			ctrl.databaseCtrl->updateProduct(product);
		} else if (choice == "8") { // closed invoice list
			vector<Invoice> closedInvoices = ctrl.databaseCtrl->getCInvoices();
			do {
				choice = ctrl.guiCtrl->CInvoices(closedInvoices);
				if (choice == "0") { // closed invoice details
					Invoice closedInvoice = ctrl.guiCtrl->ChooseCInvoice(closedInvoices);
					closedInvoice = ctrl.databaseCtrl->getCInvoiceDetails(closedInvoice);
					ctrl.guiCtrl->CInvoiceDetails(closedInvoice);
				}
			} while (choice != "0");
		} else if (choice == "9") { // settings

		}
	} while (choice != "10"); // quit

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