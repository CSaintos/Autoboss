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
		BusinessLayer::Product AddProduct(std::vector<BusinessLayer::Product>);
		BusinessLayer::Product CreateProduct();
		void productDetail(BusinessLayer::Product);
		BusinessLayer::Product UpdateProduct(std::vector<BusinessLayer::Product>);
		int UpdateSelection();
	};

}
#define PRODUCT_UI_H
#endif