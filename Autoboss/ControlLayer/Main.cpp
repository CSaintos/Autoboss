#include "Main.h"

using namespace GUILayer;
using namespace ControlLayer;
using namespace BusinessLayer;
using namespace DatabaseLayer;

int main(int argc, char* argv[]) {
	Main controller;
	controller.InstantiateControllers();

	return 0;
}

void Main::InstantiateControllers() {
	guiCtr = GUICtr::GetInstance();
	businessCtr = BusinessCtr::GetInstance();
	databaseCtr = DatabaseCtr::GetInstance();
}