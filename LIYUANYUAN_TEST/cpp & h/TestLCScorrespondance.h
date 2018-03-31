#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "lcscorrespondance.h"

class TestLcscorrespondance :public CppUnit::TestFixture
{
	private:
		calc::LCScorrespondance* lcscorrespondance;
	public:
		void setUp();
		void tearDown();
		void TestCorrespondre();

		static  CppUnit::Test *Suit();
};