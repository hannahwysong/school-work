#ifndef STACKADT_H
#define STACKADT_H

#include <iostream>

class StackADT {
public:
   // Member functions that may change the stack
   virtual bool Push(int item) = 0;
   virtual int Pop() = 0;
   
   // Member functions that do not change the stack
   virtual int GetLength() const = 0;
   virtual bool IsEmpty() const = 0;
   virtual int Peek() const = 0;
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& separator = ", ") const = 0;
};

#endif