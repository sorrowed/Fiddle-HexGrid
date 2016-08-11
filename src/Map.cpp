/*
 * Map.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */
#include "Map.h"

Hex& Map::Move( const Hex& hex, Direction dir )
{
	int x = hex.x, y = hex.y;

	switch( dir )
	{
		case North:	// Flat orientation only
			if( orientation == Orientation::Flat && hex.y > 0 )
				y -= 1;
			break;

		case South:	// Flat orientation only
			if( orientation == Orientation::Flat && hex.y < height - 1 )
				y += 1;
			break;

		case East:	// Pointed orientation only
			if( orientation == Orientation::Pointed && hex.x < width - 1 )
				x += 1;
			break;

		case West: 	// Pointed orientation only
			if( orientation == Orientation::Pointed && hex.x > 0 )
				x -= 1;
			break;

		case NorthWest:
		{
			int ny = hex.x % 2 ? hex.y : hex.y - 1;
			if( hex.x > 0 && ny >= 0 )
				x -= 1, y = ny;
			break;
		}

		case SouthWest:
		{
			int ny = hex.x % 2 ? hex.y + 1: hex.y;
			if( hex.x > 0 && ny < height )
				x -= 1, y = ny;
			break;
		}

		case NorthEast:
		{
			int ny = hex.x % 2 ? hex.y : hex.y - 1;
			if( hex.x < width - 1 && ny >= 0 )
				x += 1, y = ny;
			break;
		}

		case SouthEast:
		{
			int ny = hex.x % 2 ? hex.y + 1: hex.y;
			if( hex.x < width - 1 && ny < height )
				x += 1, y = ny;
			break;
		}

		default:
			break;
	}

	return At( x, y );
}
