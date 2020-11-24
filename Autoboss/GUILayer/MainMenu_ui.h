// MainMenu_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef MAINMENU_H
namespace GUILayer {
	class MainMenu_ui:public wxFrame {
	private:
	public:
		MainMenu_ui();
		~MainMenu_ui();

	public:
		int nFieldWidth = 3;
		int nFieldHeight = 3;
		wxButton** btn;


		void OnButtonClicked(wxCommandEvent& evt);

		wxDECLARE_EVENT_TABLE();
	};
};
#define MAINMENU_H
#endif