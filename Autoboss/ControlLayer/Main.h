#pragma once
#include "CTRLHelper.h"
#include "GUICtr.h"
#include "BusinessCtr.h"
#include "DatabaseCtr.h"

namespace ControlLayer {
	class Main {
	protected:
	public:
		GUICtr* guiCtr;
		BusinessCtr* businessCtr;
		DatabaseCtr* databaseCtr;

		void InstantiateControllers();
		void CloseControllers();
	};
}