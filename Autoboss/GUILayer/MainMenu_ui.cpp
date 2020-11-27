// MainMenu_ui.cpp
#ifndef MAINMENU_UI_H
#include"MainMenu_ui.h"
#endif

using namespace GUILayer;

BEGIN_EVENT_TABLE(MainMenu_ui, wxFrame)
	EVT_BUTTON(SomeButtonID, OnButtonClicked)
END_EVENT_TABLE()

MainMenu_ui::MainMenu_ui() : wxFrame(nullptr, wxID_ANY, "Main Menu")
{
	//Destroy();
	someButton = new wxButton(this, SomeButtonID, "Some Button :)");
}

void MainMenu_ui::OnButtonClicked(wxCommandEvent& evt) {
	Close();
}
