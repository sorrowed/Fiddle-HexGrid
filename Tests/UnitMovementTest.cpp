/*
 * UnitMovementTest.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: tom
 */

#include "Map.h"
#include "Unit.h"

#include "UnitTest++/UnitTest++.h"

SUITE( HexGridTest )
{
	class UnitMovementTest
	{
	public:
		UnitMovementTest() :
			map( 4, 4, MapOrientation::Flat )
		{
		}

		Map map;
	};

	TEST_FIXTURE(UnitMovementTest, UnitMovement)
	{
		Unit unit( map, map( 2, 1 ) );

		unit.Move( North );
		CHECK_EQUAL( unit.Location(), map( 2, 0 ) );
		unit.Move( South );

		unit.Move( NorthWest );
		CHECK_EQUAL( unit.Location(), map( 1, 0 ) );
		unit.Move( SouthEast );

		unit.Move( SouthWest );
		CHECK_EQUAL( unit.Location(), map( 1, 1 ) );
		unit.Move( NorthEast );

		unit.Move( South );
		CHECK_EQUAL( unit.Location(), map( 2, 2 ) );
		unit.Move( North );

		unit.Move( NorthEast );
		CHECK_EQUAL( unit.Location(), map( 3, 0 ) );
		unit.Move( SouthWest );

		unit.Move( SouthEast );
		CHECK_EQUAL( unit.Location(), map( 3, 1 ) );
		unit.Move( NorthWest );
	}

	TEST_FIXTURE(UnitMovementTest, UnitMovementLimitsLeftTop)
	{
		Unit unit1( map, map( 0, 0 ) );

		unit1.Move( North );
		CHECK_EQUAL( unit1.Location(), map( 0, 0 ) );

		unit1.Move( NorthWest );
		CHECK_EQUAL( unit1.Location(), map( 0, 0 ) );

		unit1.Move( SouthWest );
		CHECK_EQUAL( unit1.Location(), map( 0, 0 ) );

		unit1.Move( NorthEast );
		CHECK_EQUAL( unit1.Location(), map( 0, 0 ) );
	}

	TEST_FIXTURE(UnitMovementTest, UnitMovementLimitsRightBottom)
	{
		Unit unit2( map, map( 3,3 ) );

		unit2.Move( South );
		CHECK_EQUAL( unit2.Location(), map( 3, 3 ) );

		unit2.Move( SouthWest );
		CHECK_EQUAL( unit2.Location(), map( 3, 3 ) );

		unit2.Move( SouthEast );
		CHECK_EQUAL( unit2.Location(), map( 3, 3 ) );

		unit2.Move( NorthEast );
		CHECK_EQUAL( unit2.Location(), map( 3, 3 ) );
	}
}
