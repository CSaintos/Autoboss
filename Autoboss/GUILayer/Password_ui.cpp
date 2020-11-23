// Password_ui.cpp
#ifndef PASSWORD_UI_H
#include"Password_ui.h"
#endif

using namespace GUILayer;

Password_ui::Password_ui() : wxFrame(nullptr, wxID_ANY, "AutoBoss - Password")
{
	m_btn1 = new wxButton(this, wxID_ANY, "Enter", wxPoint(40, 40), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1= new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300,)
}

Password_ui::~Password_ui()
{

}