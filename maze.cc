#include "map.h"
#include "map_patterns.h"
#include "print.h"
#include <iostream>
#include <exception>

using namespace map;

int main() {
	//Map map;
	Wall map;
	try {
		map.init();
	}
	catch (const char* e) {
		std::cout << "A problem with map initialization occured: " << e << std::endl;
	}

	map.fill();

	try {
		PRINT(map);
	}
	catch (const char* e) {
		std::cout << "A problem during map printing: " << e << std::endl;
	}
}
