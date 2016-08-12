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

enum MapOrientation
{
	Flat = 0, Pointed
};

class Map
{
public:
	Map( int width, int height, MapOrientation orientation) :
		Width( width ), Height( height ), Orientation( orientation ), _hexes( width * height )
	{
		for( int y = 0; y < Height; ++y )
		{
			for( int x = 0; x < Width; ++x )
			{
				Hex* h = ( *this )( x, y );
				h->x = x;
				h->y = y;
			}
		}

	}

	Hex* Move( const Hex* hex, Direction dir);

	Hex* operator[]( int index)
	{
		return &_hexes[ index ];
	}

	Hex* operator()( int x, int y)
	{
		return ( *this )[ IndexOf( x, y ) ];
	}

	const int Width;
	const int Height;
	const MapOrientation Orientation;

private:

	int IndexOf( int x, int y) const
	{
		return ( y * Width ) + x;
	}

	std::valarray<Hex> _hexes;
};

#endif /* MAP_H_ */
