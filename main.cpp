#include <iostream>
#include "GenStack.h"

using namespace std;

int main(int argc, char **argv)
{
    // DoublyLinkedList<int>* linkedList = new DoublyLinkedList<int>();
    // linkedList->insertFront(3);
    // linkedList->insertFront(2);
    // linkedList->printList();
    // linkedList->insertFront(10);
    // linkedList->printList();
    // linkedList->removeFront();
    // linkedList->printList();
    // linkedList->removeFront();
    // linkedList->printList();
    // cout << linkedList->getFrontData() << endl;
    // linkedList->printList();
    // cout << linkedList->getSize() << endl;

    GenStack<int> *myStack = new GenStack<int>();
    myStack->push(5);
    myStack->push(8);
    myStack->push(-2);
    myStack->push(193);
    cout << "PEEKING: " << myStack->peek() << endl;
    while (!myStack->isEmpty())
    {
        cout << "POPPING: " << myStack->pop() << endl;
    }
    cout << "POPPING: " << myStack->pop() << endl;
    myStack->printStack();


    // delete linkedList;
    return 0;
}