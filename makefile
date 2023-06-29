CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -std=c++20
LDFLAGS = -lstdc++ -static -ffunction-sections -fdata-sections -Wl,--gc-sections

MIN_GCC_VERSION = 11.4

SOURCES = src/main.cpp src/console.cpp
EXECUTABLE = calculator

.PHONY: all clean

all: $(EXECUTABLE)_release copy_resources_release

debug: CFLAGS += -g
debug: $(EXECUTABLE)_debug copy_resources_debug

$(EXECUTABLE)_release: $(SOURCES)
		$(CC) $(CXXFLAGS) $(CFLAGS) $(SOURCES) -o ./build/Release/$(EXECUTABLE) $(LDFLAGS)

$(EXECUTABLE)_debug: $(SOURCES)
		$(CC) $(CXXFLAGS) $(CFLAGS) $(SOURCES) -o ./build/Debug/$(EXECUTABLE) $(LDFLAGS)

copy_resources_debug:
	cp -R src/resources/ build/Debug

copy_resources_release:
	cp -R src/resources/ build/Release

clean:
	rm -f $(EXECUTABLE)
