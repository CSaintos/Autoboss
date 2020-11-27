// Warehouse_ui.cpp
#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif

using namespace GUILayer;

AddWarehouse::AddWarehouse() : wxFrame(nullptr, wxID_ANY, "AutoBoss - Warehouse")
{
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	sizerV = new wxBoxSizer(wxVERTICAL);

	addWareHouse = new wxStaticText(this, wxID_ANY, "Add WareHouse!");
	sizerH->Add(addWareHouse, 1, wxEXPAND | wxLEFT | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 4O);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//Entering name
	enterName = new wxStaticText(this, wxID_ANY, "Enter Name:");
	sizerH->Add(enterName, 1, wxEXPAND | wxLEFT, 400);
	enterNameTxtBox = new wxTextCtrl(this, EnterNameID, "");
	sizerH->Add(enterNameTxtBox, 1, wxEXPAND | wxRIGHT, 300);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//Entering address
	enterAddress = new wxStaticText(this, wxID_ANY, "Address: ");
	sizerH->Add(enterAddress, 1, wxEXPAND | wxLEFT, 100);
	enterAddressTxtBox = new wxTextCtrl(this, AddressID, "");
	sizerH->Add(enterAddressTxtBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//Enter City
	enterCity = new wxStaticText(this, wxID_ANY, "City:");
	sizerH->(enterCity, 1, wxEXPAND | wxLEFT, 100);
	enterCityTextBox = new wxTextCtrl(this, CityID, "");
	sizerH->Add(enterCityTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//Enter zipcode
	enterZipcode = new wxStaticText(this, wxID_ANY, "Enter ZipCode:");
	sizerH->Add(enterZipCode, 1, wxEXPAND | wxLEFT, 100);
	enterZipCodeTextBox = new wxTextCtrl(this, EnterZipCodeID, "");
	sizerH->Add(enterZipcodeTextBox, 1, wxEXPAND | wxRIGHT, 100);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 40);
	sizerH = new wxBoxSizer(wxHORIZONTAL);
	//Button
	addWH = new wxButton(this, AddWH_ID, "ADD WAREHOUSE");
	sizerH->Add(addWH, 1, wxEXPAND | wxLEFT | wxRIGHT, 200);
	sizerV->Add(sizerH, 1, wxEXPAND | wxTOP | wxBOTTOM, 30);

	SetSizer(sizerV);
}