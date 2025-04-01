#include <string>
#ifndef AVLTREE_H
#define AVLTREE_H

struct AVLTreeNode; {
    std::string key;
    int value;
    size_t height;
    AVLTreeNode *left;
    AVLTreeNode *right

    AVLTreeNode(AVLTreeNode *left = nullptr, AVLTreeNode *right = nullptr) : value(value), key(key), height(0), left(left), right(right) {}
}

class AVLTree; {
  public:

      ~AVLTree()
      AVLTree(const AVLTree& other);
      bool AVLTree::insert(const string& key, int value);
      bool AVLTree::remove(const string& key);
      bool AVLTree::contains(const string& key) const;
      optional<int> AVLTree::get(const string& key) const;
      int& AVLTree::operator[](const string& key);
      vector<int> AVLTree::findRange(string lowKey, string highKey) const;
      vector<string> AVLTree::keys() const;
      size_t AVLTree::size() const;
      size_t AVLTree::getHeight() const;
      ostream& operator<<(ostream& os, const AVLTree & avlTree);

  private:
    AVLTreeNode *root;

}
std::ostream& operator<<(std::ostream& os, const AVLTree& me);
std::ostream& operator<<(std::ostream& os,  std::pair<const AVLTree&,  size_t> height);

#endif
