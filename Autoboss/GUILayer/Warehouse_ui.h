// Warehouse_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif

#ifndef PRODUCT_H
#include "Product.h"
#endif

#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif


#ifndef WAREHOUSE_UI_H
namespace GUILayer {
	class Warehouse_ui {
	private:
	public:
		Warehouse_ui();
		std::string Warehouse_selection();
		BusinessLayer::Warehouse AddWarehouse();
		BusinessLayer::Warehouse Warehouse_Selection(std::vector<BusinessLayer::Warehouse> x);
	

	};
}
#define WAREHOUSE_UI_H
#endif