#include <cstdint>

class console {
public:
	console();
	static wchar_t getch(void);
	static void getConsoleSize(uint32_t& width, uint32_t& height);
};
