#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "mvmcorrespondance.h"

class TestMvmcorrespondance:public CppUnit::TestFixture
{
	private:
		calc::MvmCorrespondance* mvmcorrespondances;

	public:
		void setUp();
		void tearDown();
		void TestCorrespondre();

		static CppUnit::Test *Suit();
};