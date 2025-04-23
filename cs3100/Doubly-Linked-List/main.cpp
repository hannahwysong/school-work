#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
   DoublyLinkedList numList;

   // Insert various items using Append(), Prepend(), and InsertAfter()
   numList.Append(14);          // List: 14
   numList.Append(2);           // List: 14, 2
   numList.Append(20);          // List: 14, 2, 20
   numList.Prepend(31);         // List: 31, 14, 2, 20
   numList.InsertAfter(2, 16);  // List: 31, 14, 2, 16, 20
   numList.InsertAfter(20, 55); // List: 31, 14, 2, 16, 20, 55

   // Output list
   cout << "List after adding items: ";
   numList.Print(cout);

   // Remove the tail node, then the head node
   numList.Remove(55); // List: 31, 14, 2, 16, 20
   numList.Remove(31); // List: 14, 2, 16, 20

   // Output list again
   cout << "List after removing first and last items: ";
   numList.Print(cout);
   
   // Insert three more items
   numList.Prepend(67);         // List: 67, 14, 2, 16, 20
   numList.InsertAfter(20, 58); // List: 67, 14, 2, 16, 20, 58
   numList.Append(89);          // List: 67, 14, 2, 16, 20, 58, 89
   
   // Output final list
   cout << "List after inserting three more items: ";
   numList.Print(cout);
   
   return 0;
}