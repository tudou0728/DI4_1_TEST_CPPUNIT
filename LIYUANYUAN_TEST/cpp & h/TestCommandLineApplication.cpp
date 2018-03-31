#include "TestCommandLineApplication.h"

void TestCommandlineapplication::setUp()
{
	testCopieCommandeLineApp= new TestCopieCommandeLineApp(__argc,__argv);
}

void TestCommandlineapplication::tearDown()
{
	delete testCopieCommandeLineApp;
}


void TestCommandlineapplication::testCheckParams()
{	
	//char *s[]={"E:\\test.exe","-sequences","C:\\Users\\Administrator\\Desktop\\test1.csv","C:\\Users\\Administrator\\Desktop\\test2.csv","-method","-lvn"};
	//TestCopieCommandeLineApp *testCopieCommandeLineApp=new TestCopieCommandeLineApp(argc,argv);
	testCopieCommandeLineApp->testChechParam();
	int size=testCopieCommandeLineApp->testGetICLAargv();
	CPPUNIT_ASSERT(size==6);

	char *p=testCopieCommandeLineApp->testGetVCLAoperateurs()[0];
	string s=p;
	CPPUNIT_ASSERT(s.compare("-sequences")==0);
	char *p2=testCopieCommandeLineApp->testGetVCLAoperateurs()[1];
	string s2=p2;
	CPPUNIT_ASSERT(s2.compare("-method")==0);
	char *p3=testCopieCommandeLineApp->testGetVCLAoperandes()[0];
	string s3=p3;
	CPPUNIT_ASSERT(s3.compare("-lvn")==0);
}

CppUnit::Test *TestCommandlineapplication::Suit()
{
	CppUnit::TestSuite *suiteOfTests=new CppUnit::TestSuite("TestCommandlineapplication");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestCommandlineapplication>("Commandlineapplication_testCheckParams",&TestCommandlineapplication::testCheckParams));
	//suiteOfTests->addTest(new CppUnit::TestCaller<TestCommandlineapplication>("Sequence_testGetSetAddElement",&TestCommandlineapplication::testGetSetAddElement));

	return suiteOfTests;
}