/*
 * Map.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */
#include "Map.h"

Hex* Map::Move( const Hex* hex, Direction dir )
{
	int x = hex->x, y = hex->y;

	switch( dir )
	{
		case North:	// Flat Orientation only
			if( Orientation == MapOrientation::Flat && hex->y > 0 )
				y -= 1;
			break;

		case South:	// Flat Orientation only
			if( Orientation == MapOrientation::Flat && hex->y < Height - 1 )
				y += 1;
			break;

		case East:	// Pointed Orientation only
			if( Orientation == MapOrientation::Pointed && hex->x < Width - 1 )
				x += 1;
			break;

		case West: 	// Pointed Orientation only
			if( Orientation == MapOrientation::Pointed && hex->x > 0 )
				x -= 1;
			break;

		case NorthWest:
		{
			int ny = hex->x % 2 ? hex->y : hex->y - 1;
			if( hex->x > 0 && ny >= 0 )
				x -= 1, y = ny;
			break;
		}

		case SouthWest:
		{
			int ny = hex->x % 2 ? hex->y + 1: hex->y;
			if( hex->x > 0 && ny < Height )
				x -= 1, y = ny;
			break;
		}

		case NorthEast:
		{
			int ny = hex->x % 2 ? hex->y : hex->y - 1;
			if( hex->x < Width - 1 && ny >= 0 )
				x += 1, y = ny;
			break;
		}

		case SouthEast:
		{
			int ny = hex->x % 2 ? hex->y + 1: hex->y;
			if( hex->x < Width - 1 && ny < Height )
				x += 1, y = ny;
			break;
		}

		default:
			break;
	}

	return &(*this)( x, y );
}
