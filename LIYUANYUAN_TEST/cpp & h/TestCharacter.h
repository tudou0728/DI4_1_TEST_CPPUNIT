#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>

#include "character.h"

class TestCharacter :public CppUnit::TestFixture
{
private:
	model::Character* character;
public:
	void setUp();
	void tearDown();
	void TestGetSetValue();
	void TestToString();
	void TestDistance();
	void TestCopy();

	static  CppUnit::Test *Suit();
};