// MainMenu_ui.cpp
#ifndef MAINMENU_UI_H
#include"MainMenu_ui.h"
#endif

using namespace GUILayer;
wxBEGIN_EVENT_TABLE(MainMenu_ui, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()
MainMenu_ui::MainMenu_ui() : wxFrame(nullptr, wxID_ANY, "BetaTest-WareHouse!", wxPoint(30, 30), wxSize(800, 600))
{
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainMenu_ui::OnButtonClicked, this);
		}
	}
	//btn[0]

	this->SetSizer(grid);
	grid->Layout();
}





MainMenu_ui::~MainMenu_ui()
{}

void MainMenu_ui::OnButtonClicked(wxCommandEvent& evt)
{

}
