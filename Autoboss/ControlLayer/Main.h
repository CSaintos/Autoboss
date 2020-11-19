#pragma once
#include "CTRLHelper.h"
#include "GUICtrl.h"
#include "BusinessCtrl.h"
#include "DatabaseCtrl.h"

namespace ControlLayer {
	class Main {
	protected:
	public:
		GUICtr* guiCtrl;
		BusinessCtrl* businessCtrl;
		DatabaseCtrl* databaseCtrl;

		void InstantiateControllers();
		void CloseControllers();
	};
}