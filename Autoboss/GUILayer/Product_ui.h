// Product_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
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

#ifndef PRODUCT_UI_H
namespace GUILayer {
	class Product_ui {
	private:
	public:
		Product_ui();

		BusinessLayer::Product StockInventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product AddInventory(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product CreateProduct();
		void productDetail(BusinessLayer::Product);
		BusinessLayer::Product UpdateProduct(std::vector<BusinessLayer::Product>);
		int updateSelection();
		std::string ProductStats(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product ChooseProduct(std::vector<BusinessLayer::Product> x);
		void LowStock(std::vector<BusinessLayer::Product> x);
		std::string Inventory(std::vector <BusinessLayer::Product> x);
	};

}
#define PRODUCT_UI_H
#endif