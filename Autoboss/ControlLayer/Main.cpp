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
	*			case user selects add new warehouse:
	*			case user selects back:
	*				return
	*	case user selects warnings:
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
	guiCtr = GUICtr::GetInstance();
	businessCtrl = BusinessCtrl::GetInstance();
	databaseCtr = DatabaseCtr::GetInstance();

	databaseCtr->openDB();
}

void Main::CloseControllers() {
	databaseCtr->closeDB();

	delete(guiCtr);
	delete(businessCtrl);
	delete(databaseCtr);
}