// GUICtrl.cpp
#ifndef GUICTRL_H
#include "GUICtrl.h"
#endif

using namespace GUILayer;
using namespace ControlLayer;

GUICtrl::GUICtrl() : guiHelper(std::make_unique<GUIHelper>()), createPassword(new CreatePassword())
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
	createPassword->Connect(createPassword->EnterPasswordID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CreatePassword::OnEnterPassword));
	createPassword->Connect(createPassword->RenterPasswordID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CreatePassword::OnRenterPassword));
	createPassword->Connect(createPassword->CreatePasswordID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CreatePassword::OnCreatePassword));
	createPassword->Show();
}
