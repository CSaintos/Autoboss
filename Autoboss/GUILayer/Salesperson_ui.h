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
		BusinessLayer::Salesperson AddSalesperson();
		void CommissionUpdate(BusinessLayer::Salesperson);
	};
}
#define SALESPERSON_UI_H
#endif