#pragma once
#include "console.hpp"

class application {
public:
	//you cant create an object of this class
	application() = delete;
	//you cant create an object of this class x2
	application(const application&) = delete;
	//you cant create an object of this class x3
	application(application&&) = delete;
	static void init();
};
