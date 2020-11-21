#pragma once
#include "CTRLHelper.h"
#include "GUICtrl.h"
#include "BusinessCtrl.h"
#include "DatabaseCtrl.h"

#include <iostream>
#include <string>

namespace ControlLayer {
	class Main {
	protected:
	public:
		GUICtr* guiCtrl;
		BusinessCtrl* businessCtrl;
		DatabaseCtrl* databaseCtrl;

		void InstantiateControllers();
		void CloseControllers();
		void RunTesters();
	};
}