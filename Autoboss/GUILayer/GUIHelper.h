#pragma once

#ifndef MAINMENU_H
#include "MainMenu_ui.h"
#endif

#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif

#ifndef MEMORY
#include <memory>
#define MEMORY
#endif
#ifndef IOMANIP
#include <iomanip>
#define IOMANIP
#endif


#ifndef GUIHELPER_H
namespace GUILayer {
	class GUIHelper {
	private:
	public:
		GUIHelper();

		void test();
	};
}
#define GUIHELPER_H
#endif