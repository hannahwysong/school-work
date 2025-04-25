
#include "MultiSet.h"
#include <iostream>

using namespace std;
MultiSet::Container tree;

    /**
    * Default constructor, initializes the set to be empty
    */
    MultiSet::MultiSet() : tree () {}

    /**
     * Destructor, would only be required if you had pointers inside MultiSet
     * Otherwise, your Container or other member variables should be responsible
     * for freeing the memory they are using
     */
    MultiSet::~MultiSet() = default;

    /**
     * Copy constructor, this MultiSet should be a deep-copy of other
     *
     * @param other the MultiSet to be copied
     */
    MultiSet::MultiSet(const MultiSet& other) {
        tree = other.tree;
    }

    /**
     * Assignment operator, the memory this MultiSet stores should be released (if necessary)
     * then the elements from the other MultiSet copied into this MultiSet
     * @param other the MultiSet to be copied
     * @return
     */
    MultiSet& MultiSet::operator=(const MultiSet& other) {
        if (this != &other) {
            tree = other.tree;
        }
        return *this;
    }

    /**
     * Insert the key into the multiset with an optional parameter
     * for how many of that key to insert
     *
     * @param key element to insert
     * @param num how many elements to insert, defaults to 1
     * @return true if element was insert, false if an error was encountered
     */
    bool MultiSet::insert(const std::string& key, size_t num) {
		auto current = tree.get(key);
        if (current.has_value()) {
            current.value() += static_cast<int>(num);
        }
        else {
            tree.insert(key, static_cast<int>(num));
        }
        return true;
    }

    /**
     * Remove the key from the multiset, with optional parameter for how
     * many duplicates to remove. If num > count(key), no keys are removed
     *
     * @param key key to be removed
     * @param num how many copies of key to remove
     * @return true if the key was removed, false if key is not in the set,
     * or there were not enough copies based on the number to remove
     */
    bool MultiSet::remove(const std::string& key, size_t num) {
        auto current = tree.get(key);
        if (!current.has_value()) {
            return false;
        }

        if (current.value() == num) {
            tree.remove(key);
        } else {
            int newVal = current.value() - static_cast<int>(num);
            tree.remove(key);
            tree.insert(key, newVal);
        }
        return true;
    }


    /**
     * Remove the given number of arbitrary elements from the multiset. If
     * num > size(), nothing is removed
     *
     * @param num how many elements to remove
     * @return the elements that were removed
     */
    std::vector<std::string> MultiSet::remove(size_t num) {
        std::vector<std::string> keys;
        std::vector<std::string> removed;
        if (tree.size() < num) {
            return keys;
        }
        keys = tree.keys();
        for (int i = 0; i < num; i++) {
            tree.remove(keys[i]);
            removed.push_back(keys[i]);
        }
        return removed;
        }

/**
     * Determines if they key is in the multiset at least once
     *
     * @param key element to find
     * @return true if key is in multiset, otherwise false
     */
    bool MultiSet::contains(const std::string& key) {
        return tree.contains(key);
    }

    /**
     * Given an element, count determines how many times that element appears
     * in the multiset
     *
     * @param key element to find the count of
     * @return how many of the given element appear
     */
    size_t MultiSet::count(const std::string& key) {
        auto current = tree.get(key);
        if (current.has_value()) {
            int count = current.value();
            return count;
        }
        return 0;
    }

    /**
     * Find all elements, including duplicates
     *
     * @return all elements with the vector size == size()
     */
    std::vector<std::string> MultiSet::keys() {
        std::vector<std::string> result;
        auto keys = tree.keys();

        for (const auto& k : keys) {
            size_t c = count(k);
            result.insert(result.end(), c, k);
        }
        return result;
    }

    /**
     * Find all the unique keys
     *
     * @return each key with vector size == uniqueSize()
     */
    std::vector<std::string> MultiSet::uniqueKeys() {
        std::vector<std::string> result;
        auto keys = tree.keys();

        for (const auto& k : keys) {
            if (count(k) == 1) {
                result.insert(result.end(), k);
            }
        }
        return result;
    }

    /**
     * Determines if the multiset contains any elements
     *
     * @return true if there are any elements in the multiset,
     * otherwise false
     */
    bool MultiSet::empty() const {
        if (tree.numNodes == 0) {
            return false;
        }
        return true;
    }

    /**
     * Determines the total number of elements
     *
     * @return how many elements in total are currently in the multiset
     */
    size_t MultiSet::size() const {
        return tree.size();
    }

    /**
     * Determines the number of unique keys
     *
     * @return how many unique keys are currently in the multiset
     */
    size_t MultiSet::uniqueSize() {
        std::vector<std::string> result;
        auto keys = tree.keys();
        int numKeys = 0;
        for (auto& k : keys) {
            if (count(k) == 1) {
                numKeys++;
            }
        }
        return numKeys;
    }

    /**
     * Removes all elements from the multiset
     */
    void MultiSet::clear() {
        tree = Container();
    }

    /////////////////
    // Set Operations
    /////////////////

    /**
     * Returns the union of two multiset, containing all elements of each set
     *
     * @param other the set to find the union with
     * @return the union of the current set with the other one
     */
    MultiSet MultiSet::unionWith(const MultiSet& other) const {

    }

    /**
     * Returns a multiset containing only elements common to both
     *
     * @param other the set to find the intersection with
     * @return multiset with elements only found in both this and the other
     */
    MultiSet MultiSet::intersectionWith(const MultiSet& other) const {

    }

    /**
     * Returns multiset containing all the elements in the current set that are
     * not in the other
     *
     * @param other the set to find the difference with
     * @return multiset with elements in the current set not found in the other
     */
    MultiSet MultiSet::differenceWith(const MultiSet& other) const {

    }

    /**
     * Returns a multiset containing elements that are either in this or the
     * other multiset, but not in both
     *
     * @param other the set to find the symmetric difference with
     * @return set containing elements unique to both this and other
     */
    MultiSet MultiSet::symmetricDifferenceWith(const MultiSet& other) const {

    }

    /**
     *
     *
     * @return
     */
    MultiSet MultiSet::cardinalityAnalytics() const {

    }

    /**
     * Outputs a representation of the multiset
     * One possible approach could be to print the key and its count
     * eg: {a:2, b:3, c:1}
     * or, print each element
     * e.g. {a, a, b, b, b, c}
     *
     * @param os the ostream to output to
     * @param ms the MultiSet to output
     * @return reference to os
     */
    std::ostream& operator<< (std::ostream& os, MultiSet& ms) {
        os << "{";
        std::vector<std::string> keys = ms.keys();
        for (size_t i = 0; i < keys.size(); ++i) {
            const auto& key = keys[i];
            os << key;
            if (!(i == keys.size() - 1)) {
                os << ",";
            }
        }
        os << "}";
        return os;
    }

