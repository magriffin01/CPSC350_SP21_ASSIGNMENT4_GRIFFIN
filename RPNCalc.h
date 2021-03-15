/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 4
*/

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