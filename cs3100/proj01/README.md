# Project #1 – Map ADT: [Hash Table](/cs3100/proj01/Project1_HashTable.pdf)

## Learning Objectives

- Implement a data structure to meet given specifications
- Design, implement, and use a close hash table data structure
- Utilize efficient techniques for managing collisions in hash tables
- Understand dynamic resizing strategies for hash tables
- Implement a hash table as a Map ADT to store key-value pairs
- Analyze the efficiency of hash table operations
- Practice operator overloading for better usability in C++

## Overview

The Map ADT, sometimes called a Dictionary, provides a way to access values based on keys. It is often represented as `<KeyType, ValueType>`. For example, if we wanted to store customer names and look them up using their customer ID, we could have an integer key representing the customer ID and a string value representing their name.

Alternatively, we could store the customer IDs in the Map and use the customer’s name as the key to look up their ID. In this case, the key would be a string, and the value would be an integer.

For our Map, we will use strings for keys and integers for values:

```cpp
Map<string, int> myMap;
```

However, to simplify implementation in C++, we will fix the types of the key and value to strings and integers. This allows us to focus on implementing the hash table efficiently rather than handling multiple data types.

## Hash Table Representation

There are two primary ways to handle collision resolution in hash tables:

1. **Chaining** - Each index contains a linked list of entries that share the same hash value.
2. **Probing** - Each index contains a single entry, and collisions are resolved using a probing technique within the array.

For this project, you must decide whether to implement chaining or probing. If you choose probing, you must further decide between pseudo-random probing and double hashing.

## HashTableBucket Class

The `HashTableBucket` class is provided for storing key-value pairs. This class supports:

- `string` keys
- `int` values
- An enum `BucketType` to distinguish between empty (never used), empty (after removal), and occupied buckets.

This approach helps differentiate between different bucket states, improving efficiency during lookup operations.

## The HashTable Class

You will be provided with two files:

- `HashTable.h` (header file) - Contains method declarations and necessary data structures.
- `HashTable.cpp` - Contains method stubs for `HashTable` and `HashTableBucket` classes.

You should not modify any given code but will implement method bodies and add any required member data or helper functions.

### Required Methods

#### `HashTable::HashTable(size_t initCapacity)`

Initializes the hash table with a given capacity. The choice of capacity and how it affects resizing depends on your collision resolution strategy.

#### `bool HashTable::insert(const string& key, int value)`

Inserts a key-value pair into the table. Returns `true` on success and `false` on failure (e.g., duplicate key). Proper handling of collisions is necessary.

#### `bool HashTable::remove(const string& key)`

Removes a key-value pair if the key exists. In chaining, this means deleting a node in a linked list, while in probing, it may involve marking a bucket as deleted.

#### `bool HashTable::contains(const string& key) const`

Returns `true` if the key exists in the table, otherwise `false`. This operation must be implemented efficiently.

#### `optional<int> HashTable::get(const string& key) const`

Returns the value associated with a key if found, otherwise `nullopt`. This avoids returning invalid values such as `-1`.

#### `int& operator[](const string& key)`

Provides bracket access to values, allowing retrieval and modification. If the key does not exist, behavior is undefined.

#### `vector<string> HashTable::keys() const`

Returns a vector of all keys currently in the table. This helps in iterating through the stored data efficiently.

#### `double HashTable::alpha() const`

Returns the current load factor (`size / capacity`). Ensuring this method runs in O(1) time is important.

#### `size_t HashTable::capacity() const`

Returns the total number of buckets. The value should reflect any dynamic resizing done.

#### `size_t HashTable::size() const`

Returns the number of key-value pairs in the table.

#### `ostream& operator<<(ostream& os, const HashTable& hashTable)`

Overloads `<<` to print only occupied buckets along with their indices. Example output:

```plaintext
Bucket 5: <James, 4815>
Bucket 2: <Juliet, 1623>
Bucket 11: <Hugo, 42108>
```

## Table Data Structure

### Chaining

If using chaining, implement a custom linked list, **not** standard C++ containers. The table will be stored as:

```cpp
vector<MyGreatLinkedList> dataTable;
```

Where `MyGreatLinkedList` nodes store a bucket and a pointer to the next node.

### Open Addressing

If using open addressing, manually manage an array:

```cpp
HashTableBucket* dataTable;
```

Standard C++ containers are **not** allowed for storage.

## Probe Function (Open Addressing)

If using open addressing, choose between:

- **Pseudo-random probing** - Uses a random-like sequence to find open spots.
- **Double hashing** - Uses a secondary hash function to determine probe steps.

Properly implementing these functions is key to avoiding clustering issues.

## Table Resizing

The hash table must dynamically resize, doubling in size when necessary. The expansion condition can be one of:

- Load factor exceeds `0.5`
- Insert collisions exceed `N/3`
- Bucket list length exceeds `3` (for chaining)

Resizing should involve rehashing all existing elements.

## Time Complexity Analysis

For the chosen data structure, analyze the time complexity of:

- `insert`
- `remove`
- `contains`
- `get`
- `operator[]`

Provide justifications as comments in the code. Consider:

- The impact of collision resolution strategies.
- Worst-case scenarios for insert and lookup.
- How resizing affects performance over time.

By analyzing these aspects, you will gain deeper insights into hash table efficiency and trade-offs.

