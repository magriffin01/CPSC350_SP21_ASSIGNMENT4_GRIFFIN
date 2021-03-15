/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 4
*/

#include "FileProcessor.h"

FileProcessor::FileProcessor()
{
    dna = new DNAComplement();
}

FileProcessor::~FileProcessor()
{
    delete dna;
}

void FileProcessor::processFile(string inputFile, string outputFile)
{
    openInputFile(inputFile);
    readInputFile();
    closeInputFile(inputFile);
    openOutputFile(outputFile);
    writeOutputFile();
    closeOutputFile(outputFile);
}

void FileProcessor::readInputFile()
{
    string sequence;
    int i = 1;

    getline(inputStream, sequence);

    while (!inputStream.fail())
    {
        if (!dna->isValidSequence(sequence))
        {
            cout << "Invalid sequence in the input file on line: " << i << " ....SKIPPING" << endl;
            getline(inputStream, sequence);
            ++i;
            continue;
        }
        dnaComplements += "Complement: " + dna->computeSequenceComplement(sequence) + "\n";
        dnaComplements += "Reverse Complement: " + dna->computeReverseComplement(sequence) + "\n";
        dnaComplements += "\n";
        ++i;
        getline(inputStream, sequence);
    }

    if (!inputStream.eof())
    {
        cout << "Input failure before reaching end of file." << endl;
    }
}

void FileProcessor::writeOutputFile()
{
    outputStream << dnaComplements;
}

void FileProcessor::openInputFile(string inputFile)
{
    cout << "Attempting to open " << inputFile << endl;

    inputStream.open(inputFile);
    
    if (!inputStream.is_open())
    {
        cout << "Could not open " << inputFile << endl;
    }
    else
    {
        cout << "Successfully opened " << inputFile << endl;
    }
}

void FileProcessor::openOutputFile(string outputFile)
{
    cout << "Attempting to open " << outputFile << endl;

    outputStream.open(outputFile);

    if (!outputStream.is_open())
    {
        cout << "Could not open " << outputFile << endl;
    }
    else
    {
        cout << "Successfully opened " << outputFile << endl;
    }
}

void FileProcessor::closeInputFile(string inputFile)
{
    cout << "Closing " << inputFile << endl;

    inputStream.close();
}

void FileProcessor::closeOutputFile(string outputFile)
{
    cout << "Closing " << outputFile << endl;

    outputStream.close();
}