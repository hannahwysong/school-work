

#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include <utility>
#include <vector>
#include <optional>
#include <ostream>

struct AVLTreeNode {
    std::string key;
    int value;
    size_t height;
    AVLTreeNode *left;
    AVLTreeNode *right;

    AVLTreeNode(std::string key, const int value, AVLTreeNode *left = nullptr, AVLTreeNode *right = nullptr) : key(std::move(key)), value(value), height(0), left(left), right(right) {}
};

class AVLTree {
  public:

      ~AVLTree();

      bool insert(const std::string& key, int value);

      bool remove(const std::string& key);

      bool contains(const std::string& key) const;

      std::optional<int> get(const std::string& key) const;

      int& operator[](const std::string& key);

      std::vector<int> findRange(std::string lowKey, std::string highKey) const;

      std::vector<std::string> keys() const;

      size_t size() const;

      size_t getHeight() const;

      void print() const;

      std::ostream& operator<<(std::ostream& os, const AVLTree & avlTree);


  private:
    AVLTreeNode *root;
    size_t height;
    size_t numNodes;

};
std::ostream& operator<<(std::ostream& os, const AVLTree& me);
std::ostream& operator<<(std::ostream& os,  std::pair<const AVLTree&,  size_t> height);

#endif
