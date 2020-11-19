#include "BusinessCtrl.h"

//using namespace BusinessLayer;
using namespace ControlLayer;

BusinessCtrl::BusinessCtrl() {}

BusinessCtrl* BusinessCtrl::businessCtrl = nullptr;

BusinessCtrl* BusinessCtrl::GetInstance() {
	if (businessCtrl == nullptr) {
		businessCtrl = new BusinessCtrl();
	}
	return businessCtrl;
}