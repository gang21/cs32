//
//  newMap.h
//  newMap
//
//  Created by Gabriella Ang on 1/14/22.
//

#ifndef newMap_h
#define newMap_h

#include <string>
#include <stdio.h>
#include "newMap.h"

using KeyType = std::string;
using ValueType = double;

const int DEFAULT_MAX_ITEMS = 260;

class newMap
{
  public:
    newMap();
    bool empty() const;
    int size() const;
    bool insert(const KeyType& key, const ValueType& value);
    bool update(const KeyType& key, const ValueType& value);
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
    bool erase(const KeyType& key);
    bool contains(const KeyType& key) const;
    bool get(const KeyType& key, ValueType& value) const;
    bool get(int i, KeyType& key, ValueType& value) const;
    void swap(newMap& other);
    void dump() const;

private:
    struct KeyValues {
        KeyType key;
        ValueType value;
    };
    int index;
    KeyValues map[DEFAULT_MAX_ITEMS];
};


#endif /* newMap_h */
