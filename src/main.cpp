#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

void getConsoleSize(int& rows, int& cols) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    cols = size.ws_col;
    rows = size.ws_row;
#endif
}

int main() {
    int rows, cols;
    getConsoleSize(rows, cols);
    std::cout << "Console size: " << cols << " columns x " << rows << " rows" << std::endl;

    return 0;
}
