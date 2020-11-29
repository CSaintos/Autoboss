// Warehouse_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

#ifndef WAREHOUSE_UI_H
namespace GUILayer {
	class Warehouse_ui {
	private:
	public:
		Warehouse_ui();
		void Warehouse_selection(std::vector<int> Warehouses);
	

	};
}
#define WAREHOUSE_UI_H
#endif