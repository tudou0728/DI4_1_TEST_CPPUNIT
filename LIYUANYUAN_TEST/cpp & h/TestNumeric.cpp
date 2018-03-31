#include "TestNumeric.h"

void TestNumeric::setUp()
{
	numeric=new model::Numeric();
}

void TestNumeric::tearDown()
{
	delete numeric;
}

void TestNumeric::TestGetSetValue()
{
	numeric->setValue(10.16f);
	CPPUNIT_ASSERT(numeric->getValue()==10.16f);

	model::Numeric* n1=new model::Numeric();
	n1->setValue(10);
	CPPUNIT_ASSERT_MESSAGE("TestGetSetValue - error1",n1->getValue()==(float)10);
	delete n1;
}

void TestNumeric::TestToString()
{
	numeric->setValue(3.2f);
	CPPUNIT_ASSERT(numeric->toString()=="3.2");
}

void TestNumeric::TestDistance()
{
	model::Numeric* n1=new model::Numeric();
	n1->setValue(7.04f);
	model::Numeric* n2=new model::Numeric();
	n2->setValue(12.19f);
	float d1=numeric->distance(n1,n2);
	//CPPUNIT_ASSERT(d1==5.15);
	CPPUNIT_ASSERT(fabs(d1-5.15)<0.000001); //多一个零就过不去了

	model::Numeric* n3=new model::Numeric();
	n3->setValue(7.04f);
	float d2=numeric->distance(n1,n3);
	CPPUNIT_ASSERT(d2==(float)0);

	model::Numeric* n4=new model::Numeric();
	n4->setValue(8.0);
	float d3=numeric->distance(n1,n4);
	CPPUNIT_ASSERT(fabs(d3-0.96)<0.0000001);//多一个零就过不去了
	delete n1;
	delete n2;
	delete n3;
	delete n4;
}

void TestNumeric::TestCopy()
{
	numeric->setValue(3.2f);
	model::Numeric* n1=(model::Numeric*)numeric->copy();
	CPPUNIT_ASSERT(n1->getValue()==3.2f);
	delete n1;
}

CppUnit::Test * TestNumeric::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestNumeric");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestNumeric>("Numeric_TestGetSetValue",&TestNumeric::TestGetSetValue));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestNumeric>("Numeric_TestToString",&TestNumeric::TestToString));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestNumeric>("Numeric_TestDistance",&TestNumeric::TestDistance));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestNumeric>("Numeric_TestDistance",&TestNumeric::TestCopy));

	return suiteOfTests;
}