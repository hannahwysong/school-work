#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main(int argc, char* argv[]) {
   // Make two stacks, one bounded to 4 items and the other unbounded
   ArrayStack boundedStack(4);
   ArrayStack unboundedStack;
    
   // Push 8 items to each
   cout << "Pushing values 1 through 8 to each stack" << endl;
   for (int i = 1; i <= 8; i++) {
      boundedStack.Push(i);
      unboundedStack.Push(i);
   }
   
   // Pop two items off each stack
   cout << "Popping twice" << endl;
   for (int i = 0; i < 2; i++) {
      boundedStack.Pop();
      unboundedStack.Pop();
   }

   // Push 4 more items onto each stack
   cout << "Pushing values to each stack: 10, 20, 30 and 40" << endl;
   for (int i = 10; i <= 40; i += 10) {
      boundedStack.Push(i);
      unboundedStack.Push(i);
   }
    
   // Display contents of each stack
   cout << "Bounded stack (maxLength=" << boundedStack.GetMaxLength();
   cout << ") contents:" << endl;
   while (boundedStack.GetLength() > 0) {
      cout << "  " << boundedStack.Pop() << endl;
   }
   cout << "Unbounded stack contents:" << endl;
   while (unboundedStack.GetLength() > 0) {
      cout << "  " << unboundedStack.Pop() << endl;
   }
   
   return 0;
}