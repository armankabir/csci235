/* 
Arman Kabir
Projext 2
Dr. Wole

This program is the implementation file of a doubly-linked list. 
*/

#ifndef DOUBLY_LINKED_IMPLEMENTATION
#define DOUBLY_LINKED_IMPLEMENTATION
#include "DoublyLinkedList.hpp"

//********************************Default Constructor***********************************************************//
//TESTED
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0){}     //end default constructor
                                                                                    //Initializer list to set headPtr to null and itemCount to 0

//********************************Copy Constructor*************************************************************//
//TESTED
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(DoublyLinkedList<ItemType> &copyList){
    DoubleNode<ItemType>* endNode = copyList.getHeadPtr(); //headptr of list to be copied. Will be inserted at position one of list
    // headPtr = endNode;
    // endNode = endNode -> getNext();
    // DoubleNode<ItemType>* thisNode = headPtr;
    int counter = 1;    //keeps track of position in list
    while(counter <= copyList.getSize()){
        insert(endNode->getItem(), counter);    //call insert method to insert items from copylist into this list
        endNode = endNode -> getNext();
        counter++;
    }
    itemCount = copyList.getSize(); //sets this itemCount to the itemCount of the copyList

}


//********************************Destructor********************************************************************//
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList() {       
    clear();            //calls clear fucntion upon destruction
    //std::cout << "destroying the list....." << std::endl << "Success" << std::endl;
} //end destructor

//********************************insert Method********************************************************************//
//This method will insert a node with an arbritrary data item and set it at a node in a given position of the list//
//**************Position defined @param and @return true if node is successfully inserted************************//
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
         
        }//end if

        //Inserting at front of list, when the list already contains elements
        else if(position == 1){       
            newDoubleNode -> setNext(headPtr);      //sets the next element in list as the head pointer. This makes this node now the first in the list
            headPtr -> setPrev(newDoubleNode);      //sets prev of old headPtr to the new headptr
            headPtr = newDoubleNode;        //new headPtr is the new double node
        }

         //Inserting the node at the end of the list. Similar to "add" method from last project
        else if(position == itemCount + 1){  
            DoubleNode<ItemType>* endNode = headPtr;
            while(endNode -> getNext() != nullptr){
                endNode = endNode -> getNext();     //traverse to the last node of the list
            }
            endNode -> setNext(newDoubleNode);                  //at the end of the list now, sets the next node to the new NOde
            endNode -> getNext() -> setPrev(endNode);         //sets previous of the newNode to the old last node.
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

       else{
            DoubleNode<ItemType>* prevNode = headPtr;

            for (int i = 1; i < position-1 ; i++){
                prevNode = prevNode -> getNext();    //Traverse to correct node
            }   //end for

            newDoubleNode -> setNext(prevNode -> getNext());            //Takes              
            prevNode -> setNext(newDoubleNode);
            newDoubleNode -> setPrev(prevNode);
            newDoubleNode -> getNext() -> setPrev(newDoubleNode);
       }    
        itemCount++;
        return true;
       
       


}   //end insert

