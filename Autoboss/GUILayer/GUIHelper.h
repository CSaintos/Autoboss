#pragma once

#ifndef MAINMENU_H
#include "MainMenu_ui.h"
#endif

#ifndef WX_WX_H
#include <wx/wx.h>
#define WX_WX_H
#endif
#ifndef MEMORY
#include <memory>
#define MEMORY
#endif

#ifndef GUIHELPER_H
namespace GUILayer {
	class GUIHelper : public wxApp {
	private:
		//MainMenu_ui * mainMenuFrame = nullptr;
	public:
		GUIHelper();
		~GUIHelper();

		virtual bool OnInit();
		void test();
	};
}
#define GUIHELPER_H
#endif