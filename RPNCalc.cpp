#include "RPNCalc.h"

RPNCalc::RPNCalc()
{
    operandStack = new GenStack<int>();
}

RPNCalc::~RPNCalc()
{
    delete operandStack;
}

void RPNCalc::run()
{
    cout << "You have selected the RPN calculator. Enter \"q\" to quit the program." << endl << endl;
    getUserInput();
    while (input != "q")
    {
        try
        {
            handleUserInput(input);
        }
        catch (runtime_error &exception)
        {
            cout << exception.what() << endl;
            cout << "Cannot compute entered operation" << endl;
            clearCalculatorHistory();
        }
        getUserInput();
    }
}

void RPNCalc::getUserInput()
{
    cout << "Input an operand or an operator, or enter \"c\" to clear the calculator:" << endl;
    cin >> input;

    while (!isOperand(input) && !isOperator(input) && (input != "q") && (input != "c"))
    {
        cout << "Not a valid input, input an integer or an operand:" << endl;
        cin >> input;
    }
}

void RPNCalc::handleUserInput(string input)
{
    if (isOperator(input))
    {
        performOperation(input);
    }
    else if (isOperand(input))
    {
        operandStack->push(stoi(input));
    }
    else if (input == "c")
    {
        clearCalculatorHistory();
    }
}

bool RPNCalc::isOperand(string input)
{
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[0] == '-')
        {
            continue;
        }
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

void RPNCalc::performOperation(string input)
{
    int leftValue;
    int rightValue;
    int result;

    rightValue = operandStack->pop();
    leftValue = operandStack->pop();

    if (input == "+")
    {
        result = leftValue + rightValue;
        operandStack->push(result);
    }
    else if (input == "-")
    {
        result = leftValue - rightValue;
        operandStack->push(result);
    }
    else if (input == "*")
    {
        result = leftValue * rightValue;
        operandStack->push(result);
    }
    else if (input == "/")
    {
        if (rightValue == 0)
        {
            throw runtime_error("0 entered as divisor");
        }

        result = leftValue / rightValue;
        operandStack->push(result);
    }
    else if (input == "%")
    {
        if (rightValue == 0)
        {
            throw runtime_error("0 entered as divisor");
        }
        result = leftValue % rightValue;
        operandStack->push(result);
    }
    else 
    {
        result = -1;
    }

    cout << "Calculating " << leftValue << " " << input << " " << rightValue << endl;
    cout << "Result: " << result << endl;
}

void RPNCalc::clearCalculatorHistory()
{
    operandStack->clearStack();
    cout << ".....Calculator cleared" << endl;
}