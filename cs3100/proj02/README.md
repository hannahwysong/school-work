# Project #2 – Map ADT: [AVL Tree](/cs3100/proj02/Project02_AVLTree.pdf)

## Learning Objectives

- Demonstrate effective use of memory management techniques in C++
- Implement a data structure to meet given specifications
- Design, implement, and use an AVL tree data structure
- Analyze operations for time complexity

## Overview

Your task for this assignment is to implement an AVL tree that serves as a map data type (sometimes also called a dictionary). A map allows you to store and retrieve key-value pairs. For this project, the key will be an array of characters (string) and the value will be an integer. Regardless of what you are told, you will never use recursion in any of your code.

## The AVLTree Class

You will create a C++ class named `AVLTree`. For this project, you must write your own AVL tree – not using code from outside sources except for class notes and the textbook. Your AVL tree should remain balanced by implementing single and double rotations when inserting and removing data. Your tree must implement the following methods (ensure you copy the names, parameter types, and return types exactly):

### Methods

#### `bool AVLTree::insert(const string& key, int value)`
- Insert a new key-value pair into the tree.
- After insertion, the tree is rebalanced if necessary.
- Duplicate keys are not allowed.
- Returns `true` if the insertion was successful, `false` otherwise.
- Time complexity: **O(log n)**.

#### `bool AVLTree::remove(const string& key) const`
- Removes the key-value pair from the tree if the key exists.
- Releases memory for the removed node.
- Rebalances the tree if necessary.
- Returns `true` if the key was removed, `false` if the key was not found.
- Time complexity: **O(log n)**.

#### `bool AVLTree::contains(const string& key) const`
- Returns `true` if the key is in the tree, `false` otherwise.
- Time complexity: **O(log n)**.

#### `optional<int> AVLTree::get(const string& key) const`
- Returns the value associated with the key if found.
- If not found, returns `nullopt` (a special value in C++ indicating no valid return value).
- Time complexity: **O(log n)**.

#### `int& AVLTree::operator[](const string& key)`
- Allows access and modification of values using bracket notation.
- Returns a reference to the value associated with the key.
- If the key does not exist, behavior is undefined.
- Time complexity: **O(log n)**.

#### `vector<int> AVLTree::findRange(string lowKey, string highKey) const`
- Returns a vector containing all values associated with keys in the range `[lowKey, highKey]`.
- If no matching key-value pairs are found, returns an empty vector.
- Example: `findRange("G", "W")` returns `{71, 74, 83}`.

#### `vector<string> AVLTree::keys() const`
- Returns a vector with all keys currently in the tree.

#### `size_t AVLTree::size() const`
- Returns the number of key-value pairs in the tree.
- Time complexity: **O(1)**.

#### `size_t AVLTree::getHeight() const`
- Returns the height of the AVL tree.
- Time complexity: **O(1)**.

### Operator Overloading

#### `ostream& operator<<(ostream& os, const AVLTree & avlTree)`
- Enables easy printing of the tree.
- Should output key-value pairs in a structured format, such as a sideways representation using indentation.
- Example:
  ```
  <Z: 90>
      <X: 88>
  <S: 83>
      <J: 74>
  <G: 71>
      <C: 67>
  ```

### Copy and Assignment Operators

#### `AVLTree(const AVLTree& other)`
- Implements a deep copy of the tree.
- Uses a traversal method (e.g., preorder) to copy each node.

#### `void operator=(const AVLTree& other)`
- Implements deep copy assignment.
- Releases existing memory before copying data from `other`.

#### `~AVLTree()`
- Implements a destructor to free all allocated memory.
- Uses a postorder traversal to delete all nodes.

## Recursion

For this project, the methods `insert`, `remove`, `contains`, `get`, `operator[]`, `findRange`, `keys`, the copy constructor, the assignment operator, and the destructor **must** utilize recursion.

### Tips for Recursion

- **Base Case**: Typically, the base case will check if the current node is `nullptr`, indicating the bottom of the tree.
- **Perform Actions After Recursive Calls**: After inserting, update the height and check for rebalancing as recursion unwinds.
- **Passing Pointers by Reference**: This technique allows modifications to persist outside the function.

Example:
```cpp
void passNodePtrRef(Node*& node) {
    node = new Node(7); // Assigns a new Node to the pointer
}
```

If recursion is not used where required, you will receive **no credit** for this assignment.


