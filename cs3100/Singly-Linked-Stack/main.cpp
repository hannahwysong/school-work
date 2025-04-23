#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
   int numbers[] = { 76, 81, 91, 34, 62, 88, 77, 21, 18 };
      
   // Initialize a new Stack and add numbers
   Stack numStack;
   for (int number : numbers) {
       numStack.Push(number);
   }
   
   // Show the stack before any pop operations occur
   cout << "Stack: ";
   numStack.Print();
   cout << endl;
   
   // Pop until stack is empty, printing each popped item and remaining stack
   while (!numStack.IsEmpty()) {
      cout << "Popped " << numStack.Pop() << endl;
      cout << "Stack: ";
      numStack.Print();
      cout << endl;
   }
   
   return 0;
}