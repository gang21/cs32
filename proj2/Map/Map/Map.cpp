////
////  Map.cpp
////  Map
////
////  Created by Gabriella Ang on 1/18/22.
////
//
//#include "Map.h"
//#include <iostream>
//
//Map::Map() {
//    head = nullptr;
//    tail = nullptr;
//    numItems = 0;
//}
//
////copy constructor
//Map::Map(const Map &src) {
//    head = new KeyValues;
//    KeyValues * p = src.head;
//    head->key = p->key;
//    head->value = p->value;
//    head->prev = nullptr;
//    head->next = nullptr;
//    tail = head;
//
//    while (p != nullptr) {
//        insert(p->key, p->value);
//        p = p->next;
//    }
//    numItems = src.numItems;
//}
//
////assignment operator
//Map& Map::operator= (const Map &src) {
//    if (&src == this)
//        return *this;
//    Map temp = Map(src);
//    swap(temp);
//    numItems = src.size();
//    return *this;
//}
//
////destructor
//Map::~Map() {
//    KeyValues * p = nullptr;
//    p = head;
//    while (p != nullptr) {
//        KeyValues * n = p->next;
//        delete p;
//        p = n;
//    }
//}
//
//bool Map::empty() const {
//    return (numItems == 0);
//
//}
//
//int Map::size() const {
//    return numItems;
//}
//
//bool Map::insert(const KeyType& key, const ValueType& value) {
//    KeyValues * check = head;
//    while (check != nullptr) {  //checking for duplicates
//        if (check->key == key) {
//            return false;
//        }
//        check = check->next;
//    }
//
//  //adding the object into the linked list in order
//    //creating the object
//    KeyValues * newItem;
//    newItem = new KeyValues;
//    newItem->key = key;
//    newItem->value = value;
//    newItem->next = nullptr;
//    newItem->prev = nullptr;
//
//    if (head == nullptr) { //no items
//        newItem->next = nullptr;
//        newItem->prev = nullptr;
//        head = newItem;
//        tail = newItem;
//    }
//
//    else if (key <= head->key) { //add items to front
//        newItem->prev = nullptr;
//        head->prev = newItem;
//        newItem->next = head;
//        head = newItem;
//
//    }
//
//    else if (key >= tail->key){  //add items to end
//        tail->next = newItem;
//        newItem->next = nullptr;
//        newItem->prev = tail;
//        tail = newItem;
//    }
//    else { //add items in the middle
//        KeyValues * p = head;
//        KeyValues * q = tail;
//        while (p != nullptr && key > p->next->key) {
//            p = p->next;
//        }
//        while (q != nullptr && key < q->prev->key) {
//            q = q->prev;
//        }
//        p->next = newItem;
//        newItem->next = q;
//        q->prev = newItem;
//        newItem->prev = p;
//    }
//    numItems++;
//    return true;
//}
//
//bool Map::update(const KeyType& key, const ValueType& value) {
//    if (head == nullptr) //making sure there are objects in the list
//        return false;
//    KeyValues * p = head;
//    while (p != nullptr) {
//        if (p->key == key) {
//            p->value = value;
//            return true;
//        }
//        p = p->next;
//    }
//    return false;
//}
//
//bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
//    if (head == nullptr) {
//        insert(key, value);
//        return true;
//    }
//    bool insert = Map::insert(key, value);
//    if (insert)
//        return true;
//    else {
//        Map::update(key, value);
//        return true;
//    }
//    return false;
//}
//
//bool Map::erase(const KeyType& key) {
//    if (head == nullptr) //empty list
//        return false;
//
//    //only one item in the list
//    else if (numItems == 1) {
//        KeyValues * destroy = head;
//        head = nullptr;
//        tail = nullptr;
//        delete destroy;
//        numItems--;
//        return true;
//    }
//
//    //first one in the list
//    else if (head->key == key) {
//        KeyValues * destroy = head;
//        head = head->next;
//        delete destroy;
//        head->prev = nullptr;
//        numItems--;
//        return true;
//    }
//
//    //last one in the list
//    else if (tail->key == key) {
//        KeyValues * destroy = tail;
//        tail = tail->prev;
//        delete destroy;
//        tail->next = nullptr;
//        numItems--;
//        return true;
//    }
//
//    //in the middle of the list
//    KeyValues * p;
//    p = head;
//    while (p != nullptr) {
//        if (p->next != nullptr && p->next->key == key)
//            break;
//        p = p->next;
//    }
//    if (p != nullptr) {
//        KeyValues * destroy = p->next;
//        p->next = destroy->next;
//        destroy->next->prev = p;
//        delete destroy;
//        numItems--;
//        return true;
//    }
//    return false;
//}
//
//bool Map::contains(const KeyType& key) const {
//    KeyValues * p;
//    p = head;
//    while (p != nullptr) {
//        if (p->key == key)
//            return true;
//        p = p->next;
//    }
//    return false;
//}
//
//bool Map::get(const KeyType& key, ValueType& value) const {
//    KeyValues * p = head;
//    while (p != nullptr) {
//        if (p->key == key) {
//            value = p->value;
//            return true;
//        }
//        p = p->next;
//    }
//    return false;
//}
//
//bool Map::get(int i, KeyType& key, ValueType& value) const {
//    if (i >= 0 && i < numItems) {
//        KeyValues * p = head;
//        int a = 0;
//        while (a < i && p != nullptr) {
//            p = p->next;
//            a++;
//        }
//        key = p->key;
//        value = p->value;
//        return true;
//    }
//    return false;
//}
//
//void Map::swap(Map& other) {
//    KeyValues * tempHead = other.head;
//    KeyValues * tempTail = other.tail;
//
//    other.head = head;
//    other.tail = tail;
//
//    head = tempHead;
//    tail = tempTail;
//
//    //swapping numItems
//    int temp = other.numItems;
//    other.numItems = numItems;
//    numItems = temp;
//
//}
//
//void Map::dump() const {
//    KeyValues * p = head;
//    KeyValues * q = tail;
//
//    std::cerr << "Forward: " << std::endl;
//    while (p != nullptr) {
//        std::cerr << p->key << " - " << p->value << std::endl;
//
//        p = p->next;
//    }
//
//    std::cerr << std::endl << "Backwards: " << std::endl;
//    while (q != nullptr) {
//        std::cerr << q->key << " - " << q->value << std::endl;
//
//        q = q->prev;
//    }
//    std::cerr << std::endl;
//}
//
//bool merge(const Map& m1, const Map& m2, Map& result) {
//    //clearing result list
//    if (&m1 != &result && &m2 != &result) {
//        int size = result.size();
//        KeyType destroyKey;
//        ValueType destroyValue;
//        for (int i = 0; i < size; i++) {
//            result.get(0, destroyKey, destroyValue);
//            result.erase(destroyKey);
//        }
//    }
//
//    //merging two lists together
//    KeyType tempKey;
//    ValueType tempValue;
//    for (int i = 0; i < m1.size(); i++) {
//        m1.get(i, tempKey, tempValue);
//        result.insert(tempKey, tempValue);
//    }
//    bool noRepeats = true;
//    for (int j = 0; j < m2.size(); j++) {
//        m2.get(j, tempKey, tempValue);
//        result.insert(tempKey, tempValue);
//        for (int k = 0; k < m1.size(); k++) {
//            ValueType resultValue;
//            result.get(tempKey, resultValue);
//            if (tempValue != resultValue) {
//                result.erase(tempKey);
//                noRepeats = false;
//                break;
//            }
//        }
//    }
//    return noRepeats;
//}
//
//void reassign(const Map& m, Map& result) {
//    //clearing result list
//    if (&m != &result) {
//        int size = result.size();
//        KeyType destroyKey;
//        ValueType destroyValue;
//        for (int i = 0; i < size; i++) {
//            result.get(0, destroyKey, destroyValue);
//            result.erase(destroyKey);
//        }
//    }
//    KeyType tempKey;
//    ValueType tempValue;
//
//    if (m.size() == 0) //no items in m
//        return;
//
//    if (m.size() == 1) { //one item in m
//        m.get(0, tempKey, tempValue);
//        result.insertOrUpdate(tempKey, tempValue);
//        return;
//    }
//
//    //swapping values
//    KeyType offKey, lastKey;
//    ValueType firstValue;
//    m.get(m.size() - 1, lastKey, firstValue);
//    m.get(0, offKey, firstValue);
//    for (int i = 0; i < m.size() - 1; i++) {
//        m.get(i, tempKey, tempValue);
//        m.get(i+1, offKey, tempValue);
//        result.insertOrUpdate(tempKey, tempValue);
//    }
//    result.insertOrUpdate(lastKey, firstValue);
//    return;
//
//}
