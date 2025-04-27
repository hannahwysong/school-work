#include <iostream>
#include <string>
#include <vector>
#include "QuadraticProbingHashTable.h"
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
   
   // Create a QuadraticProbingHashTable and add all items
   QuadraticProbingHashTable<string,string> table;
   for (int i = 0; i < (int) keys.size(); i++) {
      table.Insert(keys[i], values[i]);
   }
   
   // Print the table's items
   cout << "Items:" << endl;
   table.Print(cout, ": ", "\n", "", "\n");
   
   // Print the table's buckets
   cout << endl << "Buckets:" << endl;
   table.PrintTable(cout);
   
   // Remove some items
   cout << endl;
   vector<string> keysToRemove = { "LAX", "ORD" };
   for (const string& keyToRemove : keysToRemove) {
      cout << "Removing \"" << keyToRemove << "\"" << endl;
      table.Remove(keyToRemove);
   }
   
   // Print again
   cout << endl << "Buckets after removals:" << endl;
   table.PrintTable(cout);
      
   return 0;
}