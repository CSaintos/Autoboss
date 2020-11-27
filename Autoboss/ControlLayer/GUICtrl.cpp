// GUICtrl.cpp
#ifndef GUICTRL_H
#include "GUICtrl.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;

GUICtrl::GUICtrl() : guiHelper(std::make_unique<GUIHelper>()), 
	createPassword(new CreatePassword())//,
	//mainmenu(new MainMenu_ui())
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

void GUICtrl::displayCreatePassword() {
	createPassword->Show();
}

//void CreatePassword::OnEnterPassword(wxCommandEvent& event) {
//	passwordEntry = enterPasswordTextBox->GetLineText(0);
//}
//
//void CreatePassword::OnRenterPassword(wxCommandEvent& event) {
//	passwordRentry = renterPasswordTextBox->GetLineText(0);
//}
//
//void CreatePassword::OnCreatePassword(wxCommandEvent& event) {
//	if (passwordEntry == passwordRentry) {
//		Close();
//	}
//}

//void MainMenu_ui::displayMainMenu() {
//	Connect(SomeButtonID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainMenu_ui::OnButtonClicked));
//	Show();
//}
