#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "QueueADT.h"

class ArrayQueue : public QueueADT {
private:
   int allocationSize;
   int* array;
   int frontIndex;
   int length;
   int maxLength;
   
   void Resize() {
      // Allocate new array and copy existing items
      int newSize = allocationSize * 2;
      if (maxLength >= 0 && newSize > maxLength) {
         newSize = maxLength;
      }
      int* newArray = new int[newSize];
      for (int i = 0; i < length; i++) {
         int itemIndex = (frontIndex + i) % allocationSize;
         newArray[i] = array[itemIndex];
      }
         
      // Delete old array, assign new array, and assign new allocation size
      delete[] array;
      array = newArray;
      allocationSize = newSize;
       
      // Reset frontIndex to 0
      frontIndex = 0;
   }

public:
   ArrayQueue(int maximumLength = -1) {
      allocationSize = (0 == maximumLength) ? 0 : 1;
      array = new int[allocationSize];
      length = 0;
      frontIndex = 0;
      maxLength = maximumLength;
   }
   
   virtual ~ArrayQueue() {
      delete[] array;
   }
   
   virtual int Dequeue() override {
      // Get the item at the front of the queue
      int toReturn = array[frontIndex];
      
      // Decrement length and advance frontIndex
      length--;
      frontIndex = (frontIndex + 1) % allocationSize;
      
      // Return the front item
      return toReturn;
   }
        
   virtual bool Enqueue(int item) override {
      // If at max length, return false
      if (length == maxLength) {
         return false;
      }

      // Resize if length equals allocation size
      if (length == allocationSize) {
         Resize();
      }

      // Enqueue the item and return true
      int itemIndex = (frontIndex + length) % allocationSize;
      array[itemIndex] = item;
      length++;
      return true;
   }
   
   virtual int GetLength() const override {
      return length;
   }

   virtual int GetMaxLength() {
      return maxLength;
   }
   
   virtual bool IsEmpty() const override {
      return 0 == length;
   }
   
   virtual int Peek() const override {
      return array[frontIndex];
   }
   
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      if (length > 0) {
         // Front item is not preceded by separator
         printStream << array[frontIndex];
      }
      for (int i = 1; i < length; i++) {
         // Each item after the front is preceded by the separator
         int index = (frontIndex + i) % allocationSize;
         printStream << separator << array[index];
      }
   }
};

#endif