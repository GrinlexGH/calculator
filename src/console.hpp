#pragma once
#include <cstdint>

enum languages {en = 1, ru = 2};

class console {
public:
	console();
	static wchar_t getch(void);
	static wchar_t getche(void);
	static void getConsoleSize(uint32_t& width, uint32_t& height);
	static void pause(void);
	static void print(const wchar_t* message);
private:
	languages language;
#ifdef __unix__
	static wchar_t getch_(bool echo);
#endif
};
