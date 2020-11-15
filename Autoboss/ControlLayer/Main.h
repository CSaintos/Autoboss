#pragma once
#include "CTRLHelper.h"
#include "GUICtr.h"
#include "BusinessCtr.h"
#include "DatabaseCtr.h"

namespace ControlLayer {
	class Main {
	public:
		GUICtr* guiCtr;
		BusinessCtr* businessCtr;
		DatabaseCtr* databaseCtr;
		void InstantiateControllers();
	};
}