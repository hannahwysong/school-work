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
    AVLTreeNode *root;
    size_t height;
    size_t numNodes;

    AVLTree();

    ~AVLTree();

    AVLTree(const AVLTree &other);

    bool insert(const std::string& key, int value);

    bool insertNode(AVLTreeNode *&node, const std::string &key, int value);

    void updateHeight(AVLTreeNode *node);

    bool remove(const std::string& key);

    bool removeNode(AVLTreeNode *&node, const std::string &key);

    int getBalanceFactor(AVLTreeNode *node);

    void balance(AVLTreeNode *&node);

    void rotateLeft(AVLTreeNode *&node);

    void rotateRight(AVLTreeNode *&node);

    AVLTreeNode *copySubtree(AVLTreeNode *node);

    AVLTree &operator=(const AVLTree &other);

    bool contains(const std::string &key);

    bool containsHelper(AVLTreeNode *node, const std::string &key);

    std::optional<int> get(const std::string &key);

    std::optional<int> getHelper(AVLTreeNode *node, const std::string &key) const;

    int& operator[](const std::string& key);

    int &operatorHelper(AVLTreeNode *node, const std::string &key);

    std::vector<int> findRange(std::string lowKey, std::string highKey);

    void findRangeHelper(AVLTreeNode *node, const std::string &lowKey, const std::string &highKey,
                         std::vector<int> &result);

    std::vector<std::string> keys();

    std::vector<int> findRange(std::string lowKey, std::string highKey) const;

    std::vector<std::string> keys() const;

    void deleteSubtree(AVLTreeNode* Node);

    void collectKeys(AVLTreeNode *node, std::vector<std::string> &result);

    size_t size() const;

    size_t getHeight() const;

    void printTree(std::ostream &os, AVLTreeNode *node, int depth) const;

    void print() const;

};
std::ostream& operator<<(std::ostream& os, const AVLTree& AVLTree);
std::ostream& operator<<(std::ostream& os,  std::pair<const AVLTree&,  size_t> height);

#endif
