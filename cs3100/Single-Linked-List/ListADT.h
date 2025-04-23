#ifndef LISTADT_H
#define LISTADT_H

#include <iostream>
#include <ostream>
#include <string>

class ListADT {
public:
   // Member functions that may change the list
   virtual void Append(int item) = 0;
   virtual bool InsertAfter(int existingItem, int newItem) = 0;
   virtual void Prepend(int item) = 0;
   virtual bool Remove(int item) = 0;
   
   // Member functions that do not change the list
   virtual bool Contains(int item) const = 0;
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const = 0;
   virtual bool IsEmpty() const = 0;
   virtual int GetLength() const = 0;
};

#endif