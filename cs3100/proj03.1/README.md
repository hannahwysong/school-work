
# Project 3: MultiSet Design and Implementation

## Learning Objectives

- Design and implement a multiset (also known as a bag) abstract data type (ADT)
- Analyze trade-offs between different data structures, and justify choices in a design document
- Produce design document that communicates implementation plans, reasoning, and anticipated challenges

---

## Overview

In this two-part project, you will design and implement a `MultiSet` class. A multiset is like a set; however, elements may appear more than once. For our multiset, the elements will be C++ `std::string`.

You will first write a **design document** with explanations of how you will implement the `MultiSet`. This includes your choice of the underlying data structure: your hash table or AVL tree from previous projects. Alternatively, you may design your own custom structure (no standard C++ containers allowed).

Next, you will **implement standard multiset operations** (insert, remove, contains, count, etc.) and support set-like operations such as union, intersection, difference, and symmetric difference. You will also implement an **extension feature** from a list of options.

---

## Part 1: Design Document

Write a 3–5-page document in which you:

- Explain how you will implement the multiset
- Choose your internal data structure: HashTable, AVL Tree, or a custom structure
- Justify your choice
- Describe how you plan to implement core multiset operations
- Describe how you will implement the required set operations
- Identify any challenges anticipated and how you plan to address them

---

## Part 2: Implementation

Once the design document is complete, implement your `MultiSet` class in C++. You will receive a header file with the `MultiSet` class declaration. Implement all required methods, including the default constructor, copy constructor, assignment operator, and destructor (as needed).

---

## Core MultiSet Operations

Each operation should be implemented with the following signatures and explained in the design document.

```cpp
bool insert(const std::string& key, size_t num = 1);
```
Insert the key `num` times into the multiset. Always returns true.

```cpp
bool remove(const std::string& key, size_t num = 1);
```
Attempt to remove `num` instances of the given key. If not enough exist, return false.

```cpp
std::vector<std::string> remove(size_t num = 1);
```
Remove `num` arbitrary elements and return them in a vector.

```cpp
bool contains(const std::string& key) const;
```
Returns true if key exists in the multiset.

```cpp
size_t count(const std::string& key) const;
```
Returns the number of times `key` appears.

```cpp
std::vector<std::string> keys() const;
```
Return all elements in the multiset (with duplicates).

```cpp
std::vector<std::string> uniqueKeys() const;
```
Return one instance of each unique key.

```cpp
bool empty();
```
Returns true if the multiset is empty.

```cpp
size_t size() const;
```
Return the total number of elements, including duplicates.

```cpp
size_t uniqueSize() const;
```
Return the number of unique keys.

```cpp
void clear();
```
Remove all elements from the multiset.

```cpp
std::ostream& operator<< (std::ostream& os, const MultiSet& ms);
```
Output a representation of the multiset, e.g., `{key: count}`.

---

## Set Operations

### `MultiSet unionWith(const MultiSet& other) const;`

Return the union of two multisets.

Example:
- A = `{a, b, b, b, c, c, d, g}`
- B = `{a, a, c, c, d, e, f}`
- A ∪ B = `{a, a, b, b, b, c, c, d, e, f, g}`

### `MultiSet intersectionWith(const MultiSet& other) const;`

Return elements common to both multisets.

- A ∩ B = `{a, c, c, d}`

### `MultiSet differenceWith(const MultiSet& other) const;`

Return elements in `A` that are not in `B`.

- A − B = `{b, b, b, g}`

### `MultiSet symmetricDifferenceWith(const MultiSet& other) const;`

Return elements in either `A` or `B` but not both.

- A Δ B = `{a, b, b, b, e, f, g}`
- Equivalent to `(A − B) ∪ (B − A)`

---

## Extension Features (Choose at least one)

Choose **one** (or two for bonus points):

1. **Serialization/Deserialization**
    - Save/load multiset to/from file (text, binary, JSON, etc.)

2. **Generic Multiset (Templated Class)**
    - Make multiset support any type (not just strings)

3. **Iterator Support**
    - Support range-based for loops

4. **Equality and Comparison**
    - Implement `==`, `<=>`, `isSubsetOf()`, and `isSuperSetOf()`

5. **Cardinality Analytics**
    - Return a sorted list of `(element, count)` pairs by frequency

---

## Turn In and Grading

Submit two separate files:
- Design document (PDF/Word)
- Implementation (code files)

Submit to both Part 1 and Part 2 dropboxes on Pilot.

### Deliverables:
- Design explanation PDF
- `MultiSet.h` / `MultiSet.cpp`
- `main.cpp` with driver tests

---
