#pragma once
#include "wx\wx.h"
#include"MainMenu_ui.h"
class cApp : public wxApp
{
public:
	cApp();
	~cApp();

private:
	MainMenu_ui* m_frame1 = nullptr;
public:
	virtual bool OnInit();
};