#include "map.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace map {

	Map::Map() : width(WIDTH), height(HEIGHT) {
		field = new MapType*[height*width];
		for (unsigned i=0; i < height; ++i) {
			field[i] = new MapType[width];
		}
	}

	Map::~Map() {
		for (unsigned i=0; i < height; ++i) {
			delete [] field[i];
		}

		delete [] field;
	}


	void Map::init() {
		if (field == NULL) {
			throw "Map not initialized";
		}

		// initialize all cells with an empty place
		for (unsigned i=0; i < height; ++i)
			for (unsigned j=0; j < height; ++j) {
				field[i][j] = FLOOR;
			}
	}

	void Map::fill() {
		// default fill, just create a box of WALL
		for (unsigned i=0; i < height; ++i) {
			field[i][0] = field[i][width-1] = WALL;
		}

		for (unsigned j=0; j < width; ++j) {
			field[0][j] = field[height-1][j] = WALL;
		}
	}

	MapType Map::getType(unsigned const i, unsigned const j) const {
		if (i >= height || j >= width) {
			throw "Index out of map range. ";
		}

		return field[i][j];
	}

#ifdef DEBUG
	std::ostream& operator<< (std::ostream& os, const Map& map) {
		for (unsigned i=0; i < map.getHeight(); ++i) {
			for (unsigned j=0; j < map.getWidth(); ++j) {
				char c=FLOOR;
				switch (map.getType(i,j)) {
					case WALL : c = '#';
								break;
					case OBJECT : c = '.';
								  break;
					case FLOOR:
					default : c = ' ';
				}
				os << c;
			}
			os << std::endl;
		}
		return os;
	}
#endif

}	// namespace map
