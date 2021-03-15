#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include <iostream>
#include <string>
#include <exception>
#include "GenStack.h"

using namespace std;

class DNAComplement
{
    public:
        DNAComplement();
        ~DNAComplement();

        void run();
        string computeReverseComplement(string sequence);
        string computeSequenceComplement(string sequence);

        // Compute complement
        // Compute reverse complement
    
    private:
        GenStack<char> *nucleotides;
        string userSequence;

        bool isValidSequence();
        char computeNucleotideComplement(char nucleotide);

        // Temporary for testing the function of the class, convert for FILES after
        void getUserSequence();

};

#endif