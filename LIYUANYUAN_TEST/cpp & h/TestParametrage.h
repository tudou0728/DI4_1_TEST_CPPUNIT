#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "parametrage.h"

class TestParametrage: public CppUnit::TestFixture
{
	private:
		calc::Parametrage* parametrage;
	public:
		void setUp();
		void tearDown();
		void TestGetSetSize();
		void TestGetSetWeight();
		void TestGetSetWeightMatrice();

		static  CppUnit::Test *Suit();
};