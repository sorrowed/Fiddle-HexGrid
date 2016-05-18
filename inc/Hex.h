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

	Hex() : Hex( -1, -1 ) {}

	Hex( int x, int y ) :
			x(x), y(y)
	{}
};

std::ostream& operator<<( std::ostream& s, const Hex& hex );

#endif /* HEX_H_ */
