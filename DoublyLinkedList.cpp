/*

Sophie Ong
April 3, 2020
Project 3 -- Doubly Linked List

DoublyLinkedList.cpp file

*/

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
using namespace std;


template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): head(nullptr), item_count(0)
{
    //Initialize default constructor
}//end default constructor

template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList& a_list)
{
    //Copy each node and iterate through the list
    DoubleNode<ItemType> *iterator = a_list.head;
    for (int i = 1; i <= a_list.item_count; i++)
    {
        ItemType item = iterator-> getItem();
        this->insert(i, item);
        iterator = iterator -> getNext();
    }
}//end copy constructor

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    //Implement Destructor aka delete all nodes
    clear();
}//end destructor

template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
    //Create a new node containing the new entry & to get pointer to position
    DoubleNode<ItemType>*newDoubleNodeptr = new DoubleNode<ItemType>();
    newDoubleNodeptr->setItem(item);
    newDoubleNodeptr->setNext(nullptr);
    newDoubleNodeptr->setPrevious(nullptr);

    // Insert first node
    if (position == 1)
    {
        head = newDoubleNodeptr;
        item_count++;
    }
    // Attach new node to chain
    else if (position == item_count+1)
    {
        DoubleNode<ItemType>*last_ = head;
        while (last_ -> getNext() != nullptr)
        {
            last_=last_->getNext();
        }
       last_->setNext(newDoubleNodeptr);
       newDoubleNodeptr->setPrevious(last_);
       newDoubleNodeptr->setNext(nullptr);
       item_count++;
    }
    else
    {
        int i = 1;
        DoubleNode<ItemType>*temp = head;
        while(i < position-1 && temp != nullptr)
        {
            temp = temp ->getNext();
            i++;
        }
        //insert new node before node to which 
       //position it points 
       newDoubleNodeptr->setPrevious(temp);
       newDoubleNodeptr->setNext(temp->getNext());
       temp->setNext(newDoubleNodeptr);
       
       if(newDoubleNodeptr->getNext()!=nullptr)
       {
           newDoubleNodeptr->getNext()->setPrevious(newDoubleNodeptr);
       }
       item_count++;
    } 
    return true; //bool
}// end insert

template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    if (position < 1 && position > item_count)
    {
        return false;
    }
    else
    {
        DoubleNode<ItemType>*temp;
        if(position==1)
        {
            temp = head;
            head = head -> getNext();
            if (head != nullptr)
            {
                head->setPrevious(nullptr);
            }
            delete temp;
        }
        else
        {
            DoubleNode<ItemType> * iterator = head;
            for (int i = 2; i < position; i++)
            {
                temp = iterator -> getNext();
                if (iterator->getNext()->getNext() != nullptr)
                {
                    iterator->getNext()->getNext()->setPrevious(iterator);
                    iterator->setNext(iterator->getNext()->getNext());
                }
                else
                {
                    iterator->setNext(nullptr);
                }
                delete temp;   
            }
        }
         item_count --; //decrement
       return true; //bool
    }
}// end remove

/*
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    //get pointer to position
    DoubleNode<ItemType>* pos_ptr = getAtPos(position);
    if (pos_ptr == nullptr) //no node at pos
    {
        return false; //bool
    }
    else
    {
        //remove node from chain
        if(pos_ptr == last_)
        {
            //remove last node
            last_ = pos_ptr->getPrevious();
            last_->setNext(nullptr);

            //place node back in system
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr; //delete from memory
            pos_ptr = nullptr; //set to null
        }
        else
        {
            //remove from the middle
            pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
            pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());

            //place node back to system
            pos_ptr->setNext(nullptr);
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr; //delete from memory
            pos_ptr = nullptr; //set to null
        }
        item_count--; //decrement
        return true; //bool
    }
} //end remove
*/
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty()
{
    return item_count() == 0; //sets size equal to zero
}//end isEmpty()

template <class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType> * curPtr = head;
    if (curPtr != nullptr)
    {
        while (curPtr->getNext()!=nullptr)
        {
            cout<<curPtr->getItem()<<endl;
            curPtr = curPtr->getNext();
        }
        cout<<curPtr->getItem()<<endl;
    }
}// end display()

template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    item_count = 0;
    DoubleNode<ItemType> * temp = head;
    while(head!=nullptr)
    {
        head=head->getNext();
        delete temp;
        temp = head;
    }
    delete temp;
}//end clear()

template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards()const // print contents of the list backwards
{
    //Place at the back of the list
    DoubleNode<ItemType> *iterator = head;
    for(int i = 1; i<item_count; i++)
    {
        iterator=iterator->getNext();
    }
    //Iterate over each node & print in reverse
    cout<<"["; //print brackets
    for(int i = 0; i<item_count;i++)
    {
        cout<<iterator->getItem();
        if(i< item_count - 1)  //prints commas
        {
            cout<<",";
        }
        iterator = iterator->getPrevious(); //
    }
    cout<<"]"<<endl; //print brackets
} //end displayBackwards() const

template <class ItemType>
DoublyLinkedList<ItemType>& DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list) 
{
    DoublyLinkedList<ItemType> result;
    DoubleNode<ItemType>* p1 = head;
    DoubleNode<ItemType>* p2= a_list.head;
    while (p1|| p2 )
    {
        if (p1 != nullptr) 
        {
            result.insert(p1->getItem(), result.getSize()+1);    
            p1 = p1->getNext();
        }
        if (p2!= nullptr) 
        {
            result.insert(p2->getItem(), result.getSize()+1);
            p2 = p2->getNext();
        }
    }
return result;
}// end interleave



/*
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
    //Create a new node containing the new entry & to get pointer to position
    DoubleNode<ItemType>* new_node_ptr = new DoubleNode<ItemType>(); //instantiate ptr
    new_node_ptr->setItem(item);
    DoubleNode<ItemType> *pos_ptr = getAtPos(position); //obtain ptr

    // Insert first node
    if(head == nullptr) 
    {
        new_node_ptr->setNext(nullptr);
        new_node_ptr-> setPrevious(nullptr);
        head = new_node_ptr;
        last_ = new_node_ptr;
    }
    // Attach new node to chain
    else if (pos_ptr == head)
    {
        //insert at the beginning of the chain
        new_node_ptr->setNext(head);
        new_node_ptr->setPrevious(nullptr);
        head->setPrevious(new_node_ptr);
        head = new_node_ptr;
    }
    else if(pos_ptr == nullptr)
    {
        //insert at the end of the list
        new_node_ptr-> setNext(nullptr);
        new_node_ptr-> setPrevious(last_);
        last_-> setNext(new_node_ptr);
        last_-> new_node_ptr;
    }
    else
    {
        //insert new node before node to which 
        //position it points 
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrevious(pos_ptr->getPrevious());
        pos_ptr->getPrevious()->setNext(new_node_ptr);
        pos_ptr->setPrevious(new_node_ptr);
    } //end if
    
    item_count++; //increment
    return true; //boolean function
} //end insert
*/




/*
template <class ItemType>
ItemType DoublyLinkedList<ItemType>::getItem(const ItemType& item)
{
    DoubleNode<ItemType>* pos_ptr = getAtPos(item);
    if(pos_ptr == nullptr)
    {
        throw(out_of_range("getItem called with emptylist or invalid position"));
    }
    else
    {
        //return type is <ItemType>, no default null
        return pos_ptr->getItem();
    }
}

template <class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return item_count; //returns number of items in the list
} //end getSize()
*/

#endif