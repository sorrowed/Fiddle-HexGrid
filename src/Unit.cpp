/*
 * Unit.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: tom
 */

#include <Unit.h>

Unit::Unit( Map& map, Hex* location ):
	_map( map ), _location( location )
{
}

Unit::~Unit()
{
}

void Unit::Move( Direction direction )
{
	_location = _map.Move( _location, direction );
}
