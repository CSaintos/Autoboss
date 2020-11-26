// Password_ui.h
#pragma once
#include "wx/wx.h"
#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef PASSWORD_UI_H
namespace GUILayer {
	class EnterPassword : public wxFrame {
	private:
	public:
		EnterPassword();
		~EnterPassword();

		wxButton* m_btn1 = nullptr;
		wxTextCtrl* m_txt1 = nullptr;
		//wxListBox* m_list1 = nullptr;
	};
	class CreatePassword : public wxFrame {
	private:
	public:
		CreatePassword();
		~CreatePassword();
	};
}
#define PASSWORD_UI_H
#endif