#include <iostream>
#include "console.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	console::app.init();
	cout << argc << endl;
	cout << argv[0] << endl;
	uint32_t w;
	uint32_t h;
	console::getConsoleSize(h, w);
	cout << w << "\t" << h << endl;
	cout << "Enter any key for continue: ";
	int cd = console::getch();
	cout << endl;
	w = cd;
	return 0;
}
