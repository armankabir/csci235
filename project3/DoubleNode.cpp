/* 
Arman Kabir
Projext 2
Dr. Wole

This program implements the members of a node of a doubly-linked list.
*/
#include "DoubleNode.hpp"


//**************************************Default Constructor************************************************************//
template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : prevNode(nullptr), nextNode(nullptr){}       //default constructor
                                                                                //Initializer list to set both pointers to null

//********************************Paramaterized Constructor***********************************************************//
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& someItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr):
Item(someItem), nextNode(nextNodePtr), prevNode(prevNodePtr){}    //Paramerterized Constructor
                                                                //Initializer List sets all values to given parameter

//********************************getItem Method********************************************************************//
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem()const{
    return Item;                        //Returns item of node when called
}

//********************************setNext Method***********************************************************//
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr){
    nextNode = nextNodePtr;              //Sets the node to point at the nextNodePtr
}

//********************************setPrev Method**********************************************************//
template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prevNodePtr){
    prevNode = prevNodePtr;            //Sets node to point at prevNodePtr
}

//********************************getNext Method**********************************************************//
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext(){
    return nextNode;
}

//********************************getPrev Method**********************************************************//
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev(){
    return prevNode;
}
