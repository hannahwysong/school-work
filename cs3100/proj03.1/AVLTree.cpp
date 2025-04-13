/**
* AVLTree.cpp
 * CS 3100/5100
 */

#include "AVLTree.h"
#include <optional>
#include <iostream>

using namespace std;
auto *avlTree = new AVLTree;
// AVLTree methods

/// The Constructor
/// Creates an AVLTree with no root and 0 nodes
AVLTree::AVLTree() : root(nullptr), numNodes(0) {}

/// The Destructor
/// Recursively deletes all nodes
AVLTree::~AVLTree() {
    deleteSubtree(root);
}

/// Copy Constructor
/// Recursively creates a deep copy
/// @param other The AVLTree being copied
AVLTree::AVLTree(const AVLTree& other) : root(nullptr), numNodes(0) {
    root = copySubtree(other.root);
    numNodes = other.numNodes;
}

/// deleteSubtree(node)
/// Recursively delete nodes
/// @param node The internal node being deleted
void AVLTree::deleteSubtree(AVLTreeNode* node) {
    if (!node) return;
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

/// insert(key, value)
/// Calls the recursive insertNode, which:
/// Inserts a node to the left child if smaller
/// Does not insert duplicate nodes.
/// After insertion, it updates height and balances the tree.
/// @param key the key being inserted
/// @param value the key pair value
/// @return true if insert node is successful, false otherwise
bool AVLTree::insert(const string& key, int value) {
    return insertNode(root, key, value);
}

/// insertNode(node, key, value)
/// Inserts a node if it doesn't already exist
///  Updates the height after adding node. Balances if needed.
/// @param node node being inserted
/// @param key key being inserted
/// @param value the key pair value
/// @return true if node was inserted, false if the key value already exists
bool AVLTree::insertNode(AVLTreeNode*& node, const string& key, int value) {
    if (!node) {
        node = new AVLTreeNode(key, value);
        numNodes++;
        return true;
    }

    if (key < node->key) {
        if (!insertNode(node->left, key, value)) return false;
    } else if (key > node->key) {
        if (!insertNode(node->right, key, value)) return false;
    } else {
        return false;
    }

    updateHeight(node);
    balance(node);
    return true;
}

/// remove(key)
/// Deletes the node assigned with the key
/// @param key The key value being removed
/// @return true if the node is removed, false otherwise.
bool AVLTree::remove(const string& key) {
    return removeNode(root, key);
}

/// removeNode(node, key)
/// Deletes the node recursively
/// The child becomes the parent if there is only one child
/// Otherwise next child becomes the parent
/// Updates the height after removing. Balances if needed.
/// @param node the node being removed
/// @param key the key value being removed
/// @return false if the node doesnt exist, true otherwise
bool AVLTree::removeNode(AVLTreeNode*& node, const string& key) {
    if (!node) return false;

    if (key < node->key) {
        return removeNode(node->left, key);
    } else if (key > node->key) {
        return removeNode(node->right, key);
    } else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if (!node->left) {
            AVLTreeNode* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            AVLTreeNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            AVLTreeNode* successor = node->right;
            while (successor && successor->left) {
                successor = successor->left;
            }

            node->key = successor->key;
            node->value = successor->value;
            removeNode(node->right, successor->key);
        }

        numNodes--;
        if (node) {
            updateHeight(node);
            balance(node);
        }
        return true;
    }
}

/// updateHeight(node)
/// Updates height based on children height
/// @param node The node the height update is based on
void AVLTree::updateHeight(AVLTreeNode* node) {
    if (!node) return;
    int left = node->left ? node->left->height : 0;
    int right = node->right ? node->right->height : 0;
    node->height = 1 + max(left, right);
}

/// getBalenceFactor(node)
/// Balance factor helper
/// @param The node that is being balanced
/// @return the balance factor of the subtree
int AVLTree::getBalanceFactor(AVLTreeNode* node) {
    if (!node) return 0;
    int left = node->left ? node->left->height : 0;
    int right = node->right ? node->right->height : 0;
    return left - right;
}

/// balance(node)
/// Rotates the tree if the balance factor is out of range
/// @param node The node being balanced
void AVLTree::balance(AVLTreeNode*& node) {
    int balance = getBalanceFactor(node);

    if (balance > 1) {
        if (getBalanceFactor(node->left) < 0) {
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
    else if (balance < -1) {
        if (getBalanceFactor(node->right) > 0) {
            rotateRight(node->right);
        }
        rotateLeft(node);
    }
}

/// rotateLeft(node)
/// Performs a left rotation to balance the tree.
/// @param node The node the rotation is based on
void AVLTree::rotateLeft(AVLTreeNode*& node) {
    AVLTreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node = newRoot;

    updateHeight(node->left);
    updateHeight(node);
}

/// rotateRight(node)
/// Performs a right rotation to balance the tree.
/// @param node The node the rotation is based on
void AVLTree::rotateRight(AVLTreeNode*& node) {
    AVLTreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node = newRoot;

    updateHeight(node->right);
    updateHeight(node);
}


/// copySubtree(node)
/// Creates a deep copy of subtree
/// @param node The root of the subtree being copied
/// @return an AVLTree copy of the subtree at node
AVLTreeNode* AVLTree::copySubtree(AVLTreeNode* node) {
    if (!node) return nullptr;
    AVLTreeNode* newNode = new AVLTreeNode(node->key, node->value);
    newNode->left = copySubtree(node->left);
    newNode->right = copySubtree(node->right);
    updateHeight(newNode);
    return newNode;
}

/// = other
/// Allows nodes to be equal to other nodes
/// @param other The node being assigned
/// @returns A copy of the node and its subtrees
AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this == &other) return *this;
    deleteSubtree(root);
    root = copySubtree(other.root);
    numNodes = other.numNodes;
    return *this;
}

