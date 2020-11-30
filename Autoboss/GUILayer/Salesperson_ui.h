// Salesperson_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif

#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif

#ifndef SALESPERSON_UI_H
namespace GUILayer {
	class Salesperson_ui {
	private:
	public:
		Salesperson_ui();
		BusinessLayer::Salesperson AddSalesperson();
		void SetCommission(BusinessLayer::Salesperson x);
		string Salespeople(std::vector<BusinessLayer::Salesperson>x);
	};
}
#define SALESPERSON_UI_H
#endif