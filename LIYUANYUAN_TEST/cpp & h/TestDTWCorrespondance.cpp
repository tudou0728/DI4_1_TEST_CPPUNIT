#include "TestDTWCorrespondance.h"

void TestDTWCorrespondance::setUp()
{
	dtwCorrespondance=new calc::DTWCorrespondance();
}

void TestDTWCorrespondance::tearDown()
{
	delete dtwCorrespondance;
}

void TestDTWCorrespondance::TestCorrespondre()
{
	model::Sequence *cs1=new model::Sequence();
	model::Numeric * cha6 = new model::Numeric;
	cha6->setValue(1);
	cs1->addElement(cha6);
	model::Numeric * cha7 = new model::Numeric;
	cha7->setValue(2);
	cs1->addElement(cha7);
	model::Numeric * cha5 = new model::Numeric;
	cha5->setValue(3);
	cs1->addElement(cha5);
	model::Numeric * cha8 = new model::Numeric;
	cha8->setValue(4);
	cs1->addElement(cha8);
	model::Numeric * cha9 = new model::Numeric;
	cha9->setValue(5);
	cs1->addElement(cha9);

	model::Sequence *cs2=new model::Sequence();
	model::Numeric * cha3 = new model::Numeric;
	cha3->setValue(5);
	cs2->addElement(cha3);
	model::Numeric * cha4 = new model::Numeric;
	cha4->setValue(3);
	cs2->addElement(cha4);
	model::Numeric * cha10 = new model::Numeric;
	cha10->setValue(2);
	cs2->addElement(cha10);
	model::Numeric * cha11 = new model::Numeric;
	cha11->setValue(3);
	cs2->addElement(cha11);
	
	calc::ResultatCorrespondance *result=dtwCorrespondance->correspondre(cs1,cs2);
	CPPUNIT_ASSERT(fabs(result->distance-sqrt(22))<0.000001);
	CPPUNIT_ASSERT(result->correspondanceT1->at(0)==0);
	CPPUNIT_ASSERT(result->correspondanceT1->at(1)==1);
	CPPUNIT_ASSERT(result->correspondanceT1->at(2)==1);
	CPPUNIT_ASSERT(result->correspondanceT1->at(3)==2);
	CPPUNIT_ASSERT(result->correspondanceT1->at(4)==3);
	CPPUNIT_ASSERT(result->correspondanceT1->at(5)==4);
}

CppUnit::Test * TestDTWCorrespondance::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestDTWCorrespondance");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestDTWCorrespondance>("DTWCorrespondance_TestCorrespondre",&TestDTWCorrespondance::TestCorrespondre));
	
	return suiteOfTests;
}