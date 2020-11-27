// Password_ui.cpp
#ifndef PASSWORD_UI_H
#include"Password_ui.h"
#endif

using namespace GUILayer;

EnterPassword::EnterPassword() : wxFrame(nullptr, wxID_ANY, "AutoBoss - Password")
{
	m_btn1 = new wxButton(this, wxID_ANY, "Enter", wxPoint(40, 40), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1= new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300,)
}

BEGIN_EVENT_TABLE(CreatePassword, wxFrame)
	EVT_TEXT(EnterPasswordID, CreatePassword::OnEnterPassword)
	EVT_TEXT(RenterPasswordID, CreatePassword::OnRenterPassword)
	EVT_BUTTON(CreatePasswordID, CreatePassword::OnCreatePassword)
END_EVENT_TABLE()

CreatePassword::CreatePassword() : wxFrame(nullptr, wxID_ANY, "AutoBoss - CreatePassword", wxPoint(400, 150), wxSize(800, 600))
{
	//Destroy();
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	sizerV = new wxBoxSizer(wxVERTICAL);

	createYourPassword = new wxStaticText(this, wxID_ANY, "Create your password");
	sizerH->Add(createYourPassword, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//enterpassword
	enterPassword = new wxStaticText(this, wxID_ANY, "Enter Password:");
	sizerH->Add(enterPassword, 1, wxEXPAND | wxLEFT, 100);
	enterPasswordTextBox = new wxTextCtrl(this, EnterPasswordID, "");
	sizerH->Add(enterPasswordTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//renter
	renterPassword = new wxStaticText(this, wxID_ANY, "Re-enter Password:");
	sizerH->Add(renterPassword, 1, wxEXPAND | wxLEFT, 100);
	renterPasswordTextBox = new wxTextCtrl(this, RenterPasswordID, "");
	sizerH->Add(renterPasswordTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
<<<<<<< Updated upstream
	createPasswordButton = new wxButton(this, CreatePasswordID, "Create Password");
	sizerH->Add(createPasswordButton, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
=======
	//button
	createPassword = new wxButton(this, CreatePasswordID, "Create Password");
	sizerH->Add(createPassword, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
>>>>>>> Stashed changes
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 30);

	SetSizer(sizerV);
}

//void CreatePassword::displayCreatePassword() {
//	Connect(EnterPasswordID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CreatePassword::OnEnterPassword));
//	Connect(RenterPasswordID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CreatePassword::OnRenterPassword));
//	Connect(CreatePasswordID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CreatePassword::OnCreatePassword));
//	Show();
//}

void CreatePassword::OnEnterPassword(wxCommandEvent& event) {
	passwordEntry = enterPasswordTextBox->GetLineText(0);
}

void CreatePassword::OnRenterPassword(wxCommandEvent& event) {
	passwordRentry = renterPasswordTextBox->GetLineText(0);
}

void CreatePassword::OnCreatePassword(wxCommandEvent& event) {
	// Close the frame
	if (passwordEntry == passwordRentry) {
		MainMenu_ui* mainmenu = new MainMenu_ui();
		mainmenu->Show();
		Close();
	}
}

//CreatePassword::~CreatePassword()
//{
//	delete(createPassword);
//	delete(enterPasswordTextBox);
//	delete(renterPasswordTextBox);
//	delete(enterPassword);
//	delete(renterPassword);
//	delete(createYourPassword);
//	//delete(sizerH);
//	//delete(sizerV);
//	this->Close();
//}