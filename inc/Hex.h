/*
 * Hex.h
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#ifndef HEX_H_
#define HEX_H_

#include <ostream>

struct Hex
{
	int x;
	int y;
	int z;

	Hex() : Hex( -1, -1, 0 ) {}

	Hex( int x, int y, int z ) :
			x(x), y(y), z(z)
	{}
};

std::ostream& operator<<( std::ostream& s, const Hex& hex );

#endif /* HEX_H_ */
