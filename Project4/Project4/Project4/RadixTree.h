//
//  RadixTree.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef RadixTree_h
#define RadixTree_h

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

template<typename ValueType>
class RadixTree {
public:
    RadixTree();
    ~RadixTree();
    void insert(string key, const ValueType& value);
    ValueType* search(string key) const;
private:
    unordered_map<string, ValueType*> tree;
};

#endif /* RadixTree_hpp */
