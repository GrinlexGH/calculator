#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
	#include <Windows.h>
#elif defined(__unix__)
	#include <sys/ioctl.h>
	#include <unistd.h>
#endif

void getConsoleSize(int& columns, int& rows) {
#if defined(_WIN32) || defined(_WIN64)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#elif defined(__unix__)
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	columns = size.ws_col;
	rows = size.ws_row;
#endif
}

int main() {
    int columns, rows;
    getConsoleSize(columns, rows);
    std::cout << "Console size: " << columns << " columns x " << rows << " rows" << std::endl;
    return 0;
}
