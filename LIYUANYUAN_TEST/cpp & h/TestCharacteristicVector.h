#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "characteristicvector.h"

class TestCharacteristicvector:public CppUnit::TestFixture
{
	private:
		model::CharacteristicVector* characteristicVector;
public:
	void setUp();
	void tearDown();
	void TestGetSetValue();
	void TestAddRemoveGetSizeValue();
	void TestToString();
	void TestDistance();
	void TestCopy();

	static  CppUnit::Test *Suit();
};