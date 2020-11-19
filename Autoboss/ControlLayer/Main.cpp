#include "Main.h"

using namespace GUILayer;
using namespace ControlLayer;
using namespace BusinessLayer;
using namespace DatabaseLayer;

int main(int argc, char* argv[]) {
	Main controller;

	controller.InstantiateControllers();

	// sudo code : the story of main (short story)
	/*
	* Connect to database //prequel
	* Get date
	* apply date to database
	* Get password from database
	* if (password is null):
	*	Display create password window
	*	Store password in database
	* else:
	*	Display enter password window
	* Display main menu
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
	*			case user selects back:
	*				return
	*	case user selects warnings:
	*		Get products with quantityInStock <= 5 from database
	*		
	*	case user selects oInvoice:
	*	case user selects cInvoice:
	*	case user selects create product:
	*	case user selects product stats:
	*	case user selects commissions:
	*	case user selects settings:
	* Disconnect Database
	*/

	controller.CloseControllers();

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