#pragma once
#include <cstdint>

class console {
public:
	console();
	static wchar_t getch(void);
	static wchar_t getche(void);
	static void getConsoleSize(uint32_t& width, uint32_t& height);
	static void pause(void);
private:
#ifdef __unix__
	static wchar_t getch_(bool echo);
#endif
};
