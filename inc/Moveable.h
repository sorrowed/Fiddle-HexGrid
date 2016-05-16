/*
 * Moveable.h
 *
 *  Created on: May 15, 2016
 *      Author: tom
 */

#ifndef SRC_MOVEABLE_H_
#define SRC_MOVEABLE_H_

struct Hex
{
	int x;
	int y;

	Hex( int x, int y ) :
			x(x), y(y)
	{}
};

enum Direction
{
	North = 0,
	NorthWest,
	SouthWest,
	South,
	SouthEast,
	NorthEast
};


#include <vector>
class Map
{
public:
	Map( int width, int height ) :
		width( width ), height( height )
	{
		for( int y = 0; y < height; ++y )
		{
			for( int x = 0; x < width; ++x )
			{
				hexes.push_back( Hex( x, y ) );
			}
		}

	}

	Hex& Move( const Hex& hex, Direction dir )
	{
		switch( dir )
		{
			case North:
				if( hex.y > 0 )
					return HexAt( hex.x, hex.y - 1 );
				else
					return HexAt( hex.x, hex.y );
				break;

			case South:
				if( hex.y < height - 1 )
					return HexAt( hex.x, hex.y + 1 );
				else
					return HexAt( hex.x, hex.y );
				break;

			case NorthWest:
			{
				int y = hex.x % 2 ? hex.y : hex.y - 1;
				if( hex.x > 0 && y >= 0 )
					return HexAt( hex.x - 1, y );
				else
					return HexAt( hex.x, hex.y );
				break;
			}

			case SouthWest:
			{
				int y = hex.x % 2 ? hex.y + 1: hex.y;
				if( hex.x > 0 && y < height )
					return HexAt( hex.x - 1, y );
				else
					return HexAt( hex.x, hex.y );
				break;
			}

			case NorthEast:
			{
				int y = hex.x % 2 ? hex.y : hex.y - 1;
				if( hex.x < width - 1 && y >= 0 )
					return HexAt( hex.x + 1, y );
				else
					return HexAt( hex.x, hex.y );
				break;
			}

			case SouthEast:
			{
				int y = hex.x % 2 ? hex.y + 1: hex.y;
				if( hex.x < width - 1 && y < height )
					return HexAt( hex.x + 1, y );
				else
					return HexAt( hex.x, hex.y );
				break;
			}

			default:
				return HexAt( hex.x, hex.y );
		}
	}

	const Hex& Origin () { return HexAt( 0, 0 ); }

	Hex& HexAt( int x, int y )
	{
		return hexes[ y * width + x ];
	}

private:

	int width;
	int height;

	std::vector<Hex> hexes;
};

class Moveable {
public:
	Moveable();
	virtual ~Moveable();
};

#endif /* SRC_MOVEABLE_H_ */
