/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 4
*/

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

        string computeReverseComplement(string sequence);
        string computeSequenceComplement(string sequence);
        bool isValidSequence(string sequence);
    
    private:
        GenStack<char> *nucleotides;
        string userSequence;

        char computeNucleotideComplement(char nucleotide);
};

#endif