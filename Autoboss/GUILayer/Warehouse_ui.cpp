// Warehouse_ui.cpp
#ifndef WAREHOUSE_UI_H
#include "Warehouse_ui.h"
#endif

using namespace GUILayer;
using namespace std;
Warehouse_ui::Warehouse_ui()
{}
void Warehouse_ui::Warehouse_selection()
{
	cout << "******************************************************" << endl;
	cout << "**************Warehouse Selection Menu****************" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "WareHouse "<< (i+1) << endl;
	}
	cout << "Choose your warehouse:" << endl;
}