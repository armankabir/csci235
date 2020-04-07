/* 
Arman Kabir
Projext 2
Dr. Wole

This program is the implementation file of a doubly-linked list. 
*/

#include "DoublyLinkedList.hpp"

//********************************Default Constructor***********************************************************//
//TESTED
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0){}     //end default constructor
                                                                                    //Initializer list to set headPtr to null and itemCount to 0

//********************************Copy Constructor*************************************************************//
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(DoublyLinkedList<ItemType> &copyList)  :
headPtr(copyList.headPtr), itemCount(copyList.itemCount){}          //end Copy Construcor
                                                                  //Initializer list to set headPtr to headPtr of copyList
                                                                //and itemCount to itemCount of copy list. 

//********************************Destructor********************************************************************//
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() {       
    clear();            //calls clear fucntion upon destruction
    //std::cout << "destroying the list....." << std::endl << "Success" << std::endl;
} //end destructor

//********************************insert Method********************************************************************//
//This method will insert a node with an arbritrary data item and set it at a node in a given position of the list//
//TESTED!!! FINALLY WORKS :-]
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position){
        if(position < 1 || position > itemCount + 1) return false;   //List starts at 1, so position must be greater than 1 and the position cannot be 
                                                                    //greater than the itemCount+1. If the position isn't greater than itemCount+1, the node would be added out of order 
                                                            
        DoubleNode<ItemType>* newDoubleNode = new DoubleNode<ItemType>(item);       //allocated new DoubleNode on heap. This is the node to be inserted
        
        //Case if postion is 1 and the list is empty,, this would be the headPtr
        if(position == 1 && isEmpty()) {    
            headPtr = newDoubleNode;           //Changes headPtr to the DoubleNode on heap
            //delete newDoubleNode;          //Delete DoubleNode on heap to prevent memory leak
            itemCount++;              //item is added so must increment
            return true;   
        }//end if

        //Inserting at front of list, when the list already contains elements
        if(position == 1){       
            newDoubleNode -> setNext(headPtr);      //sets the next element in list as the head pointer. This makes this node now the first in the list
            headPtr = newDoubleNode;
            itemCount++;
            return true;
        }

         //Inserting the node at the end of the list. Similar to "add" method from last project
        if(position == itemCount + 1){  
            DoubleNode<ItemType>* endNode = headPtr;
            while(endNode -> getNext() != nullptr){
                endNode = endNode -> getNext();     //traverse to the last node of the list
            }
            endNode -> setNext(newDoubleNode);                  //at the end of the list now, sets the next node to the new NOde
            endNode -> getNext() -> setPrev(endNode);         //sets previous of the newNode to the old last node. 
            itemCount++;                                    //item added, item count incremented
            return true;
        }

        //case for inserting in between two nodes
        /*
        In order to insert in between two nodes, we must break the link between the two nodes:

                               node1             node2                node3
              nullptr <-[prev|data|next]<==>[prev|data|next]<==>[prev|data|next] -> nullPtr
                            (headPtr)

                            newNode
            nullPtr<-[prev|data|next]->nullptr

        If we want to insert at position 2, next of node1 and prev of node2 would have to point at the new node
        and prev of the newNode must point and node1 and next must point at node2
        */

        DoubleNode<ItemType>* prevNode = headPtr;

        for (int i = 1; i < position-1 ; i++){
            prevNode = prevNode -> getNext();    //Traverse to correct node
        }   //end for

        newDoubleNode -> setNext(prevNode -> getNext());            //Takes              
        prevNode -> setNext(newDoubleNode);
        newDoubleNode -> setPrev(prevNode);
        newDoubleNode -> getNext() -> setPrev(newDoubleNode);
        itemCount++;
        return true;
       
       


}   //end insert

//********************************Remove Method********************************************************************//
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position){
    if(position < 1 || position > itemCount || isEmpty()) return false;

    //Case of removing the headPtr 
    if(position == 1 ){
       headPtr = headPtr -> getNext();          //changes headPtr to next node in the list
       delete headPtr -> getPrev();           //delete the previous node
       itemCount--;                         //item removed so itemCount decremented
    }//end if
    
    //case of removing the last node
    if(position == itemCount){
        DoubleNode<ItemType>* endNode = headPtr;

        while(endNode -> getNext() != nullptr){
            endNode = endNode -> getNext();         //Traverse to the end of the list
        }//end while
        endNode -> getPrev() -> setNext(nullptr);       //new last node. Sets the next pointer of the second to last node to null ptr
        delete endNode;                                 //Deletes the last node of the list
        itemCount--;                                    //Item removed 
    }//end if

            /*

                               node1             node2                node3
              nullptr <-[prev|data|next]<==>[prev|data|next]<==>[prev|data|next] -> nullPtr
                            (headPtr)
        */
     DoubleNode<ItemType>* nextNode = headPtr;
}

//********************************getSize Method********************************************************************//
//*****************@return returns the amount of items in the list*************************************************//
//TESTED
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const{
    return itemCount;
    
}

//********************************getHeadPtr Method********************************************************************//
//**************@return This method returns the first element of the list: headPtr************************************//
//TESTED
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const{
  return headPtr;
}

//********************************getAtPos Method********************************************************************//
//*********** @param position of list which the user wants the DoubleNode pointer of
//***********@return returns the DoubleNode pointer from the given position
//TESTED
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const{
    if (pos > 0 &&  pos <= itemCount){ //Position must be a positve number and smaller than the total item of the list. List starts at pos 1 and ends at itemCount
            int counter = 1;    //Counter to keep track of position while traversing the list. List starts at 1
            DoubleNode<ItemType>* nextNode = headPtr;

            while(counter < pos){                   //while loop to traverse to correct position.
                nextNode = nextNode -> getNext();      
                counter++;
            } //end while

            return nextNode;
    }//end if
}

//********************************isEmpty Method********************************************************************//
//TESTED
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const{
    if(itemCount == 0) return true;
    else return false;
}

//********************************clear Method********************************************************************//
template<class ItemType>
void DoublyLinkedList<ItemType>::clear(){
}

//********************************display Method********************************************************************//
//************This method will display all the items of each node in order of the list*****************************//
//TESTED
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const{
    //     ////////////////////STUB///////////////////////////
    //     std::cout << headPtr -> getItem();/////////////////
    //     //////////////////////////////////////////////////
    //     DoubleNode<ItemType>* nextNode = headPtr -> getNext();
    DoubleNode<ItemType>* endNode = headPtr;

    // while(endNode -> getNext() != nullptr){
        for(int i = 0; i < itemCount; i++){
            std::cout << endNode -> getItem() << std::endl;   //prints out the item contained in Node 
            endNode =  endNode -> getNext();                //traverses to next node after
        }  
    


        
}

//*******************************displayBackwards Method********************************************************************//
//*************This method will display each item of each node in the reverse order of the list****************************//
//TESTED
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const{

    DoubleNode<ItemType>* endNode = headPtr;    //This node will be used to traverse to the end of the list 

    while(endNode -> getNext() != nullptr){   //Will stop looping when the next Node is nullptr. This would be the end of the list
        endNode = endNode -> getNext();  //Traverse to next node until we reach the end of the list
    }

   while(endNode != headPtr){ //Now traversing in reverse order to print in reverse order.
        std::cout << endNode -> getItem() << std:: endl;      //prints item from last node first
        endNode = endNode -> getPrev();  //travesrse to previous node until the start of the list
    }

    std::cout << endNode -> getItem() << std::endl;     //cout item at headPtr now
   
}

//********************************interleave Method********************************************************************//
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list){}