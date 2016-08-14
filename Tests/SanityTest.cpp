/*
 * SanityTest.h
 *
 *  Created on: Aug 14, 2016
 *      Author: tom
 */

#ifndef TESTS_SANITYTEST_CPP_
#define TESTS_SANITYTEST_CPP_

#include "UnitTest++/UnitTest++.h"

TEST(Sanity)
{
	CHECK_EQUAL( 1, 1 );
	//CHECK_EQUAL( 1, 2 );
}

#endif /* TESTS_SANITYTEST_CPP_ */
