#include <cstdint>

class console {
public:
	console();
	wchar_t getch(void);
	void getConsoleSize(uint32_t& width, uint32_t& height);
};
