#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "SinglyLinkedNode.h"
#include "ListADT.h"

class SinglyLinkedList : public ListADT {
private:
   SinglyLinkedNode* head;
   SinglyLinkedNode* tail;
   
public:
   SinglyLinkedList() {
      head = nullptr;
      tail = nullptr;
   }
   
   virtual ~SinglyLinkedList() {
      SinglyLinkedNode* currentNode = head;
      while (currentNode) {
         SinglyLinkedNode* toBeDeleted = currentNode;
         currentNode = currentNode->next;
         delete toBeDeleted;
      }
   }
   
   virtual void Append(int item) override {
      AppendNode(new SinglyLinkedNode(item));
   }
    
   virtual void AppendNode(SinglyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         tail = newNode;
      }
   }
   
   virtual bool Contains(int item) const override {
      return Search(item) != nullptr;
   }
   
   virtual int GetLength() const override {
      int length = 0;
      SinglyLinkedNode* node = head;
      while (node) {
         // Increment length and advance to next node
         length++;
         node = node->next;
      }
      return length;
   }
   
   virtual bool InsertAfter(int currentItem, int newItem) override {
      SinglyLinkedNode* currentNode = Search(currentItem);
      if (currentNode) {
         SinglyLinkedNode* newNode = new SinglyLinkedNode(newItem);
         InsertNodeAfter(currentNode, newNode);
         return true;
      }
      return false; // currentItem not found
   }
   
   virtual void InsertNodeAfter(SinglyLinkedNode* currentNode,
      SinglyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         tail = newNode;
      }
      else {
         newNode->next = currentNode->next;
         currentNode->next = newNode;
      }
   }
   
   virtual bool IsEmpty() const override {
      return head == nullptr;
   }
   
   virtual void Prepend(int item) override {
      PrependNode(new SinglyLinkedNode(item));
   }
   
   virtual void PrependNode(SinglyLinkedNode* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head = newNode;
      }
   }
   
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      SinglyLinkedNode* node = head;
      if (node) {
          // Head node is not preceded by separator
          printStream << node->data;
          node = node->next;
      }
      while (node) {
         // Each node after the head is preceded by the separator
         printStream << separator << node->data;
         node = node->next;
      }
      printStream << std::endl;
   }
   
   virtual bool Remove(int itemToRemove) override {
      // Traverse to the node with data equal to itemToRemove,
      // keeping track of the previous node in the process
      SinglyLinkedNode* previous = nullptr;
      SinglyLinkedNode* current = head;
      while (current) {
         if (current->data == itemToRemove) {
            RemoveNodeAfter(previous);
            return true;
         }
         
         // Advance to next node
         previous = current;
         current = current->next;
      }
      
      // Not found
      return false;
   }
   
   virtual void RemoveAfter(int currentItem) {
      SinglyLinkedNode* currentNode = Search(currentItem);
      if (currentNode) {
         RemoveNodeAfter(currentNode);
      }
   }
   
   virtual void RemoveNodeAfter(SinglyLinkedNode* currentNode) {
      if (currentNode == nullptr) {
         // Special case: remove head
         SinglyLinkedNode* nodeToRemove = head;
         head = head->next;
         delete nodeToRemove;

         if (head == nullptr) {
             tail = nullptr; // Last item was removed
         }
      }
      else if (currentNode->next) {
         SinglyLinkedNode* nodeToRemove = currentNode->next;
         SinglyLinkedNode* succeedingNode = nodeToRemove->next;
         currentNode->next = succeedingNode;
         delete nodeToRemove;

         if (succeedingNode == nullptr) {
            tail = currentNode; // Last item was removed
         }
      }
   }
   
   // Returns the first node in the list with the specified data value, or
   // nullptr if no such node exists.
   virtual SinglyLinkedNode* Search(int dataValue) const {
      // Start the search at the list's head
      SinglyLinkedNode* currentNode = head;
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