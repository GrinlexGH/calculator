#include "console.hpp"

console::console() {

}

#ifdef _WIN32

#include <Windows.h>
#include <conio.h>

wchar_t console::getch() {
	return _getch();
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

wchar_t console::getch() {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

void console::getConsoleSize(uint32_t& width, uint32_t& height) {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	width = size.ws_col;
	height = size.ws_row;
}
#endif
