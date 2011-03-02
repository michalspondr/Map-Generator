#include "map_patterns.h"


void Wall::fill() {
	for (unsigned i=0; i < getHeight(); ++i)
		for (unsigned j=0; j < getWidth(); ++j)
			field[i][j] = map::WALL;
}
