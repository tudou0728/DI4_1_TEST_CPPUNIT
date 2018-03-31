#include "TestCharacter.h"

void TestCharacter::setUp()
{
	character=new model::Character();
}

void TestCharacter::tearDown()
{
	delete character;
}

void TestCharacter::TestGetSetValue()
{
	character->setValue('m');
	CPPUNIT_ASSERT(character->getValue()=='m');
}

void TestCharacter::TestToString()
{
	character->setValue('p');
	CPPUNIT_ASSERT(character->toString()=="p");
}

void TestCharacter::TestDistance()
{
	model::Character* a1=new model::Character();
	a1->setValue('a');
	model::Character* a2=new model::Character();
	a2->setValue('d');
	float d1=character->distance(a1,a2);
	CPPUNIT_ASSERT(d1==1);

	model::Character* a3=new model::Character();
	a3->setValue('a');
	float d2=character->distance(a1,a3);
	CPPUNIT_ASSERT(d2==0);
}

void TestCharacter::TestCopy()
{
	character->setValue('b');
	model::Character* a1=(model::Character*)character->copy();
	CPPUNIT_ASSERT(a1->getValue()=='b');
}

CppUnit::Test * TestCharacter::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestCharacter");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacter>("Character_TestGetSetValue",&TestCharacter::TestGetSetValue));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacter>("Character_TestToString",&TestCharacter::TestToString));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacter>("Character_TestDistance",&TestCharacter::TestDistance));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacter>("Character_TestDistance",&TestCharacter::TestCopy));

	return suiteOfTests;
}