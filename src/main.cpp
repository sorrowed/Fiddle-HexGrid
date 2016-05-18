/*
 * main.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#include "Map.h"

#include <iostream>

Map map( 4, 4 );

std::ostream& operator<<( std::ostream& s, const Hex& hex )
{
	return s << '[' << hex.x << ',' << hex.y << ']';
}

int main( int argc, char* argv[] )
{
	const Hex& o = map.HexAt( 2, 1 );
	std::cout << "ORIGIN:" << o << ' ';

	Hex& n = map.Move( o, North );
	std::cout << "N:" << n << ' ';
	Hex& nw = map.Move( o, NorthWest );
	std::cout << "NW:" << nw << ' ';
	Hex& sw = map.Move( o, SouthWest );
	std::cout << "SW:" << sw << ' ';
	Hex& s = map.Move( o, South );
	std::cout << "S:" << s << ' ';
	Hex& ne = map.Move( o, NorthEast );
	std::cout << "NE:" << ne << ' ';
	Hex& se = map.Move( o, SouthEast );
	std::cout << "SE:" << se << '\n';

	return 0;
}



