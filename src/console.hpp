#include <cstdint>

class console {
public:
	console();
	wchar_t getch(void);
	void getConsoleSize(uint32_t& columns, uint32_t& rows);
};
