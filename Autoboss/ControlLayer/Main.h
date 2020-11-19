#pragma once
#include "CTRLHelper.h"
#include "GUICtr.h"
#include "BusinessCtrl.h"
#include "DatabaseCtr.h"

namespace ControlLayer {
	class Main {
	protected:
	public:
		GUICtr* guiCtr;
		BusinessCtrl* businessCtrl;
		DatabaseCtr* databaseCtr;

		void InstantiateControllers();
		void CloseControllers();
	};
}