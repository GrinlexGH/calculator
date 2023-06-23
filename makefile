CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -std=c++20 -lstdc++
LDFLAGS = -static

MIN_GCC_VERSION = 11.4

SOURCES = src/main.cpp
EXECUTABLE = сalculator

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CXXFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(EXECUTABLE)
