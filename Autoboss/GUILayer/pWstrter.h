// Password_ui.h
#pragma once
#include "wx/wx.h"
#include"Password_ui.h"
#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif


#ifndef PWSTRTER_H
namespace GUILayer {
	class pWstrter:public wxApp {
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