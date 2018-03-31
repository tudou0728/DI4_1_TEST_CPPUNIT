#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


#include "sequence.h"

class TestSequence:public CppUnit::TestFixture
{
	private:
		model::Sequence *sq;

	public:
		void setUp();
		void tearDown();
		void testGetAddElement();
		void testRemoveGetSize();

		static CppUnit::Test *Suit();
};