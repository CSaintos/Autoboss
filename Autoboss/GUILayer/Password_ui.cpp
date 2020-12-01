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
		cout << "******************************************************" << endl;
		cout << "**********************AUTOBOSS***********************" << endl;
		cout << "Please create Password" << endl;
		getline(cin, passwordEntry);
		cout << "******************************************************" << endl;
		cout << "Please re-enter your password" << endl;
		getline(cin, passwordRentry);
		if (passwordEntry != passwordRentry) cout << "The passwords are not the same" << endl;
	} while (passwordEntry != passwordRentry);
	cout << endl;
	return passwordEntry;
}

void Password_ui::EnterPassword(string passwordValidation) {
	while (passwordEntry != passwordValidation) {
		cout << "******************************************************" << endl;
		cout << "**********************AUTOBOSS************************" << endl;
		cout << "Please enter your password:" << endl;
		getline(cin, passwordEntry);
		if (passwordEntry != passwordValidation) cout << "The password you entered is incorrect" << endl;
	}
	cout << endl;
}