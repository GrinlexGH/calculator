#include <iostream>
#include "console.hpp"
using namespace std;

static console co;		//needs for calling constructor

int main() {
	uint32_t w;
	uint32_t h;
	console::getConsoleSize(h, w);
	cout << w << "\t" << h << endl;
	cout << "Enter any key for continue: ";
	int c = console::getch();
	cout << endl;
	w = c;
	return 0;
}
