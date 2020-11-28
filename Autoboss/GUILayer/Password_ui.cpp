// Password_ui.cpp
#ifndef PASSWORD_UI_H
#include"Password_ui.h"
#endif

using namespace GUILayer;
using namespace std;

Password_ui::Password_ui()
{}

string Password_ui::CreatePassword() {
	do {
		cout << "Please create Password" << endl;
		cin >> passwordEntry;
		cout << "Please re-enter your password" << endl;
		cin >> passwordRentry;
		if (passwordEntry != passwordRentry) cout << "The passwords are not the same" << endl;
	} while (passwordEntry != passwordRentry);
	return passwordEntry;
}

void Password_ui::EnterPassword(string passwordValidation) {
	while (passwordEntry != passwordValidation) {
		cout << "Please enter your password" << endl;
		cin >> passwordEntry;
		if (passwordEntry != passwordValidation) cout << "The password you entered is incorrect" << endl;
	}
}