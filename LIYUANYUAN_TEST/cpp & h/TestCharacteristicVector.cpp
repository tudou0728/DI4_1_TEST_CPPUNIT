#include "TestCharacteristicVector.h"

void TestCharacteristicvector::setUp()
{
	characteristicVector=new model::CharacteristicVector();
}

void TestCharacteristicvector::tearDown()
{
	delete characteristicVector;
}

void TestCharacteristicvector::TestGetSetValue()
{
	characteristicVector->addValue(3.2f);
	CPPUNIT_ASSERT(characteristicVector->getAt(0)==3.2f);
	characteristicVector->addValue(156);
	characteristicVector->addValue(65.95f);
	characteristicVector->setValue(1,20);
	CPPUNIT_ASSERT(characteristicVector->getAt(1)==(float)20);
	characteristicVector->setValue(2,54.6f);
	CPPUNIT_ASSERT(characteristicVector->getAt(2)==54.6f);
}

void TestCharacteristicvector::TestAddRemoveGetSizeValue()
{
	characteristicVector->addValue(12.19f);
	characteristicVector->addValue((float)20);
	characteristicVector->addValue(1.05f);
	characteristicVector->addValue((float)100);
	characteristicVector->addValue(6.06f);
	characteristicVector->addValue(3.3f);
	CPPUNIT_ASSERT(characteristicVector->getSize()==6);

	characteristicVector->removeValue(3);
	CPPUNIT_ASSERT(characteristicVector->getSize()==5);
}


void TestCharacteristicvector::TestToString()
{
	characteristicVector->addValue(10);
	characteristicVector->addValue(35.34f);
	characteristicVector->addValue(20);
	CPPUNIT_ASSERT(characteristicVector->toString()=="[[10] [35.34] [20] ]");
}

void TestCharacteristicvector::TestDistance()
{
	model::CharacteristicVector* c1=new model::CharacteristicVector();
	c1->addValue(10);
	c1->addValue(1);
	c1->addValue(15.5f);
	model::CharacteristicVector* c2=new model::CharacteristicVector();
	c2->addValue(2);
	c2->addValue(5.5f);
	c2->addValue(15.5f);
	float d1=characteristicVector->distance(c1,c2);
	CPPUNIT_ASSERT(fabs(d1-9.17877)<0.00001);
	delete c1,c2;
}

void TestCharacteristicvector::TestCopy()
{
	characteristicVector->addValue(10);
	characteristicVector->addValue(42.534f);
	characteristicVector->addValue(6534.75f);
	model::CharacteristicVector* c1=(model::CharacteristicVector*)characteristicVector->copy();
	CPPUNIT_ASSERT(c1->getSize()==3);
	CPPUNIT_ASSERT(c1->getAt(1)==42.534f);
	delete c1;
}

CppUnit::Test * TestCharacteristicvector::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestCharacteristicvector");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacteristicvector>("Characteristicvectorc_TestAddRemoveGetSizeValue",&TestCharacteristicvector::TestAddRemoveGetSizeValue));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacteristicvector>("Characteristicvectorc_TestAddRemoveGetSizeValue",&TestCharacteristicvector::TestGetSetValue));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacteristicvector>("Characteristicvectorc_TestAddRemoveGetSizeValue",&TestCharacteristicvector::TestCopy));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacteristicvector>("Characteristicvectorc_TestAddRemoveGetSizeValue",&TestCharacteristicvector::TestToString));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCharacteristicvector>("Characteristicvectorc_TestAddRemoveGetSizeValue",&TestCharacteristicvector::TestDistance));

	return suiteOfTests;
}