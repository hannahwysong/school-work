#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
   int numbers[] = { 83, 44, 57, 66, 92, 49, 64, 55 };
      
   // Initialize a new Queue and add numbers
   Queue numQueue;
   for (int number : numbers) {
      numQueue.Enqueue(number);
   }

   // Print queue
   cout << "Queue: ";
   numQueue.Print();
   cout << endl;
   
   // Dequeue each item and print the queue. Repeat until empty.
   while (!numQueue.IsEmpty()) {
      cout << "Dequeued " << numQueue.Dequeue() << endl;
      cout << "Queue: ";
      numQueue.Print();
      cout << endl;
   }
   
   return 0;
}