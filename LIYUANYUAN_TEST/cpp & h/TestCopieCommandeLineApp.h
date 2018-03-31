#include "commandlineapplication.h"

class TestCopieCommandeLineApp:public commandline::CommandLineApplication
{
	public:
		TestCopieCommandeLineApp(int argc, char *argv[]):CommandLineApplication(argc,argv){};
		int testGetICLAargv();
		vector<char *> testGetVCLAoperateurs();
		vector<char *> testGetVCLAoperandes();
		void testChechParam();
};