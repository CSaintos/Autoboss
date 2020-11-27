// Warehouse_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef WAREHOUSE_UI_H
namespace GUILayer {
	class AddWarehouse : public wxFrame {
	private:
	public:
		AddWarehouse();
		enum {
			EnterNameID = 004,
			AddressID = 005,
			CityID = 006,
			EnterZipCodeID = 007
		};

		// Sizers
		wxBoxSizer* sizerH = nullptr;
		wxBoxSizer* sizerV = nullptr;
		// widgets
		wxButton* addWH = nullptr;
		wxTextCtrl* enterAddressTxtBox = nullptr;
		wxTextCtrl* enterNameTextBox = nullptr;
		wxTextCtrl* enterZipCodeTextBox = nullptr;
		wxTextCtrl* CityTextBox = nullptr;
		wxStaticText* enterAddress = nullptr;
		wxStaticText* enterName = nullptr;
		wxStaticText* enterCity = nullptr;
		wxStaticText* enterZipcode = nullptr;
		wxStaticText* addWareHouse = nullptr;
	};
}
#define WAREHOUSE_UI_H
#endif