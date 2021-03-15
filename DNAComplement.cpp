#include "DNAComplement.h"

DNAComplement::DNAComplement()
{
    nucleotides = new GenStack<char>();
}

DNAComplement::~DNAComplement()
{
    delete nucleotides;
}

void DNAComplement::run()
{
    cout << "You have selected the DNA Complement program." << endl << endl;

    getUserSequence();
    cout << "Complement: " << computeSequenceComplement(userSequence) << endl;
    cout << "Reverse Complement: " << computeReverseComplement() << endl;
}

bool DNAComplement::isValidSequence()
{
    for (int i = 0; i < userSequence.size(); ++i)
    {
        if ((userSequence[i] != 'A') && (userSequence[i] != 'C') && (userSequence[i] != 'T') && (userSequence[i] != 'G'))
        {
            return false;
        }
    }

    return true;
}

string DNAComplement::computeReverseComplement()
{
    string reversedSequence = "";

    for (int i = 0; i < userSequence.size(); ++i)
    {
        nucleotides->push(userSequence[i]);
    }
    for (int i = 0; i < userSequence.size(); ++i)
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
            complement = '!';
            break;
    }

    return complement;
}

void DNAComplement::getUserSequence()
{
    cout << "Enter a DNA sequence:" << endl;
    cin >> userSequence;

    while (!isValidSequence())
    {
        cout << "Not a valid sequence, please input a valid sequence:" << endl;
        cin >> userSequence;
    }
}