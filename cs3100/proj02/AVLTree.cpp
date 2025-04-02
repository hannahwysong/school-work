
#include "AVLTree.h"
#include <optional>
#include <iostream>

using namespace std;
auto *avlTree = new AVLTree;

AVLTree::AVLTree() : root(nullptr), height(0), numNodes(0) {}

AVLTree::~AVLTree() {
  deleteSubtree(root);
}

void AVLTree::deleteSubtree(AVLTreeNode *Node) {
  if (Node == nullptr) {
    return;
  }
  deleteSubtree(Node->left);
  deleteSubtree(Node->right);
  delete Node;
}

bool AVLTree::insert(const string& key, int value) {
  auto *newNode = new AVLTreeNode(key, value);
  if (avlTree->root == nullptr) {
    avlTree->root = newNode;
    return true;
  }
  return false;
}

bool AVLTree::remove(const string& key) {
  return true;
}

bool AVLTree::contains(const string& key) {
  return true;
}

optional<int> AVLTree::get(const string& key) {
  return nullopt;
}

int& AVLTree::operator[](const string& key) const {
  int num = 0;
  int& numRef = num;
  return numRef;
}

vector<int> findRange(string lowKey, string highKey) {
  return vector<int>();
}

vector<string> keys() {
  return vector<string>();
}

size_t AVLTree::size() const {
  return numNodes;
}

size_t AVLTree::getHeight() const {
  return height;
}

void print() {

}

ostream& operator<<(ostream& os, const AVLTree &AVLTree) {
  return os;
}

