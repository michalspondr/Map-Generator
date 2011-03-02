#ifndef _GENERATORH_
#define _GENERATORH_

#include <cstdlib>
#include <ctime>

/**
 * This is a base class to generate some values
 * By default it's supposed to generate values randomly. It could change in time (fractal-based generation etc.)
 */
class Generator {
	public:
	Generator() {
		std::srand((unsigned int) std::time((time_t *)NULL));	// random seed based on time
	}

	/**
	 * @return simple random value (just like classic rand())
	 */
	int rand();

};

#endif
