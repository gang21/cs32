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
#include <map>

using namespace std;

template<typename ValueType>
class RadixTree {
public:
    RadixTree();
    ~RadixTree();
    void insert(std::string key, const ValueType& value);
    ValueType* search(std::string key) const;
private:
//    class Node {
//    public:
//        Node() {
//            prefix = nullptr;
//            suffix = nullptr;
//            count = 0;
//            isLeaf = true;
//            value = "";
//        }
//        ~Node() {
//            for (int i = 0; i < 26; i++) {
//                if (prefix[i] != nullptr) {
//                    Node * p = prefix[i];
//                    delete p;
//                }
//            }
//        }
//        bool addNode(Node * n, ValueType val) {
//            for (int i = 0; i < count; i++) {
//                if (prefix[i] == n)
//                    return false;
//            }
//            prefix[count] = n;
//            prefix[count]->setValue(val);
//            count++;
//            return true;
//        }
//        int getCount() {return count;}
//        void setValue(ValueType key) {value = key;}
//        ValueType getValue() {return value;}
//        void setLeaf(bool leaf) {isLeaf = leaf;}
//        ValueType getValAt(int i) {return prefix[i]->getValue();}
//    private:
//        Node * prefix[26];
//        vector<ValueType> suffix;
//        ValueType value;
//        int count;
//        bool isLeaf;
//    };
//    Node * m_head;

    
    map<std::string, ValueType> * m_map;
};

#endif /* RadixTree_h */

template<typename ValueType>
RadixTree<ValueType>::RadixTree() {
    //dummy node
//    m_head = new Node();
    m_map = nullptr;
}

template<typename ValueType>
RadixTree<ValueType>::~RadixTree() {
    typename map<string, ValueType>::iterator it;
    for (it = m_map->begin(); it != m_map->end(); it++) {
        m_map->erase(it);
    }
}

template<typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value) {
    m_map->insert_or_assign(key, value);
}

template<typename ValueType>
ValueType* RadixTree<ValueType>::search(std::string key) const {
    ValueType* valuecopyptr = new ValueType(m_map->find(key)->second);
    return valuecopyptr;
}
