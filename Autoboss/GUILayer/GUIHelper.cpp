// GUIHelper.cpp
#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

using namespace GUILayer;

wxIMPLEMENT_APP(GUIHelper);

GUIHelper::GUIHelper()
{}

GUIHelper::~GUIHelper()
{}

bool GUIHelper::OnInit() { // Windows Main. Console main is in control layer, for now.
    MainMenu_ui *mainMenuFrame = new MainMenu_ui();
    mainMenuFrame->Show();
    return true;
}

void GUIHelper::test() {
    
}