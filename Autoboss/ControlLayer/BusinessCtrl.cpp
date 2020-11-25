// BusinessCtrl.cpp
#ifndef BUSINESSCTRL_H
#include "BusinessCtrl.h"
#endif

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

std::string BusinessCtrl::getDate() {
	time_t now;
	time(&now);
	tm ltm;
	gmtime_s(&ltm, &now);

	std::stringstream ss;
	ss << 1900 + ltm.tm_year << "-" << 1 + ltm.tm_mon << "-" << ltm.tm_mday;
	return ss.str();
}