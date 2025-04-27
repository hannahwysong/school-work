
#include <iostream>
#include "MultiSet.h"

int main() {
    MultiSet ms1;
    MultiSet ms2;

    ms1.insert("A", 3);
    ms1.insert("B", 2);
    ms1.insert("C", 5);

    ms2.insert("B", 1);
    ms2.insert("D", 4);
    ms2.insert("A", 2);

    std::cout << "ms1: " << ms1 << std::endl;
    std::cout << "ms2: " << ms2 << std::endl;

    std::cout << "ms1 contains 'A': " << ms1.contains("A") << std::endl; // true
    std::cout << "ms1 contains 'D': " << ms1.contains("D") << std::endl;
    std::cout << "ms1 count of 'B': " << ms1.count("B") << std::endl; //
    std::cout << "ms2 count of 'C': " << ms2.count("C") << std::endl; //

    ms1.remove("A", 2);
    std::cout << "ms1 after removal: " << ms1 << std::endl;
    std::cout << "ms1 count of 'A': " << ms1.count("A") << std::endl;

    ms1.remove("B", 2);
    std::cout << "ms1 after removal: " << ms1 << std::endl;
    std::cout << "ms1 count of 'B': " << ms1.count("B") << std::endl;

    ms1.clear();
    ms2.clear();
    ms1.insert("A", 3);
    ms1.insert("B", 2);
    ms1.insert("C", 5);
    ms2.insert("B", 1);
    ms2.insert("D", 4);
    ms2.insert("A", 2);


    auto removed = ms1.remove(2);
    std::cout << "Removed elements from ms2: ";
    for (const auto& elem : removed) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    ms1.clear();
    ms2.clear();
    ms1.insert("A", 1);
    ms1.insert("B", 3);
    ms1.insert("C", 2);
    ms1.insert("D", 1);
    ms1.insert("G", 1);

    ms2.insert("A", 2);
    ms2.insert("C", 2);
    ms2.insert("D", 1);
    ms2.insert("E", 1);
    ms2.insert("F", 1);

    std::cout << "ms1: " << ms1 << std::endl;
    std::cout << "ms2: " << ms2 << std::endl;

    std::cout << "Union of ms1 and ms2: " << ms1.unionWith(ms2) <<  std::endl;

    std::cout << "Intersection of ms1 and ms2: " << ms1.intersectionWith(ms2) << std::endl;

    std::cout << "Difference between ms1 and ms2: " << ms1.differenceWith(ms2) << std::endl;

    std::cout << "Symmetric difference between ms1 and ms2: " << ms1.symmetricDifferenceWith(ms2) << std::endl;

    std::cout << "Cardinality Analytics (most to least frequent): " << ms1.cardinalityAnalytics() << std::endl;


    std::cout << "Unique keys in ms2: ";
    for (const auto& key : ms2.uniqueKeys()) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    ms1.clear();
    std::cout << "ms1 after clearing: " << ms1 << std::endl;

    return 0;
}

