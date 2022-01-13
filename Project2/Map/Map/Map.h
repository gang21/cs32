//
//  Map.h
//  Map
//
//  Created by Gabriella Ang on 1/12/22.
//

#ifndef Map_h
#define Map_h

#include <string>

using KeyType = std::string;
using ValueType = double;

const int DEFAULT_MAX_ITEMS = 260;

class Map
{
  public:
    Map();
    const bool empty();
    const int size();
    bool insert(const KeyType& key, const ValueType& value);
    bool update(const KeyType& key, const ValueType& value);
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
    bool erase(const KeyType& key);
    const bool contains(const KeyType& key);
    bool get(const KeyType& key, ValueType& value);
    bool get(int i, KeyType& key, ValueType& value);
    void swap(Map& other);

private:
    struct KeyValues {
        KeyType key;
        ValueType value;
    };
    int count;
    KeyValues map[DEFAULT_MAX_ITEMS];
};


#endif /* Map_h */
