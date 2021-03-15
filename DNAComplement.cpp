#include "DNAComplement.h"

DNAComplement::DNAComplement()
{
    nucleotides = new GenStack<char>();
}

DNAComplement::~DNAComplement()
{
    delete nucleotides;
}

bool DNAComplement::isValidSequence(string sequence)
{
    for (int i = 0; i < sequence.size(); ++i)
    {
        if (sequence[i] == '\r')
        {
            continue;
        }
        if ((sequence[i] != 'A') && (sequence[i] != 'C') && (sequence[i] != 'T') && (sequence[i] != 'G'))
        {
            return false;
        }
    }

    return true;
}

string DNAComplement::computeReverseComplement(string sequence)
{
    string reversedSequence = "";

    for (int i = 0; i < sequence.size(); ++i)
    {
        nucleotides->push(sequence[i]);
    }
    for (int i = 0; i < sequence.size(); ++i)
    {
        reversedSequence += nucleotides->pop();
    }


    return computeSequenceComplement(reversedSequence);
}

string DNAComplement::computeSequenceComplement(string sequence)
{
    string sequenceComplement = "";

    for (int i = 0; i < sequence.size(); ++i)
    {
        if (sequence[i] == '\r')
        {
            continue;
        }
        sequenceComplement += computeNucleotideComplement(sequence[i]);
    }

    return sequenceComplement;
}

char DNAComplement::computeNucleotideComplement(char nucleotide)
{
    char complement;
    
    switch (nucleotide)
    {
        case 'A':
            complement = 'T';
            break;

        case 'C':
            complement = 'G';
            break;

        case 'T':
            complement = 'A';
            break;

        case 'G':
            complement = 'C';
            break;

        default:
            complement = '@';
            break;
    }

    return complement;
}