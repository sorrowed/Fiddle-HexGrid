/*
 * Map.h
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#ifndef MAP_H_
#define MAP_H_

#include "Hex.h"
#include "Direction.h"

#include <valarray>

enum Orientation
{
	Flat = 0,
	Pointed
};

class Map
{
public:
	Map( int w, int h, Orientation o ) : width( w ), height( h ), orientation( o ), hexes( w * h )
	{
		for( int y = 0; y < height; ++y )
		{
			for( int x = 0; x < width; ++x )
			{
				Hex& h = At( x, y );
				h.x = x;
				h.y = y;
			}
		}

	}

	Hex& Move( const Hex& hex, Direction dir );

	const Hex& Origin () { return At( 0, 0 ); }

	Hex& operator[]( int index )
	{
		return hexes[ index ];
	}

	Hex& At( int x, int y )
	{
		return (*this)[ IndexOf( x, y ) ];
	}

private:

	const int width;
	const int height;
	const Orientation orientation;

	int IndexOf( int x, int y ) const
	{
		return y * width + x;
	}

	std::valarray<Hex> hexes;
};

#endif /* MAP_H_ */
