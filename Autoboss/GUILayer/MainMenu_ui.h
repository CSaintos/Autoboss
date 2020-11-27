// MainMenu_ui.h
#pragma once

#ifndef WX_WX_H
#include <wx/wx.h>
#define WX_WX_H
#endif

#ifndef MAINMENU_H
namespace GUILayer {
	class MainMenu_ui : public wxFrame {
	private:
		DECLARE_EVENT_TABLE();

		enum {
			someButtonID = 001
		};
	public:
		MainMenu_ui();
		// sizers

		// widgets
		wxButton* someButton = nullptr;
		// event handlers
		void OnButtonClicked(wxCommandEvent& evt);
	};
}
#define MAINMENU_H
#endif