#include "RPNCalc.h"

RPNCalc::RPNCalc()
{
    operandStack = new GenStack<int>();
}

RPNCalc::~RPNCalc()
{
    delete operandStack;
}

void RPNCalc::getUserInput()
{
    cout << "Input an operand or an operator:" << endl << ">>";
    cin >> input;

    while (!isOperand(input) && !isOperator(input))
    {
        cout << "Not a valid input, input an integer or an operand:" << endl << ">>";
        cin >> input;
    }
}

bool RPNCalc::isOperand(string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }

    return true;
}

bool RPNCalc::isOperator(string input)
{
    string operators[] = {"+", "-", "*", "/", "%"};

    for (int i = 0; i < 5; ++i)
    {
        if (input == operators[i])
        {
            return true;
        }
    }

    return false;
}