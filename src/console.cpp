#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "console.hpp"

using json = nlohmann::json;

console::console() {
	std::ifstream file("resources/locale.json");
	json localization;

	if (file.is_open()) {
		file >> localization;

		for (auto& lang : localization.items()) {
			if (lang.value().contains("selected") && lang.value()["selected"].is_boolean() && lang.value()["selected"]) {
				if (lang.key() == "en") {		//sorry, but I cand make it by switch
					language = en;
				} else if (lang.key() == "ru") {
					language = ru;
				} else {
					
				}
				break;
			}
		}
	}
	std::cout << "lang: " << language << std::endl;

	if (language == 0) {

	}
	
}

void console::pause(void) {
	std::wcout << L"Press any key to continue";
	getch();
}

void console::print(const wchar_t* message) {
	std::ifstream lcfile("resources/locale.json");
	json localization;
	localization["s"] = message;
	if(lcfile.is_open()) {
		lcfile >> localization;

	}
}

#ifdef _WIN32

#include <Windows.h>
#include <conio.h>

wchar_t console::getch(void) {
	return _getch();
}

wchar_t console::getche(void) {
	return _getche();
}

void console::getConsoleSize(uint32_t& width, uint32_t& height) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

#elif defined(__unix__)

#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

wchar_t console::getch_(bool echo) {
	struct termios oldattr, newattr;
	wchar_t ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~ICANON;
	if(echo)
		newattr.c_lflag |= ECHO;
	else
		newattr.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}

wchar_t console::getch(void) {
	return getch_(false);
}

wchar_t console::getche(void) {
	return getch_(true);
}

void console::getConsoleSize(uint32_t& width, uint32_t& height) {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	width = size.ws_col;
	height = size.ws_row;
}
#endif
