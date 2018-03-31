#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "levenstheincorrespondance.h"

class TestLevenstheincorrespondance:public CppUnit::TestFixture
{
	private:
		calc::LevenstheinCorrespondance *levenstheinCorrespondance;
	public:
		void setUp();
		void tearDown();
		void testCorrespondre();

		static CppUnit::Test *Suit();
};