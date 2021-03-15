#include "FileProcessor.h"

FileProcessor::FileProcessor()
{
    dna = new DNAComplement();
}

FileProcessor::~FileProcessor()
{
    delete dna;
}

// Takes a string for the input file and output file, reads the english file, and writes the translation to the output file
void FileProcessor::processFile(string inputFile, string outputFile)
{
    openInputFile(inputFile);
    readInputFile();
    closeInputFile(inputFile);
    openOutputFile(outputFile);
    writeOutputFile();
    closeOutputFile(outputFile);
}

// Reads the input file and puts the english text into a string
void FileProcessor::readInputFile()
{
    string sequence;
    int i = 1;

    getline(inputStream, sequence);

    while (!inputStream.fail())
    {
        // FIXME: Delete before turning in
        // for (int i = 0; i < sequence.size(); ++i)
        // {
        //     if (sequence[i] == '\r')
        //     {
        //         cout << "carriage return found" << endl;
        //     }
        // }
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

// Writes to the output file from the tutneseText string
void FileProcessor::writeOutputFile()
{
    outputStream << dnaComplements;
}

// Takes a string for the inputFile and attempts to open it
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

// Takes a string for the outputFile and attempts to open it
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

// Takes a string for the inputFile and attempts to close it
void FileProcessor::closeInputFile(string inputFile)
{
    cout << "Closing " << inputFile << endl;

    inputStream.close();
}

// Takes a string for the outputFile and attempts to close it
void FileProcessor::closeOutputFile(string outputFile)
{
    cout << "Closing " << outputFile << endl;

    outputStream.close();
}