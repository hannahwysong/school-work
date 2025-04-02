
#include "AVLTree.h"
#include <optional>
#include <iostream>

using namespace std;



bool insert(const string& key, int value) {
  return true;
}

bool remove(const string& key) {
  return true;
}

bool contains(const string& key) {
  return true;
}

optional<int> get(const string& key) {
  return nullopt;
}

int& operator[](const string& key) {
  int num = 0;
  int& numRef = num;
  return numRef;
}

vector<int> findRange(string lowKey, string highKey) {

}

vector<string> keys() {

}

size_t AVLTree::size() const {
  return numNodes;
}

size_t AVLTree::getHeight() const {
  return height;
}

void print() {

}

ostream& operator<<(ostream& os, const AVLTree & avlTree) {
  return os;
}

