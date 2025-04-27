#ifndef QUADRATICPROBINGHASHTABLE_H
#define QUADRATICPROBINGHASHTABLE_H

#include <iostream>
#include <vector>
#include "MapADT.h"
#include "OpenAddressingBucket.h"

template <typename K, typename V>
class QuadraticProbingHashTable : public MapADT<K,V> {
protected:
   std::vector<OpenAddressingBucket<K,V>*> table;
   int c1;
   int c2;
  // Returns a non-negative hash code for the specified key.
   int Hash(const K& key) const {
      // The type must have a hash<K> class or struct defined in std namespace
      std::hash<K> hashFunctionObject;
      size_t keyHash = hashFunctionObject(key);
      
      // size_t is unsigned and likely more than 32 bits. Convert to int by 
      // masking out the lowest 31 bits.
      return (int)(keyHash & 0x7fffffff);
   }

public:
   QuadraticProbingHashTable(int c1 = 1, int c2 = 1, int initialCapacity = 11) {
      table.resize(initialCapacity, &OpenAddressingBucket<K,V>::EMPTY_SINCE_START);
      this->c1 = c1;
      this->c2 = c2;
   }
   
   virtual ~QuadraticProbingHashTable() {
      // Free all non-empty buckets
      for (int i = 0; i < table.size(); i++) {
         if (!table[i]->IsEmpty()) {
            // Deleting the bucket calls OpenAddressingBucket's destructor, 
            // which deallocates the bucket's key and value.
            delete table[i];
         }
      }
   }
   
   // Returns true if the specific key exists in the table, false otherwise.
   virtual bool Contains(const K& key) const override {
      return Get(key) != nullptr;
   }
   
   // Searches for the key, returning a pointer to the corresponding value if
   // found, nullptr if not found.
   virtual V* Get(const K& key) const override {

      // Get the key's hash code
      int hashCode = Hash(key);

      for (int i = 0; i < table.size(); i++) {
         int bucketIndex = (hashCode + c1 * i + c2 * i * i) % table.size();
         
         // An empty-since-start bucket implies the key is not in the table
         if (table[bucketIndex]->IsEmptySinceStart()) {
            return nullptr;
         }
         
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            // Check if the non-empty bucket has the key
            if (key == *table[bucketIndex]->key) {
               return table[bucketIndex]->value;
            }
         }
      }

      return nullptr; // key not found
   }
   
   // Returns the number of items in the hash table.
   virtual int GetLength() const override {
      int length = 0;
      for (auto* bucket : table) {
         // Increment the length only if the bucket is not empty
         if (!bucket->IsEmpty()) {
            length++;
         }
      }
      return length;
   }
   
   // Inserts the specified key/value pair. If the key already exists, the 
   // corresponding value is updated. If inserted or updated, true is returned. 
   // If not inserted, then false is returned.
   bool Insert(const K& key, const V& value) override {

      // Get the key's hash code
      int hashCode = Hash(key);

      // First search for the key in the table. If found, update bucket's value.
      for (int i = 0; i < table.size(); i++) {
         int bucketIndex = (hashCode + c1 * i + c2 * i * i) % table.size();
         
         // An empty-since-start bucket implies the key is not in the table
         if (table[bucketIndex]->IsEmptySinceStart()) {
            break;
         }
         
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            // Check if the non-empty bucket has the key
            if (key == *table[bucketIndex]->key) {
               // Update the value
               delete table[bucketIndex]->value;
               table[bucketIndex]->value = new V(value);
               return true;
            }
         }
      }
      
      // The key is not in the table, so insert into first empty bucket
      for (int i = 0; i < table.size(); i++) {
         int bucketIndex = (hashCode + c1 * i + c2 * i * i) % table.size();
         if (table[bucketIndex]->IsEmpty()) {
            table[bucketIndex] = new OpenAddressingBucket(key, value);
            return true;
         }
      }
      
      return false; // no empty bucket found
   }
   
   // Searches for the specified key. If found, the key/value pair is removed 
   // from the hash table and true is returned. If not found, false is returned.
   bool Remove(const K& key) override {

      // Get the key's hash code
      int hashCode = Hash(key);

      for (int i = 0; i < table.size(); i++) {
         int bucketIndex = (hashCode + c1 * i + c2 * i * i) % table.size();
         
         // An empty-since-start bucket implies the key is not in the table
         if (table[bucketIndex]->IsEmptySinceStart()) {
            return false;
         }
         
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            // Check if the non-empty bucket has the key
            if (key == *table[bucketIndex]->key) {
               // Remove by deleting and setting the bucket to empty-after-removal
               delete table[bucketIndex];
               table[bucketIndex] = &OpenAddressingBucket<K,V>::EMPTY_AFTER_REMOVAL;
               return true;
            }
         }
      }

      return false; // key not found
   }
   
   // Prints all items in the map.
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& keyValueSeparator = ":",
      const std::string& itemSeparator = ", ",
      const std::string& prefix = "",
      const std::string& suffix = "") const override {
      // Print the prefix first
      printStream << prefix;
      
      // First item print will be a special case
      bool printedFirstItem = false;
      
      // Loop through buckets
      for (auto* bucket : table) {
         // Print only if non-empty
         if (!bucket->IsEmpty()) {
            if (printedFirstItem) {
               // All items but first are preceded by the separator
               printStream << itemSeparator;
            }
            else {
               printedFirstItem = true;
            }
            printStream << *(bucket->key) << keyValueSeparator;
            printStream << *(bucket->value);
         }
      }
      
      // Print the suffix last
      printStream << suffix;
   }
   
   void PrintTable(std::ostream& printStream) const {
      for (int i = 0; i < table.size(); i++) {
         printStream << i << ": ";
         if (table[i]->IsEmptySinceStart()) {
            printStream << "EMPTY_SINCE_START" << std::endl;
         }
         else if (table[i]->IsEmptyAfterRemoval()) {
            printStream << "EMPTY_AFTER_REMOVAL" << std::endl;
         }
         else {
            printStream << *table[i]->key << ", ";
            printStream << *table[i]->value << std::endl;
         }
      }
   }
};

#endif