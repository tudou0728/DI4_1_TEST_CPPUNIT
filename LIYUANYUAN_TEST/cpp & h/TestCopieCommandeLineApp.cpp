#include "TestCopieCommandeLineApp.h"


int TestCopieCommandeLineApp::testGetICLAargv()
{
	return this->iCLAargv;
}

vector<char *> TestCopieCommandeLineApp::testGetVCLAoperandes()
{
	return this->vCLAoperandes;
}

vector<char *> TestCopieCommandeLineApp::testGetVCLAoperateurs()
{
	return this->vCLAoperateurs;
}

void TestCopieCommandeLineApp::testChechParam()
{
	return this->checkParams();
}