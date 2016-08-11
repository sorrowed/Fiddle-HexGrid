/*
 * main.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#include "Map.h"

#include <iostream>

Map map( 4, 4, MapOrientation::Flat );

int main( int argc, char* argv[] )
{
	const Hex& o = map.At( 2, 1 );
	std::cout << "ORIGIN:" << o << '\n';

	Hex& n = map.Move( o, North );
	std::cout << "N:" << n << '\n';
	Hex& nw = map.Move( o, NorthWest );
	std::cout << "NW:" << nw << '\n';
	Hex& sw = map.Move( o, SouthWest );
	std::cout << "SW:" << sw << '\n';
	Hex& s = map.Move( o, South );
	std::cout << "S:" << s << '\n';
	Hex& ne = map.Move( o, NorthEast );
	std::cout << "NE:" << ne << '\n';
	Hex& se = map.Move( o, SouthEast );
	std::cout << "SE:" << se << '\n';

	return 0;
}
