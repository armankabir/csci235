/* 
Arman Kabir
Projext 2
Dr. Wole

This program is the implementation file of a doubly-linked list. 
*/
#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
#include "DoubleNode.hpp"
#include <iostream>
template<class ItemType>
class DoublyLinkedList{
    private:
        DoubleNode<ItemType>* headPtr;
        int itemCount;
    public:
        DoublyLinkedList();                                                                   //default constructor
        DoublyLinkedList(DoublyLinkedList<ItemType> &copyList);                             //Copy Constructor
        ~DoublyLinkedList();                                                              //Destructor
        bool insert(const ItemType& item, const int& position);                         //insert item at index position in list
        bool remove(const int& position);                                             //remove the node at index position
        int getSize() const;                                                        //return the number of the nodes in the list    
        DoubleNode<ItemType>* getHeadPtr() const;                                 //return a copy of the hearPtr
        DoubleNode<ItemType>* getAtPos(const int& pos) const;                   //returns a pointer to the node located at pos
        bool isEmpty() const;                                                 //returns whether the list is empty   *****TESTED******
        void clear();                                                       //clears the list
        void display() const;                                             //prints the contents of the list in order
        void displayBackwards() const;                                  //prints the contents of the list backwards.

        DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list);    //alters the calling list to be 
                                                                                          //the interleaved list of the original and 
                                                                                        //parameter lists

};
#include "DoublyLinkedList.cpp"

#endif