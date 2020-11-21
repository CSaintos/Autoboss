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
		GUICtrl* guiCtrl;
		BusinessCtrl* businessCtrl;
		DatabaseCtrl* databaseCtrl;

		void InstantiateControllers();
		void CloseControllers();
		bool RunTesters();
	};
}