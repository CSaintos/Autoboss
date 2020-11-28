// GUICtrl.cpp
#ifndef GUICTRL_H
#include "GUICtrl.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;

GUICtrl::GUICtrl() : 
	guiHelper(std::make_unique<GUIHelper>()),
	invoiceUI(std::make_unique<Invoice_ui>()),
	mainmenuUI(std::make_unique<MainMenu_ui>()),
	passwordUI(std::make_unique<Password_ui>()),
	salespersonUI(std::make_unique<Salesperson_ui>()),
	warehouseUI(std::make_unique<Warehouse_ui>())
{}

GUICtrl* GUICtrl::guiCtrl = nullptr;

GUICtrl* GUICtrl::GetInstance() {
	if (guiCtrl == nullptr) {
		guiCtrl = new GUICtrl();
	}
	return guiCtrl;
}

void GUICtrl::test() {
	guiHelper->test();
}

std::string GUICtrl::CreatePassword() {
	return passwordUI->CreatePassword();
}

void GUICtrl::EnterPassword(std::string password) {
	passwordUI->EnterPassword(password);
}

std::string GUICtrl::MainMenu() {
	return "0";
}
