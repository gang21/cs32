#include "Map.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;


Map::Map() {
    KeyValues map[] = {};
    index = 0;
}

const bool Map::empty() {
    if (index == 0)
        return true;
    return false;
}

const int Map::size() {
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
     
const bool Map::contains(const KeyType& key) {
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
        map[i].key = key;
        map[i].value = value;
        return true;
    }
    return false;
}

void Map::swap(Map& other) {
    KeyValues tempMap[DEFAULT_MAX_ITEMS] = {};
    int otherCount = other.size();
    
    for (int i = 0; i < other.size(); i++) {
        other.get(i, tempMap[i].key, tempMap[i].value);
        other.erase(tempMap[i].key);
    }
    for (int j = 0; j < this->size(); j++) {
        other.insert(map[j].key, map[j].value);
        this->erase(map[j].key);
    }
    for (int k = 0; k < otherCount; k++) {
        this->insert(tempMap[k].key, tempMap[k].value);
    }

}

int main() {
    Map mn;
    cout << mn.empty()<< endl;
    mn.insert("Lucy", 3.53);
    cout<< mn.empty() << endl;
    mn.insert("Dan", 2.7);
    mn.insert("Mark", 4.3);
    mn.insert("lucy", 3.3);
    mn.insert("Dan", 3.71);
    cout << "Size: " <<mn.size() << endl;
    mn.update("Mark", 3.8);
    mn.insertOrUpdate("Ben", 1.234);
    cout << "Size: " <<mn.size() << endl;
    mn.insert("lucy", 3.86);
    cout << "Size: " <<mn.size() << endl;
    cout << "Contains: " << mn.contains("Ben") << endl;
    cout << "Contains: " << mn.contains("ben") << endl;
    cout << "Erase: " << mn.erase("Mark") << endl;
    cout << "Size: " <<mn.size() << endl;
    cout << "Contains: " << mn.contains("Mark") << endl;
    cout << "Contains: " << mn.contains("Dan") << endl;
    cout << "Contains: " << mn.contains("Lucy") << endl;
    cout << "Erase: " << mn.erase("poppy") << endl;
    double gpa = 4.00;
    mn.get("lucy", gpa);
    cout << "New GPA: " << gpa << endl;
    KeyType name = "Rose";
    ValueType herGpa = 4.71;
    mn.get(1, name, herGpa);
    cout << name << " " << herGpa << endl;
    cout << "Contains: " << mn.contains("Rose") << endl;
    cout << "Contains: " << mn.contains("Dan") << endl;
    cout << "Size: " <<mn.size() << endl;
}
