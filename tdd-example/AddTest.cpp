/*
 * AddTest.cpp
 *
 *  Created on: Mar 24, 2010
 *      Author: mtodd
 */

#include "AddTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( AddTest );

void AddTest::setUp() {
}

void AddTest::tearDown() {
}

void AddTest::testAdd() {
	CPPUNIT_ASSERT_EQUAL(3, add.add(1, 2));
}
