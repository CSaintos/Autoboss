// Password_ui.h
#pragma once

#ifndef PASSWORD_UI_H
#include"Password_ui.h"
#endif
#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif
#ifndef WX_WX_H
#include <wx/wx.h>
#define WX_WX_H
#endif

#ifndef PWSTRTER_H
namespace GUILayer {
	class pWstrter : public wxApp {
	private:
	public:
		pWstrter();
		~pWstrter();
	private:
		Password_ui* m_frame1 = nullptr;
	public :
		virtual bool OnInit();
		};
};
#define PWSTRTER_H
#endif