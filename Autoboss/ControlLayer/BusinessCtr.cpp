#include "BusinessCtr.h"

//using namespace BusinessLayer;
using namespace ControlLayer;

BusinessCtr::BusinessCtr() {}

BusinessCtr* BusinessCtr::businessCtr = nullptr;

BusinessCtr* BusinessCtr::GetInstance() {
	if (businessCtr == nullptr) {
		businessCtr = new BusinessCtr();
	}
	return businessCtr;
}