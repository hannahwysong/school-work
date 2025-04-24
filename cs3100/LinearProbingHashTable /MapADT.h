#ifndef MAPADT_H
#define MAPADT_H

#include <iostream>

template <typename K, typename V>
class MapADT {
public:
   virtual ~MapADT() {
   }
   
   // Inserts the specified key/value pair. If the key already exists, the
   // corresponding value is updated. If inserted or updated, true is returned.
   // If not inserted, then false is returned.
   virtual bool Insert(const K& key, const V& value) = 0;
   
   // Searches for the specified key. If found, the key/value pair is removed
   // from the map and true is returned. If not found, false is returned.
   virtual bool Remove(const K& key) = 0;
   
   // Returns true if the specific key exists in the map, false otherwise.
   virtual bool Contains(const K& key) const = 0;
   
   // Searches for the item with the specified key. Returns a pointer to the
   // item's value if found, nullptr if not found.
   virtual V* Get(const K& key) const = 0;
   
   // Returns the number of items in the map.
   virtual int GetLength() const = 0;
   
   // Prints all items in the map.
   virtual void Print(std::ostream& printStream = std::cout,
      const std::string& keyValueSeparator = ":",
      const std::string& itemSeparator = ", ",
      const std::string& prefix = "",
      const std::string& suffix = "") const = 0;
};

#endif