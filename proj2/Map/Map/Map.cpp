//
//  Map.cpp
//  Map
//
//  Created by Gabriella Ang on 1/18/22.
//

#include "Map.h"
#include <iostream>

Map::Map() {
    head = nullptr;
    tail = nullptr;
    numItems = 0;
}

Map::Map(const Map &src) {
    
}

//Map& Map::operator= (const Map &src) {
//
//}

Map::~Map() {
    KeyValues * p = head;
    while (p != nullptr) {
        KeyValues * n = p->next;
        delete p;
        p = n;
    }
}

bool Map::empty() const {
    return (numItems == 0);
    
}

int Map::size() const {
    return numItems;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    KeyValues * check = head;
    while (check != nullptr) {  //checking for duplicates
        if (check->key == key) {
            return false;
        }
        check = check->next;
    }
    
  //adding the object into the linked list in order
    //creating the object
    KeyValues * newItem;
    newItem = new KeyValues;
    newItem->key = key;
    newItem->value = value;
    newItem->next = nullptr;
    newItem->prev = nullptr;
    
    if (head == nullptr) { //no items
        newItem->next = nullptr;
        newItem->prev = nullptr;
        head = newItem;
        tail = newItem;
    }
    
    else if (key <= head->key) { //add items to front
        newItem->prev = nullptr;
        head->prev = newItem;
        newItem->next = head;
        head = newItem;
        
    }
    
    else if (key >= tail->key){  //add items to end
        tail->next = newItem;
        newItem->next = nullptr;
        newItem->prev = tail;
        tail = newItem;
    }
    else { //add items in the middle
        KeyValues * p = head;
        KeyValues * q = tail;
        while (p != nullptr && key > p->next->key) {
            p = p->next;
        }
        while (q != nullptr && key < q->prev->key) {
            q = q->prev;
        }
        p->next = newItem;
        newItem->next = q;
        q->prev = newItem;
        newItem->prev = p;
    }
    numItems++;
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value) {
    if (head == nullptr) //making sure there are objects in the list
        return false;
    KeyValues * p = head;
    while (p != nullptr) {
        if (p->key == key) {
            p->value = value;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    if (head == nullptr) {
        insert(key, value);
        return true;
    }
    bool insert = Map::insert(key, value);
    if (insert)
        return true;
    else {
        Map::update(key, value);
        return true;
    }
    return false;
}

bool Map::erase(const KeyType& key) {
    if (head == nullptr)
        return false;
    else if (head->key == key) { //first one in the list
        KeyValues * destroy = head;
        head = head->next;
        delete destroy;
        head->prev = nullptr;
        numItems--;
        return true;
    }
    else if (tail->key == key) { //last one in the list
        KeyValues * destroy = tail;
        tail = tail->prev;
        delete destroy;
        tail->next = nullptr;
        numItems--;
        return true;
    }
    KeyValues * p;
    p = head;
    while (p != nullptr) { //in the middle of the list
        if (p->next != nullptr && p->next->key == key)
            break;
        p = p->next;
    }
    if (p != nullptr) {
        KeyValues * destroy = p->next;
        p->next = destroy->next;
        destroy->next->prev = p;
        delete destroy;
        numItems--;
        return true;
    }
    return false;
}

bool Map::contains(const KeyType& key) const {
    KeyValues * p;
    p = head;
    while (p != nullptr) {
        if (p->key == key)
            return true;
        p = p->next;
    }
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const {
    KeyValues * p = head;
    while (p != nullptr) {
        if (p->key == key) {
            value = p->value;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    if (i >= 0 && i < numItems) {
        KeyValues * p = head;
        int a = 0;
        while (a < i && p != nullptr) {
            p = p->next;
            a++;
        }
        key = p->key;
        value = p->value;
        return true;
    }
    return false;
}

void Map::swap(Map& other) {
    KeyValues * tempHead = other.head;
    KeyValues * tempTail = other.tail;
    
    other.head = head;
    other.tail = tail;
    
    head = tempHead;
    tail = tempTail;
    
}

void Map::dump() const {
    KeyValues * p = head;
    KeyValues * q = tail;
    
    std::cerr << "Forward: " << std::endl;
    while (p != nullptr) {
        std::cerr << p->key << " - " << p->value << std::endl;
        
        p = p->next;
    }
    
    std::cerr << std::endl << "Backwards: " << std::endl;
    while (q != nullptr) {
        std::cerr << q->key << " - " << q->value << std::endl;
        
        q = q->prev;
    }
    std::cerr << std::endl;
}