//********************************Remove Method********************************************************************//
//*******This method removes the node at at position defined @param. @return true when node removed***************//
//TESTED
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position){
    if(position < 1 || position > itemCount || isEmpty()) return false;

    //Case of removing the headPtr 
    if(position == 1 ){
        headPtr = headPtr -> getNext();          //changes headPtr to next node in the list
        delete headPtr -> getPrev();
        // itemCount--;                         //item removed so itemCount decremented
        // return true;
    }//end if
    
    //case of removing the last node
    if(position == itemCount){
        DoubleNode<ItemType>* endNode = headPtr;

        while(endNode -> getNext() != nullptr){
            endNode = endNode -> getNext();         //Traverse to the end of the list
        }//end while
        endNode -> getPrev() -> setNext(nullptr);           //new last node. Sets the next pointer of the second to last node to null ptr
        delete endNode;                                   //Deletes the last node of the list
        // itemCount--;                                    //Item removed so itemCount decremented
        // return true;
    }//end if

    //case of removing a node between two nodes
    /*

                               node1             node2                node3
              nullptr <-[prev|data|next]<==>[prev|data|next]<==>[prev|data|next] -> nullPtr
                            (headPtr)

        removing node2. first traverse to the correct node. next of node1 needs to point to node3 and prev of node3 now 
        needs to point at node 1.
        
    */
    else{
        int counter = 1;             //counter to keep track of position while traversing the list
        DoubleNode<ItemType>* delNode = headPtr;       //Node to be deleted

        while(counter < position){
            delNode = delNode -> getNext();     //Traverse to node at position
            counter++;
        }//end while

        delNode -> getPrev() -> setNext(delNode ->getNext());      //Goes to the previous node at the position. Sets the nextptr of this node to the node after the node to be deleted.
        delNode -> getNext() -> setPrev(delNode->getPrev());     //goes to the next node at the position. Sets the previous node of this node to point at the node before the node to be deleted.
        delete delNode;                                        //deletes the node at the position now to clear memory
    }
    itemCount--;                                         //item deleted
    return true;
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
//*************@return true if the list is empty. list is empty when the item count is 0***************************//
//TESTED
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const{
    if(itemCount == 0) return true;
    else return false;
}

//********************************clear Method********************************************************************//
//***************This method clear the list and frees all memory allocated***************************************//
//TESTED
template<class ItemType>
void DoublyLinkedList<ItemType>::clear(){
    DoubleNode<ItemType>* deleteNode = headPtr;
    DoubleNode<ItemType>* nextNode;                                 //This will be a place holder while the node is being deleted
                                    //= deleteNode -> getNext();

    while(deleteNode != nullptr){
        nextNode = deleteNode -> getNext();     //gets the next node
        delete deleteNode;                    //deletes the initial node
        deleteNode = nextNode;              //now set initial node to next node. Loop will continue to end of the list
    }//end while

    headPtr = nullptr;
    itemCount = 0;
    
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
            std::cout << endNode -> getItem();   //prints out the item contained in Node 
            endNode =  endNode -> getNext();                //traverses to next node after
            if(endNode != nullptr) std::cout << " ";
            else std::cout << "\n";                 //prints space inbetween each item and new line at the end of the list
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
        std::cout << endNode -> getItem() << " ";      //prints item from last node first
        endNode = endNode -> getPrev();  //travesrse to previous node until the start of the list
    }

    std::cout << endNode -> getItem() << "\n";     //cout item at headPtr now
   
}

//********************************interleave Method********************************************************************//
//****This method takes the list @param, and puts the nodes of that list at the even positions of the currentlist*****//
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list){
    

    DoublyLinkedList<ItemType>* newList = new DoublyLinkedList<ItemType>; //list to be returned
    int counter = 1;                    //keep track of position in the new list that will be retured
    DoubleNode<ItemType>* oddNode = headPtr;                  //node to be inserted at odd positions of list
    DoubleNode<ItemType>* evenNode = a_list.getHeadPtr();    
    DoubleNode<ItemType>* holderNode, holderNode2;
    while (oddNode != nullptr && evenNode != nullptr) {
// if first list is not done adding add a node from it
        if (oddNode != nullptr) {
            newList -> insert(oddNode -> getItem(), counter);
            oddNode = oddNode -> getNext();
            counter++;
        }
        // if second list is not done adding add a node from it
        if (evenNode != nullptr) {
            newList -> insert(evenNode -> getItem(), counter);
            evenNode = evenNode -> getNext();
            counter++;
        }
    }

    return *newList;
    /*

                               node1             node3                node5 
              nullptr <-[prev|data|next]<==>[prev|data|next]<==>[prev|data|next] -> nullPtr
                            (headPtr)

                               node2             node4                node6 
     a_list    nullptr <-[prev|data|next]<==>[prev|data|next]<==>[prev|data|next] -> nullPtr
                            (headPtr)

    set next of headptr to node to. set 
        
    */
    // DoubleNode<ItemType>* aListHead = a_list.getHeadPtr();
    // oddNode = oddNode -> getNext();
    // while(oddNode != nullptr && evenNode != nullptr){
    //     aListHead -> setNext(evenNode);

    //     if(aListHead -> getPrev() != nullptr)
    //         aListHead -> setPrev(oddNode); //end if   
    // }
    // return newList;
}

#endif