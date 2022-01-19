#include "newMap.h"
#include <iostream>
using namespace std;


Map::Map() {
    map = new KeyValues[DEFAULT_MAX_ITEMS];
    index = 0;
    maxValue = DEFAULT_MAX_ITEMS;
}

Map::Map(int max) {
    if (max < 0)
        max = 0;
    map = new KeyValues[max];
    index = 0;
    maxValue = max;
}

Map::Map (const Map& old) {
    index = old.index;
    maxValue = old.maxValue;
    map = new KeyValues[maxValue];
    for (int i = 0; i < maxValue; i++) {
        map[i] = old.map[i];
    }
}

Map &Map::operator=(const Map &src) {
    if (&src == this)
        return *this;
    delete [] map;
    maxValue = src.maxValue;
    index = src.index;
    map = new KeyValues[maxValue];
    for (int i = 0; i < src.maxValue; i++) {
        map[i] = src.map[i];
    }
    return *this;
}

Map::~Map() {
    delete [] map;
}

bool Map::empty() const {
    return (index == 0);
}

int Map::size() const {
    return index;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    if (index >= maxValue)
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

bool Map::update(const KeyType& key, const ValueType& value) {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            map[i].value = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    bool insert = Map::insert(key, value);
    if (insert)
        return true;
    else {
        bool update = Map::update(key, value);
        if (update)
            return true;
    }
    return false;
}

bool Map::erase(const KeyType& key) {
    
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
     
bool Map::contains(const KeyType& key) const {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key)
            return true;
    }
    return false;
}
     
bool Map::get(const KeyType& key, ValueType& value) const {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            value = map[i].value;
            return true;
        }
    }
    return false;
}
     
bool Map::get(int i, KeyType& key, ValueType& value) const {
    if (i >= 0 && i < this->size()) {
        key = map[i].key;
        value = map[i].value;
        return true;
    }
    return false;
}

void Map::swap(Map& other) {
    int otherSize = other.size();
    int thisSize = size();
    int otherMax = other.maxValue;
    int thisMax = maxValue;
    
    KeyValues * tempOther = other.map;
    other.map = map;
    map = tempOther;
    
    other.index = thisSize;
    index = otherSize;
    other.maxValue = thisMax;
    maxValue = otherMax;
}

void Map::dump() const {
    for (int i = 0; i < index; i++) {
        cerr << map[i].key << " - " << map[i].value << endl;
    }
}
