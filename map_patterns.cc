#include "map_patterns.h"

/**
 * Fill map with WALL tiles only
 */
void Wall::fill() {
	for (unsigned i=0; i < getHeight(); ++i)
		for (unsigned j=0; j < getWidth(); ++j)
			field[i][j] = map::WALL;
}

/**
 * Randomly fill the map
 * TODO I need to know how to get the modulo divider number from MapType enum
 */
void Random::fill() {
	for (unsigned i=0; i < getHeight(); ++i)
		for (unsigned j=0; j < getWidth(); ++j)
			field[i][j] = (map::MapType) (generator.rand() % 3);	// how to get enum size?
}

/**
 * Cave - we need a continous block of FLOOR type
 * First we create wall - there is a small chance to create floor. After a floor is luckily created,
 * it's more probable to create floor tile again.
 * 
 * Check 8-side around a tile. If the tile is a floor, it's bigger probability to create floor tile again. Et vice versa
 */
void Cave::fill() {
	short floorProbability = 10;	// 90% probability of wall appearance

	for (unsigned i=0; i < getHeight(); ++i)
		for (unsigned j=0; j < getWidth(); ++j) {
			if (floorTileAround(i,j)) {
				// there is a floor tile around field[i][j]
				// so it's bigger chance to create another floor tile
				// let's say it's 90%
				if ((generator.rand() % 100) < floorProbability) {
					// we've got another floor tile
					field[i][j] = map::FLOOR;
					floorProbability = 90;
				}
				else {
					// a wall appeared again
					field[i][j] = map::WALL;
					floorProbability = 10;
				}
			}
		}
	//for
}

/**
 * Check if there is a floor tile around given coordinates
 * TODO this should be done in a general way, not just for a Cave class
 */
bool Cave::floorTileAround(unsigned i, unsigned j) {
	if (i >= getHeight() || j >= getWidth()) {
			throw "Index out of map range. ";
	}

	// we've got 8 direction to check
	// 123
	// 4 5
	// 678

p1:
	if (i == 0 || j == 0) goto p2;
	if (field[i-1][j-1] == map::FLOOR) return true;

p2:
	if (i == 0) goto p3;
	if (field[i-1][j] == map::FLOOR) return true;

p3:
	if (i == 0 || j == getWidth()-1) goto p4;
	if (field[i-1][j+1] == map::FLOOR) return true;
			
p4:
	if (j == 0) goto p5;
	if (field[i][j-1] == map::FLOOR) return true;

p5:
	if (j == getWidth()-1) goto p6;
	if (field[i][j+1] == map::FLOOR) return true;

p6:
	if (i == getHeight()-1 || j == 0) goto p7;
	if (field[i+1][j-1] == map::FLOOR) return true;

p7:
	if (i == getHeight()-1) goto p8;
	if (field[i+1][j] == map::FLOOR) return true;

p8:
	if (i == getHeight()-1 || j == getWidth()-1) return false;
	if (field[i+1][j+1] == map::FLOOR) return true;

	return false;
}
