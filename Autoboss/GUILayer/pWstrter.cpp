// Password_ui.cpp
#ifndef PWSTRTER_H
#include"pWstrter.h"
#endif

using namespace GUILayer;

wxIMPLEMENT_APP(pWstrter);
pWstrter::pWstrter()
{}

pWstrter::~pWstrter() {}

bool pWstrter::OnInit()
{
	m_frame1 = new Password_ui();
	m_frame1->Show();
	return true;
}