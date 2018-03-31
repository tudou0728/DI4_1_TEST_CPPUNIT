#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "rapidxml-1.13\rapidxml_print.hpp"
#include "rapidxml-1.13\rapidxml_utils.hpp"
#include "rapidxml-1.13\rapidxml.hpp"
#include "rapidxml-1.13\rapidxml_iterators.hpp"

#include "paramparser.h"

class TestParamParser:public CppUnit::TestFixture
{
	private:
		inout::ParamParser* paramparser;

	public:
		void setUp();
		void tearDown();
		void testReadXML();

		static CppUnit::Test *Suit();
};