#include "TestSequence.h"

void TestSequence::setUp()
{
	sq=new model::Sequence();
}

void TestSequence::tearDown()
{
	delete sq;
}

/**
void TestSequence::testAddElement()
{
	model::Sequence *sq2=new model::Sequence();
	model::Character * cha2 = new model::Character;
	cha2->setValue('y');
	sq2->addElement(cha2);
	model::Character *cha= dynamic_cast<model::Character * >(sq2->getElement(0));
	CPPUNIT_ASSERT(cha==cha2);
}*/

void TestSequence::testGetAddElement()
{
	model::Sequence *sq2=new model::Sequence();
	model::Character * cha2 = new model::Character;
	cha2->setValue('m');
	sq2->addElement(cha2);
	char test= dynamic_cast<model::Character * >(sq2->getElement(0))->getValue();
	CPPUNIT_ASSERT(test=='m');
	delete sq2;
}
void TestSequence::testRemoveGetSize()
{
	model::Sequence *sq2=new model::Sequence();
	model::Character * cha2 = new model::Character;
	cha2->setValue('m');
	sq2->addElement(cha2);
	model::Character * cha = new model::Character;
	cha->setValue('n');
	sq2->addElement(cha);
	int size=sq2->getSize();
	CPPUNIT_ASSERT(size==2);
	sq2->removeElement(1);
	CPPUNIT_ASSERT(sq2->getSize()==1);
	delete sq2;
}

CppUnit::Test *TestSequence::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestSequence");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestSequence>("Sequence_testGetSize",&TestSequence::testRemoveGetSize));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestSequence>("Sequence_testGetSetAddElement",&TestSequence::testGetAddElement));

	return suiteOfTests;
}



