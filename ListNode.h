/*
# Name: Mark Griffin
# ID Number: 2340502
# Email: magriffin@chapman.edu
# Course: CPSC350-01
# Assignment: Assignment 4
*/

#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <typename T>
class ListNode
{
    public:
        ListNode();
        ListNode(T data);
        ~ListNode();
        
        ListNode *next;
        ListNode *prev;
        T data;

    private:

};

template <typename T>
ListNode<T>::ListNode()
{

}

template <typename T>
ListNode<T>::ListNode(T data)
{
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

template <typename T>
ListNode<T>::~ListNode()
{
    next = nullptr;
    prev = nullptr;
}


#endif