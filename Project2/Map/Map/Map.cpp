#include "Map.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


Map::Map() {
    KeyValues map[] = {};
    index = 0;
}

bool Map::empty() const {
    if (index == 0)
        return true;
    return false;
}

int Map::size() const {
    return index;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
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
     
bool Map::contains(const KeyType& key) const {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key)
            return true;
    }
    return false;
}
     
bool Map::get(const KeyType& key, ValueType& value) {
    for (int i = 0; i < index; i++) {
        if (map[i].key == key) {
            value = map[i].value;
            return true;
        }
    }
    return false;
}
     
bool Map::get(int i, KeyType& key, ValueType& value) {
    if (i >= 0 && i < this->size()) {
        key = map[i].key;
        value = map[i].value;
        return true;
    }
    return false;
}

void Map::swap(Map& other) {
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

void Map::dump() const {
    for (int i = 0; i < index; i++) {
        cerr << "Key: " << map[i].key << " Value: " << map[i].value << endl;
    }
}

int main() {

    Map femalesGPA;
    assert(femalesGPA.empty());
    assert(femalesGPA.size() == 0);
    femalesGPA.insert("Aileen", 3.9);
    femalesGPA.insert("Chloe", 4.002);
    assert(femalesGPA.size() == 2 && !femalesGPA.empty());
    femalesGPA.insert("aileen", 3.23);
    femalesGPA.insert("Aileen", 3.1);
    assert(femalesGPA.size() == 3);
    femalesGPA.update("Chloe", 4.12);
    femalesGPA.update("Bianca", 2.1);
    assert(femalesGPA.size() == 3);
    femalesGPA.insertOrUpdate("Bianca", 2.1);
    femalesGPA.insertOrUpdate("aileen", 3.75);
    assert(femalesGPA.size() == 4);
    assert(femalesGPA.contains("aileen"));
    assert(!femalesGPA.contains("aIleen"));
    femalesGPA.erase("Abby");
    assert(femalesGPA.size() == 4);
    femalesGPA.erase("Aileen");
    assert(femalesGPA.size() == 3 && !femalesGPA.contains("Aileen"));
    KeyType name = "Rose";
    ValueType gpa = 3.91;
    femalesGPA.get("Chloe", gpa);
    assert(gpa == 4.12);
    assert(femalesGPA.get(2, name, gpa) && name == "Bianca" && gpa == 2.1);
    assert(!femalesGPA.get(3, name, gpa));
//    femalesGPA.dump();
    
    Map malesGPA;
    assert(malesGPA.empty() && malesGPA.size() == 0);
    malesGPA.insert("Seth", 3.69);
    malesGPA.insert("Enoch", 3.80);
    malesGPA.insert("Trevor", 4.9);
    malesGPA.insert("Stephen", 3.93);
    malesGPA.insert("Bryan", 3.32);
    assert(malesGPA.size() == 5);
//    malesGPA.dump();
    
    malesGPA.swap(femalesGPA);
    assert(malesGPA.contains("Chloe") && malesGPA.size() == 3);
    assert(femalesGPA.contains("Seth"));
    assert(femalesGPA.size() == 5);
    assert(femalesGPA.contains("Bryan"));
    assert(!femalesGPA.contains("Chloe"));
    assert(!femalesGPA.contains("aileen"));
    assert(!femalesGPA.contains("Bianca"));
    assert(!malesGPA.contains("Enoch"));
    assert(!malesGPA.contains("Trevor"));
    assert(!malesGPA.contains("Stephen"));
    
    cout << "passed all tests" << endl;
}
