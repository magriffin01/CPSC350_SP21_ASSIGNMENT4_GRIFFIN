#ifndef RPNCALC_H
#define RPNCALC_H

#include <iostream>
#include <string>
#include "GenStack.h"

using namespace std;

class RPNCalc
{
    public:
        RPNCalc();
        ~RPNCalc();

        void getUserInput();
        // Handle Input
        // Handle Operator
        // Handle Operand
        // Perform Calculation
        // Display prompt
        // Run the Calculator

    private:
        GenStack<int> *operandStack;
        string input;

        bool isOperand(string input);
        bool isOperator(string input);

};

#endif