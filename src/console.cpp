#include "console.hpp"

console::console() {

}

#ifdef _WIN32

#include <Windows.h>
#include <conio.h>

wchar_t console::getch() {
	return _getch();
}

void console::getConsoleSize(uint32_t& columns, uint32_t& rows) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

#elif defined(__unix__)

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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
#endif
