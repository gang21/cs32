//
//  RadixTree.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "RadixTree.h"
#include <unordered_map>

using namespace std;

template<typename ValueType>
RadixTree<ValueType>::RadixTree() {
    
}

template<typename ValueType>
RadixTree<ValueType>::~RadixTree() {
    
}

template<typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value) {
    tree.insert(key, value);
}

template<typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const {
    return tree.find(key);
    
}
