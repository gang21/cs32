#include "newMap.h"
#include <iostream>
#include <cassert>
using namespace std;


newMap::newMap() {
    KeyValues map[] = {};
    index = 0;
}

bool newMap::empty() const {
    if (index == 0)
        return true;
    return false;
}

int newMap::size() const {
    return index;
}

bool newMap::insert(const KeyType& key, const ValueType& value) {
    if (index >= DEFAULT_MAX_ITEMS)
        return false;
    int i;
    for (i = 0; i < index; i++) {
        if (map[i].key == key) {
            return false;
        }
    }
    map[i].key = key;
    map[i].value = value;
    index++;
    return true;
}

bool newMap::update(const KeyType& key, const ValueType& value) {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            map[i].value = value;
            return true;
        }
    }
    return false;
}

bool newMap::insertOrUpdate(const KeyType& key, const ValueType& value) {
    bool insert = newMap::insert(key, value);
    if (insert)
        return true;
    else {
        bool update = newMap::update(key, value);
        if (update)
            return true;
    }
    return false;
}

bool newMap::erase(const KeyType& key) {
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.
    int pos = -1;
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1)
        return false;
    
    for ( ; pos < index - 1; pos++) {
        map[pos] = map[pos+1];
    }
    index--;
    return true;
}
     
bool newMap::contains(const KeyType& key) const {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key)
            return true;
    }
    return false;
}
     
bool newMap::get(const KeyType& key, ValueType& value) const {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            value = map[i].value;
            return true;
        }
    }
    return false;
}
     
bool newMap::get(int i, KeyType& key, ValueType& value) const {
    if (i >= 0 && i < this->size()) {
        key = map[i].key;
        value = map[i].value;
        return true;
    }
    return false;
}

void newMap::swap(newMap& other) {
    KeyValues tempMap[DEFAULT_MAX_ITEMS] = {};
    int otherCount = other.size();
    int indexCount = index;

    for (int i = 0; i <= otherCount; i++) {
        other.get(0, tempMap[i].key, tempMap[i].value);
        other.erase(tempMap[i].key);
    }

    for (int j = 0; j < indexCount; j++) {
        other.insert(map[0].key, map[0].value);
        this->erase(map[0].key);
    }
    for (int k = 0; k < otherCount; k++) {
        this->insert(tempMap[k].key, tempMap[k].value);
    }

    other.index = other.size();
    this->index = otherCount;

}

void newMap::dump() const {
    for (int i = 0; i < index; i++) {
        cerr << "Key: " << map[i].key << " Value: " << map[i].value << endl;
    }
}
