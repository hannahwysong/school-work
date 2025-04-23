#ifndef SINGLYLINKEDNODE_H
#define SINGLYLINKEDNODE_H

class SinglyLinkedNode {
public:
   int data;
   SinglyLinkedNode* next;

   SinglyLinkedNode(int initialData) {
      data = initialData;
      next = nullptr;
   }
};

#endif