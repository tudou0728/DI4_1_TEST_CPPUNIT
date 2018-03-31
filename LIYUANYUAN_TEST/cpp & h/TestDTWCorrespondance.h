#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "dtwcorrespondance.h"

class TestDTWCorrespondance:public CppUnit::TestFixture
{
	private:
		calc::DTWCorrespondance* dtwCorrespondance;
	public:
		void setUp();
		void tearDown();
		void TestCorrespondre();

		static  CppUnit::Test *Suit();
};