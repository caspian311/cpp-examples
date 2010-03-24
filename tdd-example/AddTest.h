/*
 * AddTest.h
 *
 *  Created on: Mar 24, 2010
 *      Author: mtodd
 */

#ifndef ADDTEST_H_
#define ADDTEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include "Add.h"

class AddTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE( AddTest );
	CPPUNIT_TEST( testAdd );
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

	void testAdd();

private:
	Add add;
};

#endif /* ADDTEST_H_ */
