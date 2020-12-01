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

#ifndef ALGORITHM
#include <algorithm>
#define ALGORITHM
#endif


#ifndef WAREHOUSE_UI_H
namespace GUILayer {
	class Warehouse_ui {
	private:
	public:
		Warehouse_ui();

		std::string WarehouseSelection(std::vector<BusinessLayer::Warehouse>);
		BusinessLayer::Warehouse AddWarehouse();
		BusinessLayer::Warehouse SelectWarehouse(std::vector<BusinessLayer::Warehouse>);
	};
}
#define WAREHOUSE_UI_H
#endif