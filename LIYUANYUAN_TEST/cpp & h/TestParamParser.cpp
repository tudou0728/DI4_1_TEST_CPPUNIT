#include "TestParamParser.h"

void TestParamParser::setUp()
{
	paramparser=new inout::ParamParser();
}

void TestParamParser::tearDown()
{
	delete paramparser;
}

void TestParamParser::testReadXML()
{
	//C:\Users\Administrator\Desktop\test1.xml
	try{
	std::vector<calc::Parametrage*> * s=(std::vector<calc::Parametrage*> *)paramparser->readXML("C:/Users/Administrator/Desktop/test1.xml");
	//CPPUNIT_ASSERT(s->at(0)->getS1Size()==2);
	//CPPUNIT_ASSERT(s->at(0)->getS2Size()==3);
	CPPUNIT_ASSERT(s->at(0)->getS1Weight(1)==2);
	//CPPUNIT_FAIL("lire fichier error");
	}
	catch(rapidxml::parse_error &e)
	{
		std::cerr<<e.what();
	}
}

CppUnit::Test *TestParamParser::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestParamParser");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestParamParser>("ParamParser_testReadXML",&TestParamParser::testReadXML));

	return suiteOfTests;
}