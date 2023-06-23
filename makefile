CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -std=c++20
LDFLAGS = -lstdc++ -static -ffunction-sections -fdata-sections -Wl,--gc-sections

MIN_GCC_VERSION = 11.4

SOURCES = src/main.cpp
EXECUTABLE = calculator

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CXXFLAGS) $(CFLAGS) $(LDFLAGS) -o ./build/$@ $(SOURCES)

clean:
	rm -f $(EXECUTABLE)
