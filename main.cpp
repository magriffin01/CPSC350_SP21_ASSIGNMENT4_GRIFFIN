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

    return 0;
}