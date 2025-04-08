
#include "MultiSet.h"
#include <iostream>

using namespace std;
auto multiSet = new MultiSet;

    /**
    * Default constructor, initializes the set to be empty
    */
    MultiSet::MultiSet() : elements() {}

    /**
     * Destructor, would only be required if you had pointers inside MultiSet
     * Otherwise, your Container or other member variables should be responsible
     * for freeing the memory they are using
     */
    MultiSet::~MultiSet() {

    }

    /**
     * Copy constructor, this MultiSet should be a deep-copy of other
     *
     * @param other the MultiSet to be copied
     */
    MultiSet::MultiSet(const MultiSet& other) {

    }

    /**
     * Assignment operator, the memory this MultiSet stores should be released (if necessary)
     * then the elements from the other MultiSet copied into this MultiSet
     * @param other the MultiSet to be copied
     * @return
     */
    MultiSet& MultiSet::operator=(const MultiSet& other) {

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

    }

    /**
     * Remove the key from the multiset, with optional parameter for how
     * many duplicates to remove. If num > coumt(key), no keys are removed
     *
     * @param key key to be removed
     * @param num how many copies of key to remove
     * @return true if the key was removed, false if key is not in the set,
     * or there were not enough copies based on the number to remove
     */
    bool MultiSet::remove(const std::string& key, size_t num) {

    }

    /**
     * Remove the given number of arbitrary elements from the multiset. If
     * num > size(), nothing is removed
     *
     * @param num how many elements to remove
     * @return the elements that were removed
     */
    std::vector<std::string> MultiSet::remove(size_t num) {

    }

    /**
     * Determins if they key is in the multiset at least once
     *
     * @param key element to find
     * @return true if key is in multiset, otherwise false
     */
    bool MultiSet::contains(const std::string& key) const {

    }

    /**
     * Given an element, count determins how many times that element appears
     * in the multiset
     *
     * @param key element to find the count of
     * @return how many of the given element appear
     */
    size_t MultiSet::count(const std::string& key) const {

    }

    /**
     * Find all elements, including duplicates
     *
     * @return all elements with the vector size == size()
     */
    std::vector<std::string> MultiSet::keys() const {

    }

    /**
     * Find all the unique keys
     *
     * @return each key with vector size == uniqueSize()
     */
    std::vector<std::string> MultiSet::uniqueKeys() const {

    }

    /**
     * Determines if the multiset contains any elements
     *
     * @return true if there are any elements in the multiset,
     * othersize false
     */
    bool MultiSet::empty() {

    }

    /**
     * Determines the total number of elements
     *
     * @return how many elements in total are currently in the multiset
     */
    size_t MultiSet::size() const {

    }

    /**
     * Determines the number of unique keys
     *
     * @return how many unique keys are currently in the multiset
     */
    size_t MultiSet::uniqueSize() const {

    }

    /**
     * Removes all elements from the multiset
     */
    void MultiSet::clear() {

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
     * @param other the set to find the symmetric differnce with
     * @return set containing elements unique to both this and other
     */
    MultiSet MultiSet::symmetricDifferenceWith(const MultiSet& other) const {

    }

    /**
     * Outputs a representation of the multiset
     * One possible approach could be to print the key and its count
     * eg: {a:2, b:3, c:1}
     * or, print each element
     * eg. {a, a, b, b, b, c}
     *
     * @param os the ostream to output to
     * @param ms the MultiSet to output
     * @return reference to os
     */
    std::ostream& operator<< (std::ostream& os, const MultiSet& ms) {

    }

