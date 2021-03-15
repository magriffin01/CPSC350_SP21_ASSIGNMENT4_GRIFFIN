/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 4
*/

#include <iostream>
#include "RPNCalc.h"
#include "FileProcessor.h"

using namespace std;

int main(int argc, char **argv)
{  
    string arg = argv[1];
    
    if (arg == "RPN")
    {
        RPNCalc *calc = new RPNCalc();
        calc->run();

        delete calc;
    }
    else if (arg == "DNA")
    {   string filePath;
        cout << "Enter the filepath for the DNA sequence file: ";
        cin >> filePath;

        FileProcessor *fileProcessor = new FileProcessor();
        fileProcessor->processFile(filePath, "dnaoutput.txt");

        delete fileProcessor;
    }
    else
    {
        cout << "Invalid command line argument. Either type \"RPN\" or \"DNA\"" << endl;
    }

    return 0;
}