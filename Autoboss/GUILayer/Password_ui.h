// Password_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif
#ifndef MAINMENU_UI_H
#include "MainMenu_ui.h"
#endif

#ifndef WX_WX_H
#include <wx/wx.h>
#define WX_WXH
#endif
#ifndef STRING
#include <string>
#define STRING
#endif

#ifndef PASSWORD_UI_H
namespace GUILayer {
	class EnterPassword : public wxFrame {
	private:
	public:
		EnterPassword();
		// widgets
		wxButton* m_btn1 = nullptr;
		wxTextCtrl* m_txt1 = nullptr;
		//wxListBox* m_list1 = nullptr;
	};
	class CreatePassword : public wxFrame {
	private:
		//DECLARE_EVENT_TABLE();
		
		std::string passwordEntry = "";
		std::string passwordRentry = "";
	public:
		CreatePassword();

		enum {
			CreatePasswordID = 001,
			EnterPasswordID = 002,
			RenterPasswordID = 003
		};

		// Sizers
		wxBoxSizer* sizerH = nullptr;
		wxBoxSizer* sizerV = nullptr;
		// widgets
		wxButton* createPassword = nullptr;
		wxTextCtrl* renterPasswordTextBox = nullptr;
		wxTextCtrl* enterPasswordTextBox = nullptr;
		wxStaticText* createYourPassword = nullptr;
		wxStaticText* enterPassword = nullptr;
		wxStaticText* renterPassword = nullptr;
		// event handlers
		void OnEnterPassword(wxCommandEvent& event);
		void OnRenterPassword(wxCommandEvent& event);
		void OnCreatePassword(wxCommandEvent& event);
	};
}
#define PASSWORD_UI_H
#endif