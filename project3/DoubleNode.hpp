/* 
Arman Kabir
Projext 2
Dr. Wole

Header file of node object in the doubly-linked list. Should have two pointers, one to the previous node
and one to the next node and a data member.
*/

#ifndef DOUBLE_NODE_HEADER
#define DOUBLE_NODE_HEADER

template <class ItemType>
class DoubleNode{
    private:
        ItemType Item;                                    //arbitrary item
        DoubleNode<ItemType>* nextNode;                 //Pointer to next node
        DoubleNode<ItemType>* prevNode;               //Pointer to prev node
        
    public:
        DoubleNode();                       //default constructor
        DoubleNode(const ItemType& someItem, DoubleNode<ItemType>* nextNodePtr = nullptr, DoubleNode<ItemType>* prevNodePtr = nullptr);   //Parameterized Constructor with default of setting previous and next pointer to null
        ItemType getItem() const;                                          //method to return data memeber
        void setNext(DoubleNode<ItemType>* nextNodePtr);               //Method that sets nextNode data member to point to next node of the list
        void setPrev(DoubleNode<ItemType>* prevNodePtr);             //Method that sets prevNode data member to point to the previous node of the list

        //Aditional methods not required for assignment 
        DoubleNode<ItemType>* getNext();
        DoubleNode<ItemType>* getPrev();

};

#include "DoubleNode.cpp"
#endif