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
		BusinessLayer::Product AddProduct(vector<BusinessLayer::Product> v);
		BusinessLayer::Product CreateProduct();
		void productDetail(BusinessLayer::Product);
		BusinessLayer::Product UpdateProduct(vector<BusinessLayer::Product>);
		int updateSelection();
		string ProductStats(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product ChooseProduct(std::vector<BusinessLayer::Product> x);
	};

}
#define PRODUCT_UI_H
#endif