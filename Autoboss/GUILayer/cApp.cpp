#include "cApp.h"
#include "MainMenu_ui.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp()
{}

cApp::~cApp()
{

}
bool cApp::OnInit()
{
	m_frame1 = new MainMenu_ui();
	m_frame1->Show();
	return true;
}
