#include <iostream>
#include "RPNCalc.h"
#include "DNAComplement.h"

using namespace std;

int main(int argc, char **argv)
{
    // RPNCalc *calc = new RPNCalc();
    // calc->run();

    DNAComplement *dna = new DNAComplement();
    dna->run();
    
    // delete calc;
    return 0;
}