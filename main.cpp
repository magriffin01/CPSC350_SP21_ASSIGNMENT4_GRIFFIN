#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char **argv)
{
    DoublyLinkedList<int>* linkedList = new DoublyLinkedList<int>();
    linkedList->insertFront(3);
    linkedList->insertFront(2);
    linkedList->printList();
    linkedList->insertFront(10);
    linkedList->printList();
    linkedList->removeFront();
    linkedList->printList();
    linkedList->removeFront();
    linkedList->printList();
    cout << linkedList->getFrontData() << endl;
    linkedList->printList();
    cout << linkedList->getSize() << endl;


    delete linkedList;
    return 0;
}