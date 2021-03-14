#include <iostream>
#include "RPNCalc.h"

using namespace std;

int main(int argc, char **argv)
{
    // RPNCalc *calc = new RPNCalc();
    // calc->run();

    GenStack<int> *myStack = new GenStack<int>();
    myStack->push(0);
    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);
    myStack->push(5);
    myStack->push(6);
    myStack->push(7);
    myStack->push(8);
    myStack->push(9);
    myStack->printStack();
    cout << endl;
    myStack->clearStack();
    myStack->printStack();
    cout << endl;
    myStack->push(0);
    myStack->push(1);
    myStack->push(2);
    myStack->printStack();
    

    // delete calc;
    delete myStack;
    return 0;
}