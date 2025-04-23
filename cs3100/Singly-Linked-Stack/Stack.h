#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "StackADT.h"

// Node to store an item in a linked-list-based stack
class StackNode {
public:
   int data;
   StackNode* next;
   
   StackNode(int dataValue, StackNode* nextNode) {
      data = dataValue;
      next = nextNode;
   }
};

// Linked-list-based stack
class Stack : public StackADT {
private:
   StackNode* top;

public:
   Stack() {
      top = nullptr;
   }

   virtual ~Stack() {
      while (top) {
         StackNode* nodeToDelete = top;
         top = top->next;
         delete nodeToDelete;
      }
   }
   
   virtual int GetLength() const override {
      StackNode* node = top;
      int count = 0;
      while (node) {
         count++;
         node = node->next;
      }
      return count;
   }
   
   virtual bool IsEmpty() const override {
      return top == nullptr;
   }
   
   virtual int Peek() const override {
      return top->data;
   }
   
   virtual void Push(int newData) override {
      top = new StackNode(newData, top);
   }
   
   virtual int Pop() override {
      // Copy top node's data
      StackNode* poppedNode = top;
      int poppedItem = top->data;
      
      // Remove top node
      top = top->next;
      
      // Delete former top node
      delete poppedNode;
      
      // Return the popped item
      return poppedItem;
   }
   
   // Prints stack items from top to bottom, with the separator string between
   // each pair of items
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      StackNode* node = top;
      
      if (node) {
         // Print first item with no separator
         printStream << node->data;
         node = node->next;
      }
      
      // Print remaining items, each preceded by the separator
      while (node) {
         printStream << separator << node->data;
         node = node->next;
      }
   }
};

#endif