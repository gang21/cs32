#include "Map.h"
#include <string>


Map::Map() {
    // Create an empty map (i.e., one with no key/value pairs)
    KeyValues map[] = {};
    count = 0;
}

const bool Map::empty() {
    //check if the map is empty
    if (count == 0)
        return true;
    return false;
}

const int Map::size() {
    return count;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
      // If key is not equal to any key currently in the map, and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that either the key is already in the map, or the map has a fixed
      // capacity and is full).
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
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value that it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // Otherwise, make no change to the map and return false.
    for (int i = 0; i < count; i++) {
        if (map[i].key == key) {
            map[i].value = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value that it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // If key is not equal to any key currently in the map and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that the key is not already in the map and the map has a fixed
      // capacity and is full).
    return false;
}

bool Map::erase(const KeyType& key) {
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.
    return false;
}
     
const bool Map::contains(const KeyType& key) {
      // Return true if key is equal to a key currently in the map, otherwise
      // false.
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
    
}
