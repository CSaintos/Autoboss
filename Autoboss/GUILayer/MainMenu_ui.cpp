// MainMenu_ui.cpp
#ifndef MAINMENU_UI_H
#include"MainMenu_ui.h"
#endif



using namespace GUILayer;
using namespace std;


MainMenu_ui::MainMenu_ui()
{}

string MainMenu_ui::Display()
{
	string choice;
	
	cout << "******************************************************" << endl;
	cout << "**********************Main Menu***********************" << endl;
	cout << "1. Commission Display		2. Warehouse Selection " << endl;
	cout << "3. Product Statistics		4. Warnings" << endl;
	cout << "5. Create Product		6. Create Product" << endl;
	cout << "7. Update Product		8. Closed Invoice List" << endl;
	cout << "9. Setting		       10. Exit" << endl;
 	cout << "******************************************************" << endl;
	cout << "\n Choice Selection:" << endl;
	cin  >> choice;

	return choice;
	
}
