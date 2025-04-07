#include "AVLTree.h"
#include <optional>
#include <iostream>

using namespace std;
auto *avlTree = new AVLTree;

AVLTree::AVLTree() : root(nullptr), numNodes(0) {}

// Destructor
AVLTree::~AVLTree() {
    deleteSubtree(root);
}

AVLTree::AVLTree(const AVLTree& other) : root(nullptr), numNodes(0) {
    root = copySubtree(other.root);
    numNodes = other.numNodes;
}

// Recursively delete nodes
void AVLTree::deleteSubtree(AVLTreeNode* node) {
    if (!node) return;
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
}

// Public insert method
bool AVLTree::insert(const string& key, int value) {
    return insertNode(root, key, value);
}

// Recursive insert + balancing
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

bool AVLTree::remove(const string& key) {
    return removeNode(root, key);
}

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
        updateHeight(node);
        balance(node);
        return true;
    }
}

// Height update
void AVLTree::updateHeight(AVLTreeNode* node) {
    if (!node) return;
    int left = node->left ? node->left->height : 0;
    int right = node->right ? node->right->height : 0;
    node->height = 1 + max(left, right);
}

// Balance factor helper
int AVLTree::getBalanceFactor(AVLTreeNode* node) {
    if (!node) return 0;
    int left = node->left ? node->left->height : 0;
    int right = node->right ? node->right->height : 0;
    return left - right;
}

// Balance tree
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

// Rotations
void AVLTree::rotateLeft(AVLTreeNode*& node) {
    AVLTreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node = newRoot;

    updateHeight(node->left);
    updateHeight(node);
}

void AVLTree::rotateRight(AVLTreeNode*& node) {
    AVLTreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node = newRoot;

    updateHeight(node->right);
    updateHeight(node);
}

AVLTreeNode* AVLTree::copySubtree(AVLTreeNode* node) {
    if (!node) return nullptr;
    AVLTreeNode* newNode = new AVLTreeNode(node->key, node->value);
    newNode->left = copySubtree(node->left);
    newNode->right = copySubtree(node->right);
    updateHeight(newNode);
    return newNode;
}

AVLTree& AVLTree::operator=(const AVLTree& other) {
    if (this == &other) return *this;
    deleteSubtree(root);
    root = copySubtree(other.root);
    numNodes = other.numNodes;
    return *this;
}

// Simple recursive contains
bool AVLTree::contains(const string& key) {
    return containsHelper(root, key);
}

bool AVLTree::containsHelper(AVLTreeNode* node, const string& key) {
    if (!node) return false;
    if (key == node->key) return true;
    if (key < node->key) return containsHelper(node->left, key);
    return containsHelper(node->right, key);
}

// Get value if exists
optional<int> AVLTree::get(const string& key) {
    return getHelper(root, key);
}

optional<int> AVLTree::getHelper(AVLTreeNode* node, const string& key) const {
    if (!node) return nullopt;
    if (key == node->key) return node->value;
    if (key < node->key) return getHelper(node->left, key);
    return getHelper(node->right, key);
}


// operator[] (undefined behavior if not found)
int& AVLTree::operator[](const string& key) {
    return operatorHelper(root, key);
}

int& AVLTree::operatorHelper(AVLTreeNode* node, const string& key) {
    if (!node);
    if (key == node->key) return node->value;
    if (key < node->key) return operatorHelper(node->left, key);
    return operatorHelper(node->right, key);
}

// Range search
vector<int> AVLTree::findRange(string lowKey, string highKey) {
    vector<int> result;
    findRangeHelper(root, lowKey, highKey, result);
    return result;
}

void AVLTree::findRangeHelper(AVLTreeNode* node, const string& lowKey, const string& highKey, vector<int>& result) {
    if (!node) return;
    if (lowKey < node->key)
        findRangeHelper(node->left, lowKey, highKey, result);
    if (lowKey <= node->key && node->key <= highKey)
        result.push_back(node->value);
    if (highKey > node->key)
        findRangeHelper(node->right, lowKey, highKey, result);
}

// Collect all keys
vector<string> AVLTree::keys() {
    vector<string> result;
    collectKeys(root, result);
    return result;
}

void AVLTree::collectKeys(AVLTreeNode* node, vector<string>& result) {
    if (!node) return;
    collectKeys(node->left, result);
    result.push_back(node->key);
    collectKeys(node->right, result);
}

// Tree size
size_t AVLTree::size() const {
    return numNodes;
}

// Tree height (of root)
size_t AVLTree::getHeight() const {
    return root ? root->height : 0;
}

// Print tree sideways
ostream& operator<<(ostream& os, const AVLTree& tree) {
    tree.printTree(os, tree.root, 0);
    return os;
}

void AVLTree::printTree(ostream& os, AVLTreeNode* node, int depth) const {
    if (!node) return;
    printTree(os, node->right, depth + 1);
    os << string(depth * 4, ' ') << "<" << node->key << ": " << node->value << ">" << endl;
    printTree(os, node->left, depth + 1);
}