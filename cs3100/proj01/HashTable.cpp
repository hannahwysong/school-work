/**
 * HashTable.h
 * CS 3100/5100
 */


 #include "HashTable.h"

 #include <chrono>
 #include <numeric>
 #include <random>
 #include <utility>
 #include <sstream>
 #include <optional>
#include <iostream>
 
 using namespace std;
 // HashTable methods
 
 /// The "default" constructor uses our default capacity
 /// You can create a hashtable without passing any parameters
 /// @param size the initial capacity of the hash table
 HashTable::HashTable(size_t initCapacity) : tableSize(initCapacity), numElements(0){
     table.resize(tableSize);
 }
 /// hash(key)
 /// A "default" hash function provided by the C++ library.
 /// It provides a way to hash objects of the string type.
 /// The resulting hash value is used to index into the hash table.
 /// @param key the key which is used to determine where in the table the value is stored
 /// @return the hashed string value
 size_t HashTable::hash(const std::string& key) const {
    size_t hashValue = std::hash<std::string>{}(key);
    return hashValue % table.size(); 
}
 
 /// insert(key, value)
 /// insert the key value pair into the table
 /// @param key the key which is used to determine where in the table the value is stored
 /// @param value the value assosiated with the given key
 /// @return if key is in the table, or if the table is full, return false
 /// otherwise return true
 bool HashTable::insert(const string& key, int value) {
    size_t index = hash(key);
    HashTableNode* current = table[index].head;
    while (current != nullptr) {
        if (current->key == key) {
            return false;
        }
        current = current->next;
    }
    HashTableNode* newNode = new HashTableNode(key, value);
    newNode->next = table[index].head;
    table[index].head = newNode;
    table[index].type = BucketType::NORMAL;
    ++numElements;
    return true;
}
 
 /// remove(key)
 /// the key and value are "deleted" from the table
 /// in actuality, the buckets are "killed" and marked as
 /// EAR (tombstone)
 /// @param key the key for the value to be removed
 /// @return true if the key was found and removed, otherwise false
 bool HashTable::remove(const string& key) {
    size_t index = hash(key);
    HashTableBucket& bucket = table[index];
    HashTableNode* current = bucket.head;
    HashTableNode* previous = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (previous) {
                previous->next = current->next;
            } else {
                bucket.head = current->next;
            }
            delete current; 
            bucket.kill();
            --numElements;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
 }
 
 /// contains(key)
 /// determines whether the key is in the table or not
 /// @param key the key to be searched for
 /// @return true if given key is in the table, otherwise false
 bool HashTable::contains(const string& key) const {
    size_t index = hash(key);
    HashTableNode* current = table[index].head;
    while (current != nullptr) {
        if (current->key == key && current->type != BucketType::EAR) {
            return true;
        }
        current = current->next;
    }
    return false;
}
 
 /// get(key)
 /// searches for the value associated with the given key
 /// @param key the key to search for
 /// @return the value associated with the key, if the key is not
 /// in the table find returns nullopt
 optional<int> HashTable::get(const string& key) const {
    size_t index = hash(key);
    const HashTableBucket& bucket = table[index];
    HashTableNode* current = bucket.head;
    while (current != nullptr) {
        if (current->key == key && current->type != BucketType::EAR) {
            return current->value;
        }
        current = current->next;
    }
    return nullopt;
 }
 
 /// operator[key]
 /// return a reference to the value associated with the key
 /// this allows statements like:
 /// int value = hashTable[key];
 /// and
 /// hashTable[key] = value;
 /// @param key the key associated with the value to search for
 /// @return a reference to the value associated with the key
 /// if the key is not in the table, the behavior is undefined
 int& HashTable::operator[](const string& key) {
    auto value = get(key);
    if (value) {
        return *value;
    }
    int index = hash(key);
    return table[index].value; 
 }
 
 /// keys()
 /// get all the keys stored in the table
 /// @return a vector of strings of all the keys
 ///  should all be just from NORMAL slots
 vector<string> HashTable::keys() const {
     std::vector<std::string> keyList;
     for (size_t i = 0; i < tableSize; ++i) {
         const auto& bucket = table[i];
         if (bucket.isNormal()) {
            HashTableNode* current = table[i].head;
            while (current != nullptr) {
                keyList.push_back(current->key);
                current = current->next;
                }
         }
     }
     return keyList;
 }
 
 /// alpha()
 /// the load factor
 /// number of elements / table capacity
 /// @return the current alpha/load factor
 double HashTable::alpha() const {
     return static_cast<double>(numElements) / tableSize;
 }
 
 /// capacity()
 /// how many buckets the table can currently hold
 /// @return the current capacity of the table
 size_t HashTable::capacity() const {
     return tableSize;
 }
 
 /// size()
 /// how many key-value pairs are currently in the table
 /// alternatively, how many buckets are NORMAL
 /// @return number of elements currently in the table
 size_t HashTable::size() const {
     return numElements;
 }
 
 /// resizeTable(factor)
 /// precondition: table has elements
 /// postcondition: table capacity increased to current capacity * resizeFactor
 /// all the elements remain in the table, and will need to be re-hashed based on the new capacity
 /// @param resizeFactor how much to resize the table by
 void HashTable::resizeTable(double resizeFactor) {
    size_t newCapacity = static_cast<size_t>(tableSize * resizeFactor);
    vector<HashTableBucket> newTable(newCapacity);
    for (size_t i = 0; i < tableSize; ++i) {
        HashTableBucket& bucket = table[i];
        HashTableNode* current = bucket.head;
        while (current != nullptr) {
            size_t newIndex = hash(current->key) % newCapacity;  
            newTable[newIndex].load(current->key, current->value); 
            current = current->next;
        }
    }
    table = std::move(newTable);
    tableSize = newCapacity;
 }
 
 /// makeShuffledVector is provided for you
 /// @param N ths capacity of our hash table
 /// make sure to pass the capacity and not capacity - 1
 /// makeShuffledVector takes care of that for us
 /// @return vector of length N - 1 that has values 1 to N - 1 shuffled
 vector<size_t> HashTable::makeShuffledVector(size_t N) {
     vector<size_t> arrayShuffle(N - 1);
     iota(arrayShuffle.begin(), arrayShuffle.end(), 1);
     // obtain a time-based seed for the shuffle
     auto seed = static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
     seed = 0; // for testing you can comment th is out so the shuffled array is always shuffled the same
     // vector will be shuffled in-place
     shuffle(arrayShuffle.begin(), arrayShuffle.end(), default_random_engine(seed));
     return arrayShuffle;
 }
 /// printLists()
 /// Prints the contents of each bucket.
 /// Does not print the bucket if the bucket is empty.
 void HashTable::printLists() const {
    for (size_t i = 0; i < tableSize; ++i) {
        const auto& bucket = table[i];
        if (bucket.head != nullptr) {
            cout << "Bucket " << i << ": ";
            HashTableNode* current = bucket.head;
            while (current != nullptr) {
                if (current->key != "" && current->value != 0) {
                    cout << "<" << current->key << ", " << current->value << "> ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }
}
 
 /// opeartor<<(ostream, HashTable)
 /// overload of << to output to stream
 /// Should only print normal (occupied) buckets
 /// You should use the << overload for the bucket and index
 /// So the bucket contents are output with the bucket's index
 /// You can use it like:
 /// os << pair{bucket, index};
 /// @param os the ostream to output to
 /// @param hashTable the hash table to print
 /// @return reference to the ostream
 ostream& operator<<(ostream& os, const HashTable& hashTable) {
     hashTable.printLists();
     return os;
 }
 
 /******************************************************
  **************    HashTableBucket    *****************
  ******************************************************/
 // you shouldn't need to change these, but read through
 // and make sure you understand what each one does
 
 /// empty constructor
 /// initializes the value to zero (not really necessary)
 /// and sets the bucket type to empty since start
 HashTableBucket::HashTableBucket() : value(0), type(BucketType::ESS) {
 }
 
 /// parameterized constructor(key, value)
 /// creates a new bucket with the given key and value
 /// the bucket is marked as normal
 /// @param k the lookup key for the bucket
 /// @param v the value associated with the key
 HashTableBucket::HashTableBucket(const string& k,
                                  int v) : key(std::move(k)),
                                           value(v),
                                           type(BucketType::NORMAL) {
 }
 
 
 /// load(key, value)
 /// update the key and value stored in the bucket
 /// bucket is marked as normal to denote it is occupied
 /// @param k new key
 /// @param v new value
 void HashTableBucket::load(const string& k, int v) {
     key = std::move(k);
     value = v;
     type = BucketType::NORMAL;
 }
 
 /// kill()
 /// clear the key and value, and mark the slot as EAR (tombstone)
 void HashTableBucket::kill() {
     key.clear();
     value = 0;
     type = BucketType::EAR;
 }
 
 /// getKey()
 /// get the key stored in the bucket
 /// @return the bucket's key
 string HashTableBucket::getKey() const {
     return key;
 }
 
 /// getValue()
 /// get the value stored in the bucket
 /// @return the bucket's value
 int HashTableBucket::getValue() const {
     return value;
 }
 
 /// getType()
 /// get the current type of the bucket
 /// @return the bucket's type (NORMAL, ESS, EAR)
 BucketType HashTableBucket::getType() const {
     return type;
 }
 
 /// isEmpty()
 /// determines if bucket is empty either since start or after remove
 /// @return true if bucket is ESS or EAR, otherwise false
 bool HashTableBucket::isEmpty() const {
     return type == BucketType::EAR || type == BucketType::ESS;
 }
 
 /// isNormal()
 /// determines if bucket is normal/occupied
 /// @return true if bucket is NORMAL, otherwise false
 bool HashTableBucket::isNormal() const {
     return type == BucketType::NORMAL;
 }
 
 /// isEmptySinceStart()
 /// determines only if bucket is ESS
 /// @return true is the bucket is ESS, otherwise false
 bool HashTableBucket::isEmptySinceStart() const {
     return type == BucketType::ESS;
 }
 
 /// isEmptyAfterRemoval()
 /// determines only if bucket is EAR
 /// @return true if bucket is EAR, otherwise false
 bool HashTableBucket::isEmptyAfterRemoval() const {
     return type == BucketType::EAR;
 }
 
 /// toString()
 /// format the bucket's contents to a string
 /// if bucket is empty, the string does not
 /// have the key and value
 /// @return a string with the key and value
 /// if bucket is empty, string is: "[empty]"
 string HashTableBucket::toString() const {
     stringstream result;
     if (isEmpty()) {
         result << "[empty]";
     } else {
         result << "<" << key << ", " << value << ">";
     }
     return result.str();
 }
 
 /// format the bucket's contents to a string
 /// along with the given index
 /// if bucket is empty, the string does not
 /// have the key and value
 /// @param index the index of the bucket in the table
 /// @return a string with the index, key and value
 string HashTableBucket::toString(size_t index) const {
     stringstream result;
     if (isEmpty()) {
         result << "[empty]";
     } else {
         result << "Bucket "<< index << ": " << *this;
     }
     return result.str();
 }
 
 /// operator<<(ostream, HashTableBucket)
 /// overload of << for outputting bucket to stream
 /// @param os the ostream to output to
 /// @param bucket the bucket being output
 /// @return reference to the ostream
 ostream& operator<<(ostream& os, const HashTableBucket& bucket) {
     os << bucket.toString();
     return os;
 }
 
 /// operator<<(ostream, pair<HashTableBucket, size_t>)
 /// overload of << to output bucket to stream
 /// second argument used to print the index of the bucket in the table
 /// would be used like:
 /// cout << pair{bucket, index};
 /// @param os the ostream to output to
 /// @param bucket a pair with the bucket and bucket's index
 /// @return reference to the ostream
 ostream& operator<<(ostream& os, pair<const HashTableBucket&,  size_t> bucket) {
     os << bucket.first.toString(bucket.second);
     return os;
 }
 