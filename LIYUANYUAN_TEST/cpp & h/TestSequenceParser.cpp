#include "TestSequenceParser.h"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"

void TestSequenceParser::setUp()
{
	sequenceParser=new inout::SequenceParser();
}

void TestSequenceParser::tearDown()
{
	delete sequenceParser;
}

void TestSequenceParser::testReadCSV()
{
	string filepath ="C:\\Users\\Administrator\\Desktop\\test1.csv";
	void * test =sequenceParser->readCSV(filepath);
	rapidxml::xml_document<>  *docr = (rapidxml::xml_document<char> *)test;
	// test sequence
	CPPUNIT_ASSERT(docr->first_node("Sequences")!= 0);

	// test the type
	rapidxml::xml_node<> * type_node;
	type_node = docr->first_node("Type");
	CPPUNIT_ASSERT(type_node!= 0);

	// test the type attribute
	rapidxml::xml_attribute<> * type_attr = type_node->first_attribute("id");
	CPPUNIT_ASSERT(type_attr!= 0);

	//test the sequence
	rapidxml::xml_node<> * seq_node = docr->first_node("Sequence");
	rapidxml::xml_attribute<> * id_attr = seq_node->first_attribute("idS");
	CPPUNIT_ASSERT(seq_node!= 0);
	CPPUNIT_ASSERT(id_attr!= 0);

	//test numeric
	//int type = atoi(type_attr->value());
	//CPPUNIT_ASSERT(type==1);

	//test character
	int type = atoi(type_attr->value());
	CPPUNIT_ASSERT(type==0);

	//test elements
	rapidxml::xml_node<> * elt_node = seq_node->first_node("Element");
	rapidxml::xml_attribute<> * val_attr = elt_node->first_attribute("value");
	char b=val_attr->value()[0];//character
	CPPUNIT_ASSERT(b=='a');

	//numeric
	//char * value1=val_attr->value();
	//CPPUNIT_ASSERT(atof(value1)==20);
	

	docr->clear();
    delete docr;
}

void TestSequenceParser::testReadXML()
{
	string filepath ="C:\\Users\\Administrator\\Desktop\\test1.csv";
	void * testCsv=sequenceParser->readCSV(filepath);
	 std::vector<model::Sequence*> *  test=(std::vector<model::Sequence*> *)sequenceParser->readXML(testCsv);
	 //std::cout<< test->at(0)->toString()<<std::endl;
	 CPPUNIT_ASSERT(test->at(0)->toString()=="afgfihe");
}

CppUnit::Test *TestSequenceParser::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestSequenceParser");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestSequenceParser>("SequenceParser_testCheckDocument",&TestSequenceParser::testReadCSV));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestSequenceParser>("SequenceParser_testReadXMLt",&TestSequenceParser::testReadXML));

	return suiteOfTests;
}