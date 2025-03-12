/**
 * HashTable.h
 * CS 3100/5100
 *
 * You should not modify any of the code you are given in this file, however
 * you will need to add a few things per the assignment instructions
 */



#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <functional>
#include <string>
#include <vector>

/// enum BucketType
/// NORMAL: bucket is currently occipied with a valid key/value
/// ESS: bucket has empty since start (has never had a key/value)
/// EAR: bucket is empty after removal (aka tombstone, bucket used to hold
/// a key/value but they have been removed from the table)
enum class BucketType { NORMAL, ESS, EAR };

struct HashTableNode {
        std::string key;
        int value;
        HashTableNode* next;
        BucketType type;

        HashTableNode(const std::string& k, int v) : key(k), value(v), next(nullptr) {}
};

/// all members of HashTableBucket are public to make it easy
/// methods are defined in HashTable.cpp,
/// they are already written for you
class HashTableBucket {
public:
    std::string key;
    int value;
    BucketType type;
    HashTableNode* head;

    HashTableBucket();

    HashTableBucket(const std::string& k, int v);

    void load(const std::string& k, int v);

    bool remove(const std::string& key);

    void kill();

    std::string getKey() const;

    int getValue() const;

    BucketType getType() const;

    std::string toString() const;

    std::string toString(size_t index) const;

    bool isEmpty() const;

    bool isNormal() const;

    bool isEmptySinceStart() const;

    bool isEmptyAfterRemoval() const;

};

// overloads for operator<< to print buckets using cout
std::ostream& operator<<(std::ostream& os, const HashTableBucket& me);
std::ostream& operator<<(std::ostream& os,  std::pair<const HashTableBucket&,  size_t> bucket);

class HashTable {
private:
    // chaining method

    size_t tableSize;
    size_t numElements;

    size_t hash(const std::string& key) const;

    void resizeTable(double resizeFactor = 2.0);

    std::vector<size_t> makeShuffledVector(size_t N);

public:

    std::vector<HashTableBucket> table;

    void printLists() const;

    // don't change this, this is required for the assignment
    static constexpr size_t DEFAULT_INITIAL_CAPACITY = 8;

    HashTable(size_t initCapacity = DEFAULT_INITIAL_CAPACITY);

    bool insert(const std::string& key, int value);

    bool remove(const std::string& key);

    std::optional<int> get(const std::string& key) const;

    bool contains(const std::string& key) const;

    int& operator[](const std::string& key);

    std::vector<std::string> keys() const;

    double alpha() const;

    size_t capacity() const;

    size_t size() const;
};

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);
std::ostream& operator<<(std::ostream& os, std::pair<const HashTableBucket&, size_t> bucket);

#endif //HASHTABLE_H
