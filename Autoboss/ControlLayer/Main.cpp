#include "Main.h"

using namespace GUILayer;
using namespace ControlLayer;
using namespace BusinessLayer;
using namespace DatabaseLayer;

int main(int argc, char* argv[]) {
	Main ctrl;
	ctrl.InstantiateControllers();

	ctrl.databaseCtrl->test();
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
			ctrl.
		}
	}
	/*
	* while user does not exit:
	*	case user selects warehouse:
	*		Get warehouses from database
	*		Display warehouse selection
	*			case user selects select warehouse:
	*				Get inventory for said warehouse from database
	*				Display Inventory
	*					case user selects add product:
	*						Display Add Product
	*						Add product to database
	*			case user selects add new warehouse:
	*				Display Add Warehouse
	*				Add warehouse to database
	*	case user selects warnings:
	*		Get products with quantityInStock <= 5 from database
	*		Display Products on Low Stock
	*	case user selects oInvoice:
	*		Get open invoices from database
	*		Display open invoice list
	*			case user selects pay invoice
	*				Display Pay invoice
	*				Update invoice in database
	*			case user selects add invoice
	*				Get Products from database
	*				Get salespeople from database
	*				Display Create invoice
	*				Add open invoice to database
	*	case user selects cInvoice:
	*		Get closed invoices from database
	*		Display closed invoice list
	*	case user selects create product:
	*		Display Create product
	*		Add product to the database
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
	guiCtrl = GUICtr::GetInstance();
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