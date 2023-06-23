CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = -std=c++20 -lstdc++
LDFLAGS = -static

MIN_GCC_VERSION = 11.4

SOURCES = src/main.cpp
EXECUTABLE = сalculator

.PHONY: all clean check_compiler_version

all: check_compiler_version $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CXXFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(EXECUTABLE)

check_compiler_version:
	@printf "Checking compiler version...\n"
	@printf "C compiler: "
	@$(CC) --version | grep $(CC) | awk '{print $$NF}'
	@if [ "$$(echo "$$($(CC) -dumpversion | cut -d'.' -f1).$$(echo "$$($(CC) -dumpversion | cut -d'.' -f2)" | awk '{printf "%02d\n", $$1}') >= $(MIN_GCC_VERSION)" | bc)" -eq 0 ]; then \
		printf "\nUnsupported GCC version! Requires $(MIN_GCC_VERSION) or higher.\n" >&2; \
		exit 1; \
	fi
	# @printf "C++ compiler: "
	# @$(CXX) --version | grep $(CXX) | awk '{print $$NF}'
	# @if [ "$$(echo "$$($(CXX) -dumpversion | cut -d'.' -f1).$$(echo "$$($(CXX) -dumpversion | cut -d'.' -f2)" | awk '{printf "%02d\n", $$1}') >= $(MIN_GCC_VERSION)" | bc)" -eq 0 ]; then \
	# 	printf "\nUnsupported G++ version! Requires $(MIN_GCC_VERSION) or higher.\n" >&2; \
	# 	exit 1; \
	# fi
	@printf "Compiler version check passed.\n"