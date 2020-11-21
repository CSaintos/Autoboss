#include "GUICtrl.h"

using namespace GUILayer;
using namespace ControlLayer;

GUICtrl::GUICtrl() : guiHelper(std::make_unique<GUIHelper>())
{}

GUICtrl* GUICtrl::guiCtrl = nullptr;

GUICtrl* GUICtrl::GetInstance() {
	if (guiCtrl == nullptr) {
		guiCtrl = new GUICtrl();
	}
	return guiCtrl;
}

void GUICtrl::test() {
	guiHelper->test();
}
