#include <iostream>
#include "RPNCalc.h"
#include "FileProcessor.h"

using namespace std;

int main(int argc, char **argv)
{
    // RPNCalc *calc = new RPNCalc();
    // calc->run();

    // DNAComplement *dna = new DNAComplement();
    // dna->run();

    FileProcessor *fileProcessor = new FileProcessor();
    fileProcessor->processFile("input.txt", "output.txt");
    
    // delete calc;
    // delete dna;
    delete fileProcessor;
    return 0;
}