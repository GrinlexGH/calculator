#pragma once
#include <cstdint>
#include "application.hpp"

enum languages {en = 1, ru = 2};

class console {
public:
	console() = delete;					//you cant create an object of this class
	console(const console&) = delete;	//you cant create an object of this class x2
	console(console&&) = delete;		//you cant create an object of this class x3
	static wchar_t getch(void);
	static wchar_t getche(void);
	static void getConsoleSize(uint32_t& width, uint32_t& height);
	static void pause(void);
	static void print(const wchar_t* message);
	static application app;
private:
#ifdef __unix__
	wchar_t getch_(bool echo);
#endif
};
