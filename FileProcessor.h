#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include "DNAComplement.h"

using namespace std;

class FileProcessor
{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string inputFile, string outputFile);
        
    private:
        void openInputFile(string inputFile);
        void readInputFile();
        void closeInputFile(string inputFile);
        void openOutputFile(string outputFile);
        void writeOutputFile();
        void closeOutputFile(string outputFile);
        ifstream inputStream;
        ofstream outputStream;
        DNAComplement *dna;
        string dnaComplements = "";
};

#endif