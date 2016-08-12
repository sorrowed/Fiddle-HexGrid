/*
 * main.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#include "Map.h"
#include "Unit.h"

#include <iostream>

Map map( 4, 4, MapOrientation::Flat );

int main( int argc, char* argv[] )
{
	Hex& start = map( 2, 1 );

	Unit unit( map, start );

	std::cout << "START:\t\t" << unit.Location() << '\n';

	unit.Move( North );
	std::cout << "North:\t\t" << unit.Location() << '\n';
	unit.Move( South );

	unit.Move( NorthWest );
	std::cout << "NorthWest:\t" << unit.Location() << '\n';
	unit.Move( SouthEast );

	unit.Move( SouthWest );
	std::cout << "SouthWest:\t" << unit.Location() << '\n';
	unit.Move( NorthEast );

	unit.Move( South );
	std::cout << "South:\t\t" << unit.Location() << '\n';
	unit.Move( North );

	unit.Move( NorthEast );
	std::cout << "NorthEast:\t" << unit.Location() << '\n';
	unit.Move( SouthWest );

	unit.Move( SouthEast );
	std::cout << "SouthEast:\t" << unit.Location() << '\n';
	unit.Move( NorthWest );

	return 0;
}
