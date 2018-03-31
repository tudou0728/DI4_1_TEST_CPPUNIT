#include "TestMvmCorrespondance.h"


void TestMvmcorrespondance::setUp()
{
	mvmcorrespondances=new calc::MvmCorrespondance();
}

void TestMvmcorrespondance::tearDown()
{
	delete mvmcorrespondances;
}

void TestMvmcorrespondance::TestCorrespondre()
{
	model::Sequence *cs1=new model::Sequence();
	model::Numeric * cha6 = new model::Numeric;
	cha6->setValue(1);
	cs1->addElement(cha6);
	model::Numeric * cha7 = new model::Numeric;
	cha7->setValue(2);
	cs1->addElement(cha7);
	model::Numeric * cha5 = new model::Numeric;
	cha5->setValue(8);
	cs1->addElement(cha5);
	model::Numeric * cha8 = new model::Numeric;
	cha8->setValue(6);
	cs1->addElement(cha8);
	model::Numeric * cha9 = new model::Numeric;
	cha9->setValue(8);
	cs1->addElement(cha9);

	model::Sequence *cs2=new model::Sequence();
	model::Numeric * cha3 = new model::Numeric;
	cha3->setValue(1);
	cs2->addElement(cha3);
	model::Numeric * cha4 = new model::Numeric;
	cha4->setValue(2);
	cs2->addElement(cha4);
	model::Numeric * cha10 = new model::Numeric;
	cha10->setValue(9);
	cs2->addElement(cha10);
	model::Numeric * cha11 = new model::Numeric;
	cha11->setValue(3);
	cs2->addElement(cha11);
	model::Numeric * cha12 = new model::Numeric;
	cha12->setValue(3);
	cs2->addElement(cha12);
	model::Numeric * cha13 = new model::Numeric;
	cha13->setValue(5);
	cs2->addElement(cha13);
	model::Numeric * cha14 = new model::Numeric;
	cha14->setValue(9);
	cs2->addElement(cha14);

	calc::ResultatCorrespondance *result=mvmcorrespondances->correspondre(cs1,cs2);
	CPPUNIT_ASSERT(fabs(result->distance-sqrt(3))<0.0001);
	CPPUNIT_ASSERT(result->correspondanceT2->at(0)==0);
	CPPUNIT_ASSERT(result->correspondanceT2->at(1)==1);
	CPPUNIT_ASSERT(result->correspondanceT2->at(2)==2);
	CPPUNIT_ASSERT(result->correspondanceT2->at(3)==5);
	CPPUNIT_ASSERT(result->correspondanceT2->at(4)==6);
}


CppUnit::Test *TestMvmcorrespondance::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestMvmcorrespondance");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestMvmcorrespondance>("Sequence_testGetSize",&TestMvmcorrespondance::TestCorrespondre));

	return suiteOfTests;
}



