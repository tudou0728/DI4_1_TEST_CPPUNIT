#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "TestCopieCommandeLineApp.h"

class TestCommandlineapplication: public CppUnit::TestFixture
{
	private:
		TestCopieCommandeLineApp *testCopieCommandeLineApp;
	public:
			void setUp();
			void tearDown();
			void testCheckParams();			
			static CppUnit::Test *Suit(); 
};