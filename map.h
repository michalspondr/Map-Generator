#ifndef _MAP_
#define _MAP_

/**
 * Map is a rectangle object with given width and height
 *
 * Each field could be a different type
 */

#ifdef DEBUG
#include <iostream>
#endif

const unsigned int WIDTH = 10;
const unsigned int HEIGHT = 10;

namespace map {

	/**
	 * Type of map field
	 */
	enum MapType {
		FLOOR,
		WALL,
		OBJECT
	};

	class Map {
		unsigned int width;
		unsigned int height;
		MapType type;

		protected:
		MapType** field;

		public:
		Map();
		~Map();
		unsigned int getWidth() const { return width; }
		unsigned int getHeight() const { return height; }
		MapType getType(unsigned const i, unsigned const j) const;
		void init();

		virtual void fill();	/// this determines the way the map is created

#ifdef DEBUG
		friend std::ostream & operator<<(std::ostream& os, const Map& m);
#endif
	};

};

#endif
