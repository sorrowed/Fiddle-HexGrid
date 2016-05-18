/*
 * Hex.h
 *
 *  Created on: May 18, 2016
 *      Author: tom
 */

#ifndef HEX_H_
#define HEX_H_

struct Hex
{
	int x;
	int y;

	Hex( int x, int y ) :
			x(x), y(y)
	{}
};

#endif /* HEX_H_ */
