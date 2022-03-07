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

using namespace std;

template<typename ValueType>
class RadixTree {
public:
    RadixTree();
    ~RadixTree();
    void insert(string key, const ValueType& value);
    ValueType* search(string key) const;
private:
    class Node {
    public:
        Node() {
            prefix = nullptr;
            suffix = nullptr;
            count = 0;
            isLeaf = true;
            value = "";
        }
        ~Node() {
            for (int i = 0; i < 26; i++) {
                if (prefix[i] != nullptr) {
                    Node * p = prefix[i];
                    delete p;
                }
            }
        }
        bool addNode(Node * n, ValueType val) {
            for (int i = 0; i < count; i++) {
                if (prefix[i] == n)
                    return false;
            }
            prefix[count] = n;
            prefix[count]->setValue(val);
            count++;
            return true;
        }
        int getCount() {
            return count;
        }
        void setValue(ValueType key) {
            value = key;
        }
        void setLeaf(bool leaf) {
            isLeaf = leaf;
        }
    private:
        Node * prefix[26];
        vector<ValueType> suffix;
        ValueType value;
        int count;
        bool isLeaf;
    };
    Node * m_head;
};

#endif /* RadixTree_h */

template<typename ValueType>
RadixTree<ValueType>::RadixTree() {
    //dummy node
    m_head = new Node();
}

template<typename ValueType>
RadixTree<ValueType>::~RadixTree() {
    
}

template<typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value) {
    string prefix = key;
    //insert into empty tree
    if (m_head->getCount() == 0) {
        Node * n = new Node();
        n->setValue(key);
        addNode(n);
        m_head->setLeaf(false);
    }
    //node has no edges that have a prefix to the word
    for (int i = 0; i < )
    //The prefix completely matches the first part of the word, but there are still leftover parts to the word
    //The word matches the prefix but the prefix has leftover parts (the word is shorter than the prefix)
    //The prefix has a mismatch with the word
    //Prefix and the word fully match and both lengths are the same
    
}

template<typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const {
    
}
