#include <iostream>
#include "ArrayQueue.h"
using namespace std;

int main() {
   // Make two queues, one bounded to 4 items and the other unbounded
   ArrayQueue boundedQueue(4);
   ArrayQueue unboundedQueue;
        
   // Enqueue 8 items in each
   cout << "Enqueueing values 1 through 8 to each queue" << endl;
   for (int i = 1; i <= 8; i++) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }
       
   // Dequeue two items from each queue
   cout << "Dequeuing twice" << endl;
   for (int i = 0; i < 2; i++) {
      cout << "  Dequeued " << boundedQueue.Dequeue();
      cout << " from bounded queue" << endl;
      cout << "  Dequeued " << unboundedQueue.Dequeue();
      cout << " from unbounded queue" << endl;
   }

   // Enqueue 4 more items
   cout << "Enqueueing values: 10, 20, 30 and 40" << endl;
   for (int i = 10; i <= 40; i+=10) {
      boundedQueue.Enqueue(i);
      unboundedQueue.Enqueue(i);
   }
        
   // Display contents of each queue
   cout << "Bounded queue (maxLength=";
   cout << boundedQueue.GetMaxLength();
   cout << ") contents:" << endl;
   while (boundedQueue.GetLength() > 0) {
      cout << "  " << boundedQueue.Dequeue() << endl;
   }
   cout << "Unbounded queue contents:" << endl;
   while (unboundedQueue.GetLength() > 0) {
      cout << "  " << unboundedQueue.Dequeue() << endl;
   }
}