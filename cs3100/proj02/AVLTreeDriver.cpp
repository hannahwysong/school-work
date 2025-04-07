#include <iostream>

using namespace std;
/*
Driver code for testing your AVL Tree
This is NOT the test code for grading,
instead for you to get an idea of how to test the tree
 */
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <ranges>
#include <vector>
using namespace std;


int main() {
    AVLTree tree;
    bool insertResult;
    insertResult = tree.insert("F", 'F');
    cout << insertResult << endl;
    insertResult = tree.insert("F", 'F'); // false, no duplicates allowed
    cout << insertResult << endl;
    insertResult = tree.insert("K", 'K');
    cout << insertResult << endl;
    insertResult = tree.insert("X", 'X');// single rotate left
    cout << insertResult << endl;

    insertResult = tree.insert("C", 'C');
    cout << insertResult << endl;
    insertResult = tree.insert("A", 'A'); // single rotate right
    cout << insertResult << endl;

    insertResult = tree.insert("D", 'D'); // double rotate right
    cout << insertResult << endl;

    insertResult = tree.insert("R", 'R'); // double rotate left
    cout << insertResult << endl;

    insertResult = tree.insert("V", 'V');
    cout << insertResult << endl;
    insertResult = tree.insert("A", 'A'); // false, duplicate
    cout << insertResult << endl;
    insertResult = tree.insert("Z", 'Z');
    cout << insertResult << endl;
    insertResult = tree.insert("M", 'M');
    cout << insertResult << endl;
    insertResult = tree.insert("D", 'D'); // false, duplicate
    cout << insertResult << endl;

    // size and getHeight
    cout << "tree size: " << tree.size() << endl; // 10
    cout << "tree height: " << tree.getHeight() << endl; // 3
    cout << endl;

    // contains
    bool containsResult;
    containsResult = tree.contains("A"); // true
    cout << containsResult << endl;
    containsResult = tree.contains("N"); // false
    cout << containsResult << endl;

    // get
    optional<int> getResult;

    getResult = tree.get("A"); // 65
    cout << "A: " << getResult.value() << endl;

    getResult = tree.get("C"); // 67
    cout << "C: " << getResult.value() << endl;

    getResult = tree.get("Q"); // getResult has no value
    cout << "Q: " << getResult.has_value() << endl; // print 0
    cout << endl;

     // findRange
    vector<int> rangeTest = tree.findRange("D", "W");
    // 70 68 82 75 77 86
    for (auto val: rangeTest) {
        cout << val << " ";
    }
    cout << endl << endl;

    // operator[]
    tree["A"] = 108;
    cout << tree << endl;
    cout << endl;

    // remove
    bool removeResult;
    removeResult= tree.remove("A"); // "A" is a leaf
    cout << removeResult << endl;
    //cout << tree << endl;

    removeResult = tree.remove("C"); // "C" has one child, single rotate left
    cout << removeResult << endl;
    //cout << tree << endl;

    removeResult = tree.remove("F"); // "F" has two children
    cout << removeResult << endl;
    //cout << tree << endl;

    removeResult = tree.remove("V");
    cout << removeResult << endl;
    removeResult = tree.remove("X");
    cout << removeResult << endl;
    removeResult = tree.remove("Z"); // double rotate right
    cout << removeResult << endl;
    //cout << tree << endl;

    return 0;
}
