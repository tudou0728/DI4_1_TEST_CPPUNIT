#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


#include "commandlineoutput.h"

class TestCommandLineOutput:public CppUnit::TestFixture
{
	private:
		inout::CommandLineOutput* commandeLineOutput;

	public:
		void setUp();
		void tearDown();
		void testFormat();

		static CppUnit::Test *Suit();
};