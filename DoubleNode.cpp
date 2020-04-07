/*

Sophie Ong
April 3, 2020
Project 3 -- Doubly Linked List

DoubleNode.cpp file

*/

#ifndef DOUBLE_NODE_CPP
#define DOUBLE_NODE_CPP

#include <iostream>
#include "DoubleNode.hpp"
using namespace std;

template<class ItemType>
DoubleNode<ItemType>::DoubleNode()
{
    data_ = 0;
    next_ = nullptr;
    previous_ = nullptr;
} //end DoubleNode()

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& item)
{
    data_ = item;
    next_ = nullptr;
    previous_= nullptr;
}// end DoubleNode(ItemType item)

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item;
}// end getData()

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next_;
} //end getNext()

template<class ItemType>
DoubleNode<ItemType>*DoubleNode<ItemType>::getPrevious() const
{
    return previous_;
} //end getPrevious

template<class ItemType>
void DoubleNode<ItemType>::setItem(ItemType item)
{
    this->data_ = item;
}// end setItem

template<class ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode <ItemType> *prev_node_ptr)
{
    this->previous_=previous_;
}//end setPrevious

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode <ItemType> *next_node_ptr)
{
    this->next_=next_;
}// end setNext
 

 #endif
