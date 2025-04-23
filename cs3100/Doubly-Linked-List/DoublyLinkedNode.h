#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H

class DoublyLinkedNode {
public:
   int data;
   DoublyLinkedNode* next;
   DoublyLinkedNode* previous;

   DoublyLinkedNode(int initialData) {
      data = initialData;
      next = nullptr;
      previous = nullptr;
   }
};

#endif