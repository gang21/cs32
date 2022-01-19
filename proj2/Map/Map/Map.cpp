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
    
    //adding the object into the linked list
    if (head == nullptr) { //no objects in the list yet
        KeyValues * p;
        p = new KeyValues;
        p->key = key;
        p->value = value;
        p->next = nullptr;
        p->prev = nullptr;
        head = p;
        tail = p;
        numItems++;
    }
    
    else {  //objects exist in this list already (add to end)
        KeyValues * newItem;
        newItem = new KeyValues;
        newItem->key = key;
        newItem->value = value;
        tail->next = newItem;
        newItem->next = nullptr;
        newItem->prev = tail;
        tail = newItem;
        numItems++;
    }
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value) {
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    return false;
}

bool Map::erase(const KeyType& key) {
    if (head == nullptr)
        return false;
    else if (head->key == key) { //if it is the first one in the list
        KeyValues * destroy = head;
        head = head->next;
        delete destroy;
        numItems--;
        return true;
    }
    else if (tail->key == key) { //last one in the list
        KeyValues * destroy = tail;
        tail = tail->prev;
        delete destroy;
        numItems--;
        return true;
    }
    KeyValues * p;
    p = head;
    while (p != nullptr) { //in the middle of the list
        if (p->next != nullptr && p->key == key)
            break;
        p = p->next;
    }
    if (p != nullptr) {
        KeyValues *destroy = p->next;
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
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    return false;
}

void Map::swap(Map& other) {
    
}
