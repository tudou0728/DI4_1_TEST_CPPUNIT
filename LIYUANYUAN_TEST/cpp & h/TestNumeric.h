#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "numeric.h"

class TestNumeric: public CppUnit::TestFixture
{
	private:
		model::Numeric* numeric;
	public:
		void setUp();
		void tearDown();
		void TestGetSetValue();
		void TestToString();
		void TestDistance();
		void TestCopy();

		static  CppUnit::Test *Suit();
};