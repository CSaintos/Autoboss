// MainMenu_ui.cpp
#ifndef MAINMENU_UI_H
#include"MainMenu_ui.h"
#endif

using namespace GUILayer;

BEGIN_EVENT_TABLE(MainMenu_ui, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
END_EVENT_TABLE()

MainMenu_ui::MainMenu_ui() : wxFrame(nullptr, wxID_ANY, "Main Menu")
{
	
}

//
//void MainMenu_ui::OnButtonClicked(wxCommandEvent& evt)
//{
//
//}
