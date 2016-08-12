/*
 * Unit.h
 *
 *  Created on: Aug 12, 2016
 *      Author: tom
 */

#ifndef UNIT_H_
#define UNIT_H_

#include "Direction.h"
#include "Map.h"

class Unit
{
public:
	Unit( Map& map, Hex* location );
	virtual ~Unit();

	void Move( Direction direction );

	const Hex* Location() const { return _location; }
private:
	Map& _map;
	Hex* _location;
};

#endif /* UNIT_H_ */
