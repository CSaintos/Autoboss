#include "GUICtrl.h"

//using namespace GUILayer;
using namespace ControlLayer;

GUICtr::GUICtr() {}

GUICtr* GUICtr::guiCtr = nullptr;

GUICtr* GUICtr::GetInstance() {
	if (guiCtr == nullptr) {
		guiCtr = new GUICtr();
	}
	return guiCtr;
}
