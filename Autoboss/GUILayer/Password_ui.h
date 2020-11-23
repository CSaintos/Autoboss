// Password_ui.h
#pragma once
#include "wx/wx.h"
#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef PASSWORD_UI_H
namespace GUILayer {
	class Password_ui : public wxFrame{
	private:
	public:
		Password_ui();
		~Password_ui();
	public :
		wxButton* m_btn1 = nullptr;
		wxTextCtrl* m_txt1 = nullptr;
		//wxListBox* m_list1 = nullptr;
		};
};
#define PASSWORD_UI_H
#endif