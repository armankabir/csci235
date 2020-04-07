#include<iostream>
#include "DoublyLinkedList.hpp"

int main(){
    DoublyLinkedList<int> testList;
    if(testList.isEmpty()) std::cout << "The Linked list is empty and therefore the size is " << testList.getSize() << std::endl<< std::endl;

    std::cout << "Now inserting 5 to position 1" << std::endl;
    if(testList.insert(5, 1)) {
        std::cout<< "The linked list size is now " << testList.getSize() << " And "; 
        testList.display();
        std::cout << " has been added." << std::endl;
        DoubleNode<int>* node1 = testList.getHeadPtr();
        std::cout<<  std::endl<< std::endl;
    }

    std::cout << "now inserting 69 at position 2" << std::endl;
    if(testList.insert(69, 2)){
        std::cout << "the linked list size is now " << testList.getSize() << "(2)" << std::endl;
        std::cout << "5 and 69 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node2 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }

    std::cout << "now inserting 98 at position 3" << std::endl;
    if(testList.insert(98, 3)){
        std::cout << "the linked list size is now " << testList.getSize() << "(3)" << std::endl;
        std::cout << "5, 69 and 98 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }
   
    std::cout << "now inserting 9 at position 1" << std::endl;
    if(testList.insert(9, 1)){
        std::cout << "the linked list size is now " << testList.getSize() << "(4)" << std::endl;
        std::cout << "5, 69, 98, and 9 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }
    std::cout << "now inserting 76 at position 2" << std::endl;
    if(testList.insert(76, 2)){
        std::cout << "the linked list size is now " << testList.getSize() << "(5)" << std::endl;
        std::cout << "5, 69, 98, 9 and 76 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }

    std::cout << "now testing printing in previous order" << std::endl;
    testList.displayBackwards();
    std::cout << "Now testing printing an item at position 3, this should be 5" << std::endl;
    std::cout << testList.getAtPos(3) -> getItem() << " (5)" << std::endl;
}
