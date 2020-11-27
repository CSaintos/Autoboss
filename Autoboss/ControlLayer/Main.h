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

#ifndef WX_WX_H
#include <wx/wx.h>
#define WX_WX_H
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
//#include <string>

#ifndef MAIN_H
namespace ControlLayer {
	class Main : public wxApp {
	public:
		Main();
		~Main();

		virtual bool OnInit();

		GUICtrl* guiCtrl = nullptr;
		BusinessCtrl* businessCtrl = nullptr;
		DatabaseCtrl* databaseCtrl = nullptr;

		void InstantiateControllers();
		void CloseControllers();
		bool RunTesters();
	};
}
#define MAIN_H
#endif