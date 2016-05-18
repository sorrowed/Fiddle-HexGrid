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

#include <array>

template<int W,int H>
class Map
{
public:
	Map() : width( W ), height( H ), hexes()
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
		return operator[]( IndexOf( x, y ) );
	}

private:

	int width;
	int height;

	int IndexOf( int x, int y ) const
	{
		return y * width + x;
	}

	std::array<Hex, W * H > hexes;
};

template<int W,int H>
Hex& Map<W,H>::Move( const Hex& hex, Direction dir )
{
	switch( dir )
	{
		case North:
			if( hex.y > 0 )
				return At( hex.x, hex.y - 1 );
			else
				return At( hex.x, hex.y );
			break;

		case South:
			if( hex.y < height - 1 )
				return At( hex.x, hex.y + 1 );
			else
				return At( hex.x, hex.y );
			break;

		case NorthWest:
		{
			int y = hex.x % 2 ? hex.y : hex.y - 1;
			if( hex.x > 0 && y >= 0 )
				return At( hex.x - 1, y );
			else
				return At( hex.x, hex.y );
			break;
		}

		case SouthWest:
		{
			int y = hex.x % 2 ? hex.y + 1: hex.y;
			if( hex.x > 0 && y < height )
				return At( hex.x - 1, y );
			else
				return At( hex.x, hex.y );
			break;
		}

		case NorthEast:
		{
			int y = hex.x % 2 ? hex.y : hex.y - 1;
			if( hex.x < width - 1 && y >= 0 )
				return At( hex.x + 1, y );
			else
				return At( hex.x, hex.y );
			break;
		}

		case SouthEast:
		{
			int y = hex.x % 2 ? hex.y + 1: hex.y;
			if( hex.x < width - 1 && y < height )
				return At( hex.x + 1, y );
			else
				return At( hex.x, hex.y );
			break;
		}

		default:
			return At( hex.x, hex.y );
	}
}

#endif /* MAP_H_ */
