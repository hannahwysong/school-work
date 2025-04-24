#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "ListADT.h"

class ArrayList : public ListADT {
private:
   int* array;     // Pointer to array data
   int length;         // Number of elements in use
   int allocationSize; // Allocation size, in number of elements
   
   virtual void Resize(int newAllocationSize) {
      // Create a new array with the indicated size
      int* newArray = new int[newAllocationSize];

      // Copy items in current array into the new array
      for (int i = 0; i < length; i++) {
         newArray[i] = array[i];
      }
      
      // Free current array
      delete[] array;

      // Assign the array member with the new array
      array = newArray;
      
      // Update allocation size
      allocationSize = newAllocationSize;
   }

public:
   ArrayList(int capacity = 1) {
      allocationSize = capacity;
      array = new int[capacity];
      length = 0;
   }
   
   virtual ~ArrayList() {
      delete[] array;
   }
   
   virtual void Append(int item) override {
      // Resize if the array is full
      if (allocationSize == length) {
         Resize(length * 2);
      }

      // Insert the new item at index length
      array[length] = item;

      // Increment length to reflect the added item
      length++;
   }
   
   virtual bool Contains(int item) const override {
      return Search(item) != -1;
   }
   
   virtual int GetLength() const override {
      return length;
   }
   
   virtual bool InsertAfter(int existingItem, int newItem) override {
      // Get the existing item's index
      int existingItemIndex = Search(existingItem);
      
      if (-1 == existingItemIndex) {
         return false; // not found
      }
      
      InsertAt(existingItemIndex + 1, newItem);
      return true;
   }
   
   virtual void InsertAt(int index, int item) {
      // Resize if the array is full
      if (allocationSize == length) {
         Resize(length * 2);
      }

      // Shift all the array items to the right,
      // starting from the last item and moving down to
      // the item at the given index
      for (int i = length; i > index; i--) {
         array[i] = array[i - 1];
      }
            
      // Insert the new item at the index
      array[index] = item;
        
      // Increment length to reflect the inserted item
      length++;
   }
   
   virtual bool IsEmpty() const override {
      return 0 == length;
   }
   
   virtual void Prepend(int item) override {
      // Resize if the array is full
      if (allocationSize == length) {
         Resize(length * 2);
      }
     
      // Shift all array items to the right,
      // starting from the last index and moving 
      // down to the first index.
      for (int i = length; i > 0; i--) {
         array[i] = array[i - 1];
      }
           
      // Insert the new item at index 0
      array[0] = item;
        
      // Increment length to reflect the added item
      length++;
   }
   
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const override {
      if (length > 0) {
         // Print first item without separator
         printStream << array[0];
      }
      
      // Print remaining items, each preceded by the separator
      for (int i = 1; i < length; i++) {
         printStream << separator << array[i];
      }
   }
   
   virtual void PrintInfo(std::ostream& printStream) const {
      printStream << "Allocation size: " << allocationSize;
      printStream << ", length: " << length;
   }
   
   virtual bool Remove(int item) override {
      int itemIndex = Search(item);
      if (itemIndex >= 0) {
         RemoveAt(itemIndex);
         return true;
      }
      
      return false; // not found
   }
   
   virtual void RemoveAt(int index) {
      // Make sure the index is valid for the current array
      if (index >= 0 && index < length) {
         // Shift down all items after the given index
         for (int i = index; i < length - 1; i++) {
            array[i] = array[i + 1];
         }

         // Update length to reflect the removed item
         length--;
      }
   }
   
   virtual int Search(int item) const {
      // Iterate through the entire array
      for (int i = 0; i < length; i++) {
         // If the current item matches the search
         // item, return the current index immediately.
         if (array[i] == item) {
            return i;
         }
      }

      // If the above loop finishes without returning,
      // then the search item was not found.
      return -1;
   }
};

#endif