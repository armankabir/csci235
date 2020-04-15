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

    std::cout << "now inserting 59 at position 2" << std::endl;
    if(testList.insert(59, 2)){
        std::cout << "the linked list size is now " << testList.getSize() << "(2)" << std::endl;
        std::cout << "5 and 59 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node2 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }

    std::cout << "now inserting 98 at position 3" << std::endl;
    if(testList.insert(98, 3)){
        std::cout << "the linked list size is now " << testList.getSize() << "(3)" << std::endl;
        std::cout << "5, 59 and 98 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }
   
    std::cout << "now inserting 9 at position 1" << std::endl;
    if(testList.insert(9, 1)){
        std::cout << "the linked list size is now " << testList.getSize() << "(4)" << std::endl;
        std::cout << "5, 59, 98, and 9 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }
    std::cout << "now inserting 76 at position 2" << std::endl;
    if(testList.insert(76, 2)){
        std::cout << "the linked list size is now " << testList.getSize() << "(5)" << std::endl;
        std::cout << "5, 59, 98, 9 and 76 have been inserted and The doubly linked list now is: " << std::endl;
        testList.display();
        DoubleNode<int>* node3 = testList.getHeadPtr();
        std::cout << std::endl << std::endl;
    }

    std::cout << "now testing printing in previous order" << std::endl;
    testList.displayBackwards();
    std::cout << std::endl;

    std::cout << "Now testing printing an item at position 3, this should be 5" << std::endl;
    std::cout << testList.getAtPos(3) -> getItem() << " (5)" << std::endl;
    std::cout << "Now testing removing this number" << std::endl;
    std::cout << std::endl; 

    if(testList.remove(3)){
        std::cout << "Item at position 3 removed. The list is now:"  << testList.getSize() << std::endl;
        testList.display();
        std::cout << std::endl; 
    }

    if(testList.remove(1)){
        std::cout << "Now removing headPtr. List is now:  " << testList.getSize() << std::endl;
        testList.display();
        std::cout << std::endl; 
    }
    if(testList.remove(testList.getSize())){
        std::cout << "Now removing last node. List is now:  " << testList.getSize() << std::endl;
        testList.display();
         std::cout << std::endl;
    }

    if(testList.insert(9, testList.getSize())) std::cout << "adding 9 to list ";
    if(testList.insert(10, testList.getSize())) std::cout << "adding 10 to the list" << std::endl;
    std::cout << "List is now: " << std::endl;
    testList.display();
    std::cout << std::endl;
    std::cout << "now clearing the list" << std::endl;
    testList.clear();
    testList.display();
    if(testList.isEmpty()) std::cout << "List successfully cleared." << std::endl;
    std::cout << std::endl;


    DoublyLinkedList<int> evenNumbers, oddNumbers;

    if(evenNumbers.insert(0, 1)) std::cout << "Adding.." << std::endl;
    if(evenNumbers.insert(2, 2)) std::cout << "Adding..." << std::endl;
    if(evenNumbers.insert(4, 3)) std::cout << "Adding..." << std::endl;
    if(evenNumbers.insert(6, 4)) std::cout << "Adding..." << std::endl;
    if(evenNumbers.insert(8, 5)) std::cout << "Adding..." << std::endl;

    std::cout << "even numbers list is: " << std::endl;
    evenNumbers.display();
    std::cout << std::endl;

    if(oddNumbers.insert(1, 1)) std::cout << "Adding.." << std::endl;
    if(oddNumbers.insert(3, 2)) std::cout << "Adding.." << std::endl;
    if(oddNumbers.insert(5, 3)) std::cout << "Adding.." << std::endl;
    if(oddNumbers.insert(7, 4)) std::cout << "Adding.." << std::endl;
    if(oddNumbers.insert(9, 5)) std::cout << "Adding.." << std::endl;
    std::cout << "odd numbers list is: " << std::endl;
    oddNumbers.display();
    std::cout << std::endl;

    DoublyLinkedList<std::string> numeros;
    numeros.insert("uno", 1);
    numeros.insert("dos", 2);
    numeros.insert("tres", 3);
    numeros.insert("cuatro", 4);
    numeros.display();

    DoublyLinkedList<std::string> copyNumberos(numeros);
    copyNumberos.display();
    DoublyLinkedList<std::string> interList = numeros.interleave(copyNumberos);
    interList.display()


    // std::cout << "Interleaving odd and even numbers..." << std::endl << "Full list is: " << std::endl;
    // DoublyLinkedList<int> digits(oddNumbers);
    // digits.interleave(oddNumbers);
    

    
 
}
