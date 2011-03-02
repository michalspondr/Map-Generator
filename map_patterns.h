#ifndef _MAPPATTERNS_
#define _MAPPATTERNS_

#include "map.h"
#include "generator.h"

/**
 * This map is all made from WALL tiles
 */
class Wall : public map::Map {
	public:
	virtual void fill();
};

/**
 * Totally random map using the random generator
 */
class Random : public map::Map {
	Generator generator;
	public:
	virtual void fill();
};

/**
 * Map with a floor inside surrounded by wall
 */
class Cave : public map::Map {
	Generator generator;
	bool floorTileAround(unsigned i, unsigned j);

	public:
	virtual void fill();
};

#endif
