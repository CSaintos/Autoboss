#pragma once

#ifndef MAINMENU_UI_H
#include "MainMenu_ui.h"
#endif

#ifndef WX_WX_H
#include <wx\wx.h>
#define WX_WX_H
#endif

#ifndef CAPP_H
namespace GUILayer {
	class cApp //: public wxApp
	{
	public:
		cApp();
		~cApp();

	private:
		//MainMenu_ui* m_frame1 = nullptr;
	public:
		//virtual bool OnInit();
	};
}
#define CAPP_H
#endif