#include <stdio.h>
#include "InOut.h"
#include "CommandLine.h"
#include "Exc.h"
#include <iostream>
#include <fstream>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

#include "TestSequence.h""
#include "TestSequenceParser.h"
#include "TestLevenstheinCorrespondance.h"
#include "TestCommandLineApplication.h"
#include "TestCharacter.h"
#include "TestNumeric.h"
#include "TestCharacteristicVector.h"
#include "TestLCScorrespondance.h"
#include "TestDTWCorrespondance.h"
#include "TestParametrage.h"
#include "TestMvmCorrespondance.h"
#include "TestParamParser.h"
#include "TestCommandLineOutput.h"


using namespace std;

//Auteur: LI YUANYUAN
int main(int argc, char *argv[])
{
	
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(TestCharacter::Suit());
	runner.addTest(TestNumeric::Suit());
	runner.addTest(TestCharacteristicvector::Suit());
	runner.addTest(TestSequence::Suit());
	runner.addTest(TestSequenceParser::Suit());
	runner.addTest(TestParametrage::Suit());
	runner.addTest(TestLevenstheincorrespondance::Suit());
	runner.addTest(TestLcscorrespondance::Suit());
	runner.addTest(TestDTWCorrespondance::Suit());	
	runner.addTest(TestMvmcorrespondance::Suit());
	runner.addTest(TestCommandlineapplication::Suit());	
	runner.addTest(TestParamParser::Suit());//il y  a des probleme pendant lire le fichier
	runner.addTest(TestCommandLineOutput::Suit());

	bool result;
	result=runner.run();
	std::cout<<result<<std::endl;

	system("pause");
    //return 0;
	//return result ? 0 : 1;
}

/**
int main(int argc, char *argv[])
{
	commandline::CommandLineApplication c(argc,argv);
    try{
       std::cout<<"this is the result of the test_main:"<<std::endl;
	    std::cout<<"\r"<<std::endl;
		c.run();
    }
    catch(exc::SequenceMatchingException & e)
    {
        std::cout<<e.what()<<std::endl;
		std::cout<<"this is the error of the test_main"<<std::endl;
        std::cout<<"Gestion des param¨¨tres toolbox :\n\narguments :\n\n-sequences <fichier1.csv> <fichier2.csv>\n\nPermet d indiquer les s¨¦quences d entr¨¦e\n\n-method lvn|lcd|dtw|mvmm\n\nPermet d indiquer la m¨¦thode ¨¤ utiliser\n\n-patron <name> <fichier1.csv> <fichier2.csv>\n\nPermet de cr¨¦er un patron\n\n-sequences <fichier1.csv> <fichier2.csv> -param <fichier.xml>\n\nPermet d utiliser un fichier de param¨¨tres cr¨¦¨¦ auparavant\n\n-method lvn  --costs 1 1 1\n\nCout d ajout suppression substitution levensthein"<<std::endl;
    }
	system("pause");
    return 0;
}*/