#include <iostream>
#include "console.hpp"


int main() {
	console con;
	uint32_t w;
	uint32_t h;
	con.getConsoleSize(h, w);
	std::cout << w << "\t" << h;
	return 0;
}
