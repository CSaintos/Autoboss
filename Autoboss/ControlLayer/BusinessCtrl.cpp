// BusinessCtrl.cpp
#include "BusinessCtrl.h"

using namespace BusinessLayer;
using namespace ControlLayer;

BusinessCtrl::BusinessCtrl() : bizHelper(std::make_unique<BIZHelper>())
{}

BusinessCtrl* BusinessCtrl::businessCtrl = nullptr;

BusinessCtrl* BusinessCtrl::GetInstance() {
	if (businessCtrl == nullptr) {
		businessCtrl = new BusinessCtrl();
	}
	return businessCtrl;
}

void BusinessCtrl::test() {
	bizHelper->test();
}