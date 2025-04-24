#include <iostream>
#include <string>
#include <vector>
#include "ChainingHashTable.h"
using namespace std;

int main() {
   vector<string> keys = {
      "LAX", "IAH", "IAD",
      "ORD", "SFO", "DAL",
      "NRT", "JFK", "YVR",
      "LHR"
   };
   vector<string> values = {
      "Los Angeles", "Houston", "Washington",
      "Chicago", "San Francisco", "Dallas",
      "Tokyo", "New York", "Vancouver",
      "London"
   };
   
   // Create a ChainingHashTable and add all items
   ChainingHashTable<string,string> chaining;
   for (int i = 0; i < (int) keys.size(); i++) {
      chaining.Insert(keys[i], values[i]);
   }
   
   // Print the table's buckets
   cout << "Buckets:" << endl;
   chaining.PrintTable(cout);

   // Remove some items
   cout << endl;
   vector<string> keysToRemove = { "LAX", "ORD" };
   for (const string& keyToRemove : keysToRemove) {
      cout << "Removing \"" << keyToRemove << "\"" << endl;
      chaining.Remove(keyToRemove);
   }
   
   // Print again
   cout << endl << "Buckets after removals:" << endl;
   chaining.PrintTable(cout);
      
   return 0;
}