#include "TestCommandLineOutput.h"

void TestCommandLineOutput::setUp()
{
	model::Sequence *cs1=new model::Sequence();
	cs1->setUid("001");
	model::Character * cha = new model::Character;
	cha->setValue('a');
	cs1->addElement(cha);
	model::Character * cha2 = new model::Character;
	cha2->setValue('d');
	cs1->addElement(cha2);
	model::Character * cha6 = new model::Character;
	cha6->setValue('e');
	cs1->addElement(cha6);
	model::Character * cha7 = new model::Character;
	cha7->setValue('f');
	cs1->addElement(cha7);

	model::Sequence *cs2=new model::Sequence();
	cs2->setUid("002");
	model::Character * cha3 = new model::Character;
	cha3->setValue('c');
	cs2->addElement(cha3);
	model::Character * cha4 = new model::Character;
	cha4->setValue('e');
	cs2->addElement(cha4);
	model::Character * cha5 = new model::Character;
	cha5->setValue('m');
	cs2->addElement(cha5);
	model::Character * cha8 = new model::Character;
	cha8->setValue('n');
	cs2->addElement(cha8);
	model::Character * cha9 = new model::Character;
	cha9->setValue('f');
	cs2->addElement(cha9);

	calc::Correspondance * rc=0;
	rc=new calc::LevenstheinCorrespondance(1,1,1);

	commandeLineOutput=new inout::CommandLineOutput(cs1,cs2,rc);
	
}

void TestCommandLineOutput::tearDown()
{
	delete commandeLineOutput;
}

void TestCommandLineOutput::testFormat()
{
	string format=commandeLineOutput->format();
	string result="Result \nDistance = 4";
	CPPUNIT_ASSERT(format.find(result)<format.length());
}

CppUnit::Test *TestCommandLineOutput::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestCommandLineOutput");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCommandLineOutput>("CommandLineOutput_testFormat",&TestCommandLineOutput::testFormat));

	return suiteOfTests;
}