/*

Sophie Ong
April 3, 2020
Project 3 -- Doubly Linked List

DoublyLinkedList.hpp file

Ceated a class that is a demonstration of the Doubly-Linked List concept
discussed in class, containing a head pointer to a DoubleNode of an arbitrary
type ItemType and has a member that keeps track of size
*/

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include <iostream>

#include "DoubleNode.hpp"
using namespace std;

template <class ItemType>
class DoublyLinkedList
{
    public:
        DoublyLinkedList(); // default constructor
        DoublyLinkedList(const DoublyLinkedList& a_list); //copy constructor
        ~DoublyLinkedList(); //destructor
        bool insert(const ItemType& item, const int& position); //insert item at index position
        bool remove(const int& position); //remove node at index position
        DoubleNode<ItemType>* getAtPos(const int& position) const; // returns a pointer to the node located at pos
        bool isEmpty(); //returns whether the list is empty
        void clear (); //clears the list
        void display() const; // prints the contents of the list in order
        DoublyLinkedList<ItemType> & interleave(const DoublyLinkedList<ItemType>& a_list); 
        /* alters the calling list to be the interleaved list of the the original 
        and parameter list*/
        void displayBackwards() const; //prints the contents of the list backwards
    private:
        DoubleNode<ItemType>*last_; //Points to previous node
        DoubleNode<ItemType>* head; //Points to last node
        int item_count; // keeps track of number of items in the list

    

};//end DoublyLinkedList.hpp


#endif //DOUBLYLINKEDLIST_H