#include "Map.h"
#include <string>

#include <iostream>

Map::Map() {
    KeyValues map[] = {};
    count = 0;
}

const bool Map::empty() {
    if (count == 0)
        return true;
    return false;
}

const int Map::size() {
    return count;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    if (count >= DEFAULT_MAX_ITEMS)
        return false;
    int i;
    for (i = 0; i < count; i++) {
        if (map[i].key == key) {
            return false;
        }
    }
    map[i].key = key;
    map[i].value = value;
    count++;
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value) {
    for (int i = 0; i < count; i++) {
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
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.
    int pos = -1;
    for (int i = 0; i < count; i++) {
        if (map[i].key == key) {
            pos = i;
        }
    }
    
    if (pos == -1)
        return false;
    
    for ( ; pos < count - 1; pos++) {
        map[pos] = map[pos+1];
    }
    count--;
    return true;
}
     
const bool Map::contains(const KeyType& key) {
      // Return true if key is equal to a key currently in the map, otherwise
      // false.
    for (int i = 0; i < count; i++) {
        if (map[i].key == key)
            return true;
    }
    return false;
}
     
bool Map::get(const KeyType& key, ValueType& value) {
      // If key is equal to a key currently in the map, set value to the
      // value in the map which that key maps to, and return true.  Otherwise,
      // make no change to the value parameter of this function and return
      // false.
    return false;
}
     
bool Map::get(int i, KeyType& key, ValueType& value) {
      // If 0 <= i < size(), copy into the key and value parameters the
      // key and value of the key/value pair in the map whose key is strictly
      // greater than exactly i keys in the map and return true.  Otherwise,
      // leave the key and value parameters unchanged and return false.
    return false;
}

void Map::swap(Map& other) {
      // Exchange the contents of this map with the other one.
}

int main() {
    Map mn;
    std::cout << mn.empty()<< std::endl;
    mn.insert("Lucy", 3.53);
    std::cout<< mn.empty() << std::endl;
    mn.insert("Dan", 2.7);
    mn.insert("Mark", 4.3);
    mn.insert("lucy", 3.8);
    mn.insert("Dan", 3.71);
    std::cout << "Size: " <<mn.size() << std::endl;
    mn.update("Mark", 3.8);
    mn.insertOrUpdate("Ben", 1.234);
    std::cout << "Size: " <<mn.size() << std::endl;
    mn.insert("lucy", 3.86);
    std::cout << "Size: " <<mn.size() << std::endl;
    std::cout << "Contains: " << mn.contains("Ben") << std::endl;
    std::cout << "Contains: " << mn.contains("ben") << std::endl;
    std::cout << "Erase: " << mn.erase("Mark") << std::endl;
    std::cout << "Size: " <<mn.size() << std::endl;
    std::cout << "Contains: " << mn.contains("Mark") << std::endl;
    std::cout << "Contains: " << mn.contains("Dan") << std::endl;
    std::cout << "Contains: " << mn.contains("Lucy") << std::endl;
    std::cout << "Erase: " << mn.erase("poppy") << std::endl;
    
    
}
