/*
 * Hex.cpp
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */
#include "Hex.h"

std::ostream& operator<<( std::ostream& s, const Hex& hex )
{
	return s << '[' << hex.x << ',' << hex.y << ']';
}




