#ifndef GENSTACK_H
#define GENSTACK_H

#include <exception>
#include "DoublyLinkedList.h"

using namespace std;

template <typename T>
class GenStack
{
    public:
        GenStack();
        ~GenStack();

        void push(T data);
        T pop();
        T peek();
        bool isEmpty();
        int getSize();

        void printStack();

    private:
        DoublyLinkedList<T> *linkedList;
        int stackSize;

};

template <typename T>
GenStack<T>::GenStack()
{
    linkedList = new DoublyLinkedList<T>();
    stackSize = 0;
}

template <typename T>
GenStack<T>::~GenStack()
{
    delete linkedList;
}

template <typename T>
void GenStack<T>::push(T data)
{
    linkedList->insertFront(data);
    stackSize++;
}

template <typename T>
T GenStack<T>::pop()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty, nothing to pop");
    }
    
    stackSize--;
    return linkedList->removeFront();
}

template <typename T>
T GenStack<T>::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty, nothing to peek");
    }

    return linkedList->getFrontData();
}

template <typename T>
bool GenStack<T>::isEmpty()
{
    return linkedList->isEmpty();
}

template <typename T>
int GenStack<T>::getSize()
{
    return stackSize;
}

template <typename T>
void GenStack<T>::printStack()
{
    return linkedList->printList();
}

#endif