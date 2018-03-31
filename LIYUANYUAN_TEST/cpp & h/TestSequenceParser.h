#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "sequenceparser.h"

class TestSequenceParser:public CppUnit::TestFixture
{
	private:
		inout::SequenceParser *sequenceParser;

	public:
		void setUp();
		void tearDown();
		void testReadCSV();
		void testReadXML();

		static CppUnit::Test *Suit();
};