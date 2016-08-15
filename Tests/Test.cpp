/*
 * AllTests.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: tom
 */
#include "Test.h"
#include "UnitTest++/UnitTest++.h"

namespace Tests
{
	int All( void )
	{
		return UnitTest::RunAllTests();
	}
}
