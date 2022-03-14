//
//  RadixTree.h
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef RadixTree_h
#define RadixTree_h

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

template<typename ValueType>
class RadixTree {
public:
    RadixTree();
    ~RadixTree();
    void insert(string key, const ValueType& value);
    ValueType* search(string key) const;
private:
    unordered_map<string, ValueType*> m_map;
};

#endif /* RadixTree_h */

template<typename ValueType>
RadixTree<ValueType>::RadixTree() {
    //dummy node
//    m_head = new Node();
    m_map = {};
}

template<typename ValueType>
RadixTree<ValueType>::~RadixTree() {
//    typename map<string, ValueType>::iterator it;
//    for (it = m_map.begin(); it != m_map.end(); it++) {
//        m_map.erase(it);
//    }
}

template<typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value) {
    ValueType * val = new ValueType(value);
    pair<string, ValueType*> pair(key, val);
    m_map.insert(pair);
}

template<typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const {
    if (m_map.size() == 0)
        return nullptr;
    if (m_map.find(key) != m_map.end()) {
        return m_map.find(key)->second;
    }
    return nullptr;
}
