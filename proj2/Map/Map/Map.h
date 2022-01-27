////
////  Map.h
////  Map
////
////  Created by Gabriella Ang on 1/18/22.
////
//
//#ifndef Map_h
//#define Map_h
//#include <string>
//
//using KeyType = std::string;
//using ValueType = double;
//
//class Map
//{
//  public:
//    Map();
//    Map(const Map &src); //copy constructor
//    Map& operator= (const Map &src);
//    ~Map();
//    bool empty() const;
//    int size() const;
//    bool insert(const KeyType& key, const ValueType& value);
//    bool update(const KeyType& key, const ValueType& value);
//    bool insertOrUpdate(const KeyType& key, const ValueType& value);
//    bool erase(const KeyType& key);
//    bool contains(const KeyType& key) const;
//    bool get(const KeyType& key, ValueType& value) const;
//    bool get(int i, KeyType& key, ValueType& value) const;
//    void swap(Map& other);
//    void dump() const;
//  private:
//    struct KeyValues {
//        KeyType key;
//        ValueType value;
//        KeyValues * next;
//        KeyValues * prev;
//    };
//    int numItems;
//    KeyValues * head;
//    KeyValues * tail;
//};
//
//bool merge(const Map& m1, const Map& m2, Map& result);
//void reassign(const Map& m, Map& result);
//
//#endif /* Map_h */
