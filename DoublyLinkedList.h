#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <exception>
#include "ListNode.h"

using namespace std;

template <typename T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertFront(T data);
        T removeFront();
        bool isEmpty();
        int getSize();
        T getFrontData();
        void printList();

    private:
        ListNode<T> *head;
        ListNode<T> *tail;
        int listSize;

};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    listSize = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        ListNode<T> *next = head->next;
        delete head;
        head = next;
    }

    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T data)
{
    ListNode<T> *newNode = new ListNode<T>(data);

    if (listSize == 0)
    {
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
    }

    head = newNode;
    listSize++;
}

template <typename T>
T DoublyLinkedList<T>::removeFront()
{
    ListNode<T> *tempNode = head;

    if (isEmpty())
    {
        throw runtime_error("List is empty, cannot remove");
    }

    if (head->next == nullptr)
    {
        tail = nullptr;
    }
    else
    {
        head->next->prev = nullptr;
    }

    head = head->next;
    tempNode->next = nullptr;
    T data = tempNode->data;
    delete tempNode;
    listSize--;
    return data;
}

template <typename T>
T DoublyLinkedList<T>::getFrontData()
{
    if (isEmpty())
    {
        throw runtime_error("List is empty, nothing to get");
    }
    return head->data;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return (listSize == 0);
}

template <typename T>
int DoublyLinkedList<T>::getSize()
{
    return listSize;
}

template <typename T>
void DoublyLinkedList<T>::printList()
{
    ListNode<T> *currentNode = head;
    int i = 0;
    while (currentNode != nullptr)
    {
        cout << "Element at location " << i << " is " << currentNode->data << endl;
        currentNode = currentNode->next;
        ++i;
    }
}


#endif