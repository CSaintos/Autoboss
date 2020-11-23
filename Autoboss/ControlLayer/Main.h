// Main.h
#ifndef CTRLHELPER_H
#include "CTRLHelper.h"
#endif
#ifndef GUICTRL_H
#include "GUICtrl.h"
#endif
#ifndef BUSINESSCTRL_H
#include "BusinessCtrl.h"
#endif
#ifndef DATABASECTRL_H
#include "DatabaseCtrl.h"
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
//#include <string>

#ifndef MAIN_H
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
#define MAIN_H
#endif