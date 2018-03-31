#include "TestLCScorrespondance.h"

void TestLcscorrespondance::setUp()
{
	lcscorrespondance=new calc::LCScorrespondance();
}

void TestLcscorrespondance::tearDown()
{
	delete lcscorrespondance;
}

void TestLcscorrespondance::TestCorrespondre()
{
	model::Sequence *cs1=new model::Sequence();
	model::Character * cha = new model::Character;
	cha->setValue('A');
	cs1->addElement(cha);
	model::Character * cha2 = new model::Character;
	cha2->setValue('c');
	cs1->addElement(cha2);
	model::Character * cha6 = new model::Character;
	cha6->setValue('g');
	cs1->addElement(cha6);
	model::Character * cha7 = new model::Character;
	cha7->setValue('b');
	cs1->addElement(cha7);
	model::Character * cha5 = new model::Character;
	cha5->setValue('f');
	cs1->addElement(cha5);
	model::Character * cha8 = new model::Character;
	cha8->setValue('h');
	cs1->addElement(cha8);
	model::Character * cha9 = new model::Character;
	cha9->setValue('k');
	cs1->addElement(cha9);

	model::Sequence *cs2=new model::Sequence();
	model::Character * cha3 = new model::Character;
	cha3->setValue('c');
	cs2->addElement(cha3);
	model::Character * cha4 = new model::Character;
	cha4->setValue('e');
	cs2->addElement(cha4);
	model::Character * cha10 = new model::Character;
	cha10->setValue('g');
	cs2->addElement(cha10);
	model::Character * cha11 = new model::Character;
	cha11->setValue('e');
	cs2->addElement(cha11);
	model::Character * cha12 = new model::Character;
	cha12->setValue('f');
	cs2->addElement(cha12);
	model::Character * cha13 = new model::Character;
	cha13->setValue('k');
	cs2->addElement(cha13);
	model::Character * cha14 = new model::Character;
	cha14->setValue('h');
	cs2->addElement(cha14);
	
	calc::ResultatCorrespondance *result=lcscorrespondance->correspondre(cs1,cs2);
	CPPUNIT_ASSERT(result->distance==4);
	CPPUNIT_ASSERT(result->correspondanceT1->at(1)==1);
	CPPUNIT_ASSERT(result->correspondanceT1->at(2)==1);
	CPPUNIT_ASSERT(result->correspondanceT1->at(4)==1);
	CPPUNIT_ASSERT(result->correspondanceT1->at(5)==1);
}

CppUnit::Test * TestLcscorrespondance::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestLcscorrespondance");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestLcscorrespondance>("Lcscorrespondance_TestCorrespondre",&TestLcscorrespondance::TestCorrespondre));
	
	return suiteOfTests;
}