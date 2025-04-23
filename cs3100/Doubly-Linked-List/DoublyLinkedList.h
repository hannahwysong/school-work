#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "DoublyLinkedNode.h"
#include "ListADT.h"

class DoublyLinkedList : public ListADT {
private:
   DoublyLinkedNode* head;
   DoublyLinkedNode* tail;

public:
   DoublyLinkedList() {
      head = nullptr;
      tail = nullptr;
   }
   
   virtual ~DoublyLinkedList() {
      DoublyLinkedNode* currentNode = head;
      while (currentNode) {
         DoublyLinkedNode* toBeDeleted = currentNode;
         currentNode = currentNode->next;
         delete toBeDeleted;
      }
   }
   
   virtual void Append(int item) override {
      AppendNode(new DoublyLinkedNode(item));
   }
    
   virtual void AppendNode(DoublyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         newNode->previous = tail;
         tail = newNode;
      }
   }
   
   virtual bool Contains(int item) const override {
      return Search(item) != nullptr;
   }
   
   virtual int GetLength() const override {
      int length = 0;
      DoublyLinkedNode* node = head;
      while (node) {
         // Increment length and advance to next node
         length++;
         node = node->next;
      }
      return length;
   }
   
   virtual bool InsertAfter(int currentItem, int newItem) override {
      DoublyLinkedNode* currentNode = Search(currentItem);
      if (currentNode) {
         DoublyLinkedNode* newNode = new DoublyLinkedNode(newItem);
         InsertNodeAfter(currentNode, newNode);
         return true;
      }
      return false; // currentItem not found
   }
   
   virtual void InsertNodeAfter(DoublyLinkedNode* currentNode,
      DoublyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         newNode->previous = tail;
         tail = newNode;
      }
      else {
         DoublyLinkedNode* successor = currentNode->next;
         newNode->next = successor;
         newNode->previous = currentNode;
         currentNode->next = newNode;
         successor->previous = newNode;
      }
   }
   
   virtual bool IsEmpty() const override {
      return head == nullptr;
   }
   
   virtual void Prepend(int item) override {
      PrependNode(new DoublyLinkedNode(item));
   }
   
   virtual void PrependNode(DoublyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head->previous = newNode;
         head = newNode;
      }
   }
   
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      DoublyLinkedNode* node = head;
      if (node) {
          // Head node is not preceded by separator
          printStream << node->data;
          node = node->next;
      }
      while (node) {
         printStream << separator << node->data;
         node = node->next;
      }
      printStream << std::endl;
   }
   
   virtual bool Remove(int itemToRemove) override {
      DoublyLinkedNode* nodeToRemove = Search(itemToRemove);
      if (nodeToRemove) {
         RemoveNode(nodeToRemove);
         return true;
      }
      
      return false; // not found
   }
   
   virtual void RemoveNode(DoublyLinkedNode* currentNode) {
      DoublyLinkedNode* successor = currentNode->next;
      DoublyLinkedNode* predecessor = currentNode->previous;
      
      if (successor) {
         successor->previous = predecessor;
      }
      if (predecessor) {
         predecessor->next = successor;
      }
         
      if (currentNode == head) {
         head = successor;
      }
      if (currentNode == tail) {
         tail = predecessor;
      }
      
      delete currentNode;
   }
   
   // Returns the first node in the list with the specified data value, or
   // nullptr if no such node exists.
   virtual DoublyLinkedNode* Search(int dataValue) const {
      // Start the search at the list's head
      DoublyLinkedNode* currentNode = head;
      while (currentNode) {
         // Compare the node's data with dataValue
         if (currentNode->data == dataValue) {
            return currentNode;
         }
         
         // Advance to next node
         currentNode = currentNode->next;
      }
      
      // Not found
      return nullptr;
   }
};

#endif