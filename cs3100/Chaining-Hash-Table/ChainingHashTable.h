#ifndef CHAININGHASHTABLE_H
#define CHAININGHASHTABLE_H

#include <iostream>
#include <vector>
#include "MapADT.h"

// ChainingHashTableItem represents one item in the hash table.
template <typename K, typename V>
class ChainingHashTableItem {
public:
   K key;
   V value;
   ChainingHashTableItem<K,V>* next;

   ChainingHashTableItem(const K& itemKey, const V& itemValue) :
      key(itemKey), value(itemValue) {
      next = nullptr;
   }
};

template <typename K, typename V>
class ChainingHashTable : public MapADT<K,V> {
private:
   std::vector<ChainingHashTableItem<K,V>*> table;

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
   ChainingHashTable(int initialCapacity = 11) {
      table.resize(initialCapacity, nullptr);
   }
   
   virtual ~ChainingHashTable() {
      // Delete each ChainingHashTableItem in the table
      for (int i = 0; i < table.size(); i++) {
         ChainingHashTableItem<K,V>* item = table[i];
         while (item) {
            ChainingHashTableItem<K,V>* itemToDelete = item;
            item = item->next;
            delete itemToDelete;
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
      // Hash the key and compute the bucket index
      int bucketIndex = this->Hash(key) % table.size();
      
      // Search the bucket's linked list for the key
      ChainingHashTableItem<K,V>* item = table[bucketIndex];
      while (item) {
         if (key == item->key) {
            return &item->value;
         }
         item = item->next;
      }
      
      return nullptr; // key not found
   }
   
   virtual int GetLength() const override {
      int length = 0;
      
      // Loop through buckets
      for (auto* bucket : table) {
         ChainingHashTableItem<K,V>* item = bucket;
         
         // Loop through the bucket's linked list
         while (item) {
            // Increment the length
            length++;
            
            // Advance to next item in the bucket's linked list
            item = item->next;
         }
      }
      
      return length;
   }
   
   // Inserts the specified key/value pair. If the key already exists, the 
   // corresponding value is updated. If inserted or updated, true is returned. 
   // If not inserted, then false is returned.
   bool Insert(const K& key, const V& value) override {
      // Hash the key to get the bucket index
      int bucketIndex = this->Hash(key) % table.size();
      
      // Traverse the linked list, searching for the key. If the key exists in 
      // an item, the value is replaced. Otherwise a new item is appended.
      ChainingHashTableItem<K,V>* currentItem = table[bucketIndex];
      ChainingHashTableItem<K,V>* previousItem = nullptr;
      while (currentItem) {
         if (key == currentItem->key) {
            currentItem->value = value;
            return true;
         }
         
         previousItem = currentItem;
         currentItem = currentItem->next;
      }
      
      // Append to the linked list
      if (table[bucketIndex] == nullptr) {
         table[bucketIndex] = new ChainingHashTableItem(key, value);
      }
      else {
         previousItem->next = new ChainingHashTableItem(key, value);
      }
      return true;
   }
   
   // Searches for the specified key. If found, the key/value pair is removed 
   // from the hash table and true is returned. If not found, false is returned.
   bool Remove(const K& key) override {
      // Hash the key and compute bucket index
      int bucketIndex = this->Hash(key) % table.size();
      
      // Search the bucket's linked list for the key
      ChainingHashTableItem<K,V>* currentItem = table[bucketIndex];
      ChainingHashTableItem<K,V>* previousItem = nullptr;
      while (currentItem) {
         if (key == currentItem->key) {
            if (previousItem == nullptr) {
               // Remove linked list's first item
               table[bucketIndex] = currentItem->next;
            }
            else {
               previousItem->next = currentItem->next;
            }
            delete currentItem;
            return true;
         }
         
         previousItem = currentItem;
         currentItem = currentItem->next;
      }
      
      return false; // key not found
   }
   
   // Prints all items in the table.
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& keyValueSeparator = ": ",
      const std::string& itemSeparator = ", ",
      const std::string& prefix = "",
      const std::string& suffix = "") const override {
      // Print the prefix first
      printStream << prefix;
      
      // First item print will be a special case
      bool printedFirstItem = false;
      
      // Loop through buckets
      for (auto* bucket : table) {
         ChainingHashTableItem<K,V>* item = bucket;
         
         // Loop through the bucket's linked list
         while (item) {
            if (printedFirstItem) {
               // All items but first are preceded by the separator
               printStream << itemSeparator;
            }
            else {
               printedFirstItem = true;
            }
            
            // Print the item's key and value with the separator between
            printStream << item->key << keyValueSeparator << item->value;
            
            // Advance to next item in the bucket's linked list
            item = item->next;
         }
      }
      
      // Print the suffix last
      printStream << suffix;
   }
   
   // Prints the hash table's data, including empty buckets.
   void PrintTable(std::ostream& printStream) const {
      for (int i = 0; i < table.size(); i++) {
         printStream << i << ": ";
         
         if (table[i] == nullptr) {
            printStream << "(empty)" << std::endl;
         }
         else {
            ChainingHashTableItem<K,V>* item = table[i];
            
            // Print first item and move to next
            printStream << item->key << ": " << item->value;
            item = item->next;
            
            // Print remaining items, each preceded by "-->"
            while (item) {
               printStream << " --> " << item->key << ": " << item->value;
               item = item->next;
            }
            printStream << std::endl;
         }
      }
   }
};

#endif