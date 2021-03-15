#ifndef RPNCALC_H
#define RPNCALC_H

#include <iostream>
#include <string>
#include <exception>
#include "GenStack.h"

using namespace std;

class RPNCalc
{
    public:
        RPNCalc();
        ~RPNCalc();

        void run();
        
        // Handle Input
        // Handle Operator
        // Handle Operand
        // Perform Calculation
        // Display prompt
        // Run the Calculator

    private:
        GenStack<int> *operandStack;
        string input;

        void getUserInput();
        void handleUserInput(string input);
        bool isOperand(string input);
        bool isOperator(string input);
        void performOperation(string input);
        void clearCalculatorHistory();

};

#endif