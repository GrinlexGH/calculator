#include <iostream>
#include "console.hpp"


int main() {
	uint32_t w;
	uint32_t h;		//commentariy
	console::getConsoleSize(h, w);
	std::cout << w << "\t" << h;
	return 0;
}
