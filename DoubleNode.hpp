/*

Sophie Ong
April 3, 2020
Project 3 -- Doubly Linked List

DoubleNode.hpp file

Created a class that is capable of holding an item of an arbitrary type
ItemType as an node of a Doubly-Linked list, containing two pointers that respecively
point to other objects of type DoubleNode
*/

#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP // include guard


template <class ItemType>
class DoubleNode
{
    private:
        ItemType data_; // Data item
        ItemType item;
        DoubleNode* next_; // Points to next node
        DoubleNode* previous_; // Points to previous node
    public:
        DoubleNode(); // default constructor
        DoubleNode(const ItemType& item); //copy constructor
        //DoubleNode(const ItemType& an_item, DoubleNode<ItemType> * next_node_ptr); //parametrized constructor
        ItemType getItem() const;
        DoubleNode  *getNext() const;
        DoubleNode * getPrevious() const;
        //setters
        void setItem(ItemType item);
        void setPrevious(DoubleNode<ItemType>* prev_node_ptr);
        void setNext(DoubleNode <ItemType> *next_node_ptr);

    
        
//end doublenode
};

#endif //DOUBLE_NODE_H


