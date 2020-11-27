// Password_ui.h
#pragma once

#ifndef MAINMENU_UI_H
#include "MainMenu_ui.h"
#endif

#ifndef STRING
#include <string>
#define STRING
#endif
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif

#ifndef PASSWORD_UI_H
namespace GUILayer {
	class Password_ui {
	private:
	public:
		Password_ui();

		std::string passwordEntry = "";
		std::string passwordRentry = "";

		std::string CreatePassword();
		void EnterPassword(std::string passwordValidation);
	};
}
#define PASSWORD_UI_H
#endif