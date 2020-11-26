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

EnterPassword::~EnterPassword()
{}

CreatePassword::CreatePassword() : wxFrame(nullptr, wxID_ANY, "AutoBoss - CreatePassword", wxPoint(400, 150), wxSize(800, 600))
{
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	sizerV = new wxBoxSizer(wxVERTICAL);

	createYourPassword = new wxStaticText(this, wxID_ANY, "Create your password");
	sizerH->Add(createYourPassword, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	enterPassword = new wxStaticText(this, wxID_ANY, "Enter Password:");
	sizerH->Add(enterPassword, 1, wxEXPAND | wxLEFT, 100);
	enterPasswordTextBox = new wxTextCtrl(this, wxID_ANY, "");
	sizerH->Add(enterPasswordTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	renterPassword = new wxStaticText(this, wxID_ANY, "Re-enter Password:");
	sizerH->Add(renterPassword, 1, wxEXPAND | wxLEFT, 100);
	renterPasswordTextBox = new wxTextCtrl(this, wxID_ANY, "");
	sizerH->Add(renterPasswordTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	createPassword = new wxButton(this, wxID_ANY, "Create Password");
	sizerH->Add(createPassword, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 30);

	SetSizer(sizerV);
}

CreatePassword::~CreatePassword()
{
	delete(createPassword);
	delete(enterPasswordTextBox);
	delete(renterPasswordTextBox);
	delete(enterPassword);
	delete(renterPassword);
	delete(createYourPassword);
	//delete(sizerH);
	//delete(sizerV);
	this->Close();
}