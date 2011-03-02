#ifndef _PRINTOUT_
#define _PRINTOUT_

/**
 * Here is defined printout of the map, especially for debugging purposes
 *
 * Each class using the PRINT method must have its operator<< definition
 */

#include <iostream>
template <typename C>
void PRINT(C& c) {
#ifdef DEBUG
	std::cout << c;
#endif
}

#endif