/// contains(key)
/// Returns true or false if key exists or not
/// @param key the key pair
/// @returns true if the key is located, false otherwise
bool AVLTree::contains(const string& key) {
    return containsHelper(root, key);
}

/// containsHelper(node, key)
/// Searches for a node based on key
/// @param node the root node
/// @param key the key pair
/// @return true if the node exists, false otherwise
bool AVLTree::containsHelper(AVLTreeNode* node, const string& key) {
    if (!node) return false;
    if (key == node->key) return true;
    if (key < node->key) return containsHelper(node->left, key);
    return containsHelper(node->right, key);
}

/// get(key)
/// Get value if exists
/// @param key the key pair
/// @return the value assocaited with the key
optional<int> AVLTree::get(const string& key) {
    return getHelper(root, key);
}

/// getHelper(node, key, key)
/// Returns the node value if found
/// @param node the root node
/// @param key the key pair
/// @return the value associated with the key
optional<int> AVLTree::getHelper(AVLTreeNode* node, const string& key) const {
    if (!node) return nullopt;
    if (key == node->key) return node->value;
    if (key < node->key) return getHelper(node->left, key);
    return getHelper(node->right, key);
}


/// AVLTree[key]
/// Allows keys to be inserted using the [] syntax
/// @param key The key value being assigned
/// @retun the value associated with the key pair
int& AVLTree::operator[](const string& key) {
    return operatorHelper(root, key);
}

/// operatorHelper(node, key)
/// Updates value of key pair
/// @param node the root node
/// @param key the key pair being assigned
/// @return the updated key pair value
int& AVLTree::operatorHelper(AVLTreeNode* node, const string& key) {
    if (!node) {
        node = new AVLTreeNode(key, 0);
        numNodes++;
        return node->value;
    }
    if (key == node->key) return node->value;
    if (key < node->key) return operatorHelper(node->left, key);
    return operatorHelper(node->right, key);
}

/// findRange(lowKey, highKey)
/// Gets a list of keys in a range
/// @param lowKey The low end of the range
/// @param highKey The high end of the range
/// @return An array of keys in the range given
vector<int> AVLTree::findRange(string lowKey, string highKey) {
    vector<int> result;
    findRangeHelper(root, lowKey, highKey, result);
    return result;
}

/// findRangeHelper(node, lowkey, highkey, result)
/// creates an array of keys in a range
/// @param node the root node
/// @param lowKey the low end of the range
/// @param highKey the high end of the range
/// @param result an array of the keys within the range
void AVLTree::findRangeHelper(AVLTreeNode* node, const string& lowKey, const string& highKey, vector<int>& result) {
    if (!node) return;
    if (lowKey <= node->key && node->key <= highKey) {
        result.push_back(node->value);
    }
    if (lowKey < node->key) {
        findRangeHelper(node->left, lowKey, highKey, result);
    }
    if (highKey > node->key) {
        findRangeHelper(node->right, lowKey, highKey, result);
    }
}

/// keys()
/// gets an array of all keys in AVLTree
/// @return the key list of all nodes
vector<string> AVLTree::keys() {
    vector<string> result;
    collectKeys(root, result);
    return result;
}

/// collectKeys(node, result)
/// returns an array of keys starting at node
/// @param node the root node
/// @param result an array of keys
void AVLTree::collectKeys(AVLTreeNode* node, vector<string>& result) {
    if (!node) return;
    collectKeys(node->left, result);
    result.push_back(node->key);
    collectKeys(node->right, result);
}

/// size()
/// The number of nodes in the AVLTree
/// @return the size of the AVLTree
size_t AVLTree::size() const {
    return numNodes;
}

/// getHeight()
/// The height of the AVLTree
/// @return the height of the AVLTree
size_t AVLTree::getHeight() const {
    return root ? root->height : 0;
}

/// << tree
/// prints the AVLTree sideways
/// @param os the operating stream
/// @param tree The AVLTree being printed
/// @return the printed AVL tree
ostream& operator<<(ostream& os, const AVLTree& tree) {
    tree.printTree(os, tree.root, 0);
    return os;
}

/// printTree(os, node, depth)
/// prints the AVLTree sideways
/// @param os the opseating stream
/// @param node the root node
/// @param depth the height of the tree
void AVLTree::printTree(ostream& os, AVLTreeNode* node, int depth) const {
    if (!node) return;
    printTree(os, node->right, depth + 1);
    os << string(depth * 4, ' ') << "<" << node->key << ": " << node->value << ">" << endl;
    printTree(os, node->left, depth + 1);
}
