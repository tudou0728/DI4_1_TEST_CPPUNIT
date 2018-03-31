#include "TestParametrage.h"

void TestParametrage::setUp()
{
	parametrage=new calc::Parametrage(2,1);
}

void TestParametrage::tearDown()
{
	delete parametrage;
}

void TestParametrage::TestGetSetSize()
{
	CPPUNIT_ASSERT(parametrage->getS1Size()==2);
	CPPUNIT_ASSERT(parametrage->getS2Size()==1);
	parametrage->setS1Size(5);
	parametrage->setS2Size(6);
	CPPUNIT_ASSERT(parametrage->getS1Size()==5);
	CPPUNIT_ASSERT(parametrage->getS2Size()==6);
}

void TestParametrage::TestGetSetWeight()
{
	parametrage->setS1Size(5);
	parametrage->setS2Size(6);
	parametrage->setS1Weight(2,0.6f);
	CPPUNIT_ASSERT(parametrage->getS1Weight(2)==0.6f);
	parametrage->setS2Weight(4,0.8f);
	CPPUNIT_ASSERT(parametrage->getS2Weight(4)==0.8f);
}

void TestParametrage::TestGetSetWeightMatrice()
{
	parametrage->setS1Size(2);
	parametrage->setS2Size(3);
	parametrage->setMatrixWeight(1,1,0.8f);
	CPPUNIT_ASSERT(parametrage->getMatrixWeight(1,1)==0.8f);
}

CppUnit::Test *TestParametrage::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestParametrage");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestParametrage>("Parametrage_TestGetSetSize",&TestParametrage::TestGetSetSize));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestParametrage>("Parametrage_TestGetSetWeight",&TestParametrage::TestGetSetWeight));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestParametrage>("Parametrage_TestGetSetWeightMatrice",&TestParametrage::TestGetSetWeightMatrice));

	return suiteOfTests;
}
