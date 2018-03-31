#include "TestLevenstheinCorrespondance.h"

void TestLevenstheincorrespondance::setUp()
{
	levenstheinCorrespondance=new calc::LevenstheinCorrespondance();
}

void TestLevenstheincorrespondance::tearDown()
{
	delete levenstheinCorrespondance;
}

void TestLevenstheincorrespondance::testCorrespondre()
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

	calc::ResultatCorrespondance * rc=levenstheinCorrespondance->correspondre(cs1,cs2);
	//int i=0;
	//std::cout<<rc->correspondanceT2->size()<<std::endl;
	/**
	while(i<rc->correspondanceT1->size())
	{
		std::cout<<rc->correspondanceT1->at(i)<<std::endl;
		i++;
	}*/
	CPPUNIT_ASSERT(rc->distance==4);
	delete cs1,cs2;
}

CppUnit::Test *TestLevenstheincorrespondance::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestLevenstheincorrespondance");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestLevenstheincorrespondance>("Levenstheincorrespondance_testCorrespondre",&TestLevenstheincorrespondance::testCorrespondre));
	//suiteOfTests->addTest(new CppUnit::TestCaller<TestLevenstheincorrespondance>("Sequence_testGetSetAddElement",&TestLevenstheincorrespondance::testGetSetAddElement));

	return suiteOfTests;
}