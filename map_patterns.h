#ifndef _MAPPATTERNS_
#define _MAPPATTERNS_

#include "map.h"

/**
 * This map is all made from WALL tiles
 */
class Wall : public map::Map {
	public:
	virtual void fill();
};

#endif
