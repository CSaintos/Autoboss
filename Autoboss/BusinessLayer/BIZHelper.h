// BIZHelper.h
#pragma once

#ifndef WAREHOUSE_H
#include "Warehouse.h"
#endif
#ifndef PRODUCT_H
#include "Product.h"
#endif

#ifndef STRING
#include <string>
#define STRING
#endif
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif

#ifndef BIZHELPER_H
namespace BusinessLayer {
	class BIZHelper {
	private:
	public:
		BIZHelper();
		void test();
	};
}
#define BIZHELPER_H
#endif
