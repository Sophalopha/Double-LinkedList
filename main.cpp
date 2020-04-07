#include<iostream>
using namespace std;

#include "DoublyLinkedList.hpp"

int main()
{
   DoublyLinkedList<int>* list1 = new DoublyLinkedList<int>();
   // insert elements
   list1->insert(4, 1);
   list1->insert(2, 2);
   list1->insert(1, 3);
   list1->insert(3, 4);
   list1->insert(5, 3);
   list1->display();

   cout << "Creating copy of first list" << endl;
   DoublyLinkedList<int> list2(*list1);
   list2.display();

   cout << "tesing clear" << endl;
   list2.clear();
 
   cout << "list in reverse" << endl;
   list2.displayBackwards();

   cout << "removing value at index 1" << endl;
   list2.remove(1);

   cout << "value at index 3: " << list2.getAtPos(3)->getItem() << endl;
   list2.display();



   return 0;

}