// Salesperson_ui.h
#pragma once

#ifndef GUIHELPER_H
#include "GUIHelper.h"
#endif

#ifndef SALESPERSON_H
#include "Salesperson.h"
#endif

#ifndef SALESPERSON_UI_H
namespace GUILayer {
	class Salesperson_ui {
	private:
	public:
		Salesperson_ui();
		//Salespeople(std::vector<BusinessLayer::Salesperson> salespeople);
		BusinessLayer::Salesperson AddSalesperson();
	};
}
#define SALESPERSON_UI_H
#endif