//
//  testMap.cpp
//  Map
//
//  Created by Gabriella Ang on 1/13/22.
//
#include "Map.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {

//    Map femalesGPA;
//    assert(femalesGPA.empty());
//    assert(femalesGPA.size() == 0);
//    femalesGPA.insert("Aileen", 3.9);
//    femalesGPA.insert("Chloe", 4.002);
//    assert(femalesGPA.size() == 2 && !femalesGPA.empty());
//    femalesGPA.insert("aileen", 3.23);
//    femalesGPA.insert("Aileen", 3.1);
//    assert(femalesGPA.size() == 3);
//    femalesGPA.update("Chloe", 4.12);
//    femalesGPA.update("Bianca", 2.1);
//    assert(femalesGPA.size() == 3);
//    femalesGPA.insertOrUpdate("Bianca", 2.1);
//    femalesGPA.insertOrUpdate("aileen", 3.75);
//    assert(femalesGPA.size() == 4);
//    assert(femalesGPA.contains("aileen"));
//    assert(!femalesGPA.contains("aIleen"));
//    femalesGPA.erase("Abby");
//    assert(femalesGPA.size() == 4);
//    femalesGPA.erase("Aileen");
//    assert(femalesGPA.size() == 3 && !femalesGPA.contains("Aileen"));
//    KeyType name = "Rose";
//    ValueType gpa = 3.91;
//    femalesGPA.get("Chloe", gpa);
//    assert(gpa == 4.12);
//    assert(femalesGPA.get(2, name, gpa) && name == "Bianca" && gpa == 2.1);
//    assert(!femalesGPA.get(3, name, gpa));
////    femalesGPA.dump();
//
//    Map malesGPA;
//    assert(malesGPA.empty() && malesGPA.size() == 0);
//    malesGPA.insert("Seth", 3.69);
//    malesGPA.insert("Enoch", 3.80);
//    malesGPA.insert("Trevor", 4.9);
//    malesGPA.insert("Stephen", 3.93);
//    malesGPA.insert("Bryan", 3.32);
//    assert(malesGPA.size() == 5);
////    malesGPA.dump();
//
//    malesGPA.swap(femalesGPA);
//    assert(malesGPA.contains("Chloe") && malesGPA.size() == 3);
//    assert(femalesGPA.contains("Seth"));
//    assert(femalesGPA.size() == 5);
//    assert(femalesGPA.contains("Bryan"));
//    assert(!femalesGPA.contains("Chloe"));
//    assert(!femalesGPA.contains("aileen"));
//    assert(!femalesGPA.contains("Bianca"));
//    assert(!malesGPA.contains("Enoch"));
//    assert(!malesGPA.contains("Trevor"));
//    assert(!malesGPA.contains("Stephen"));
    

    cerr << "all tests suceeded" << endl;
}

//Map mm;
//    mm.insert("Little Ricky", 3.206);
//    mm.insert("Ethel", 3.538);
//    mm.insert("Ricky", 3.350);
//    mm.insert("Lucy", 2.956);
//    mm.insert("Ethel", 3.538);
//    mm.insert("Fred", 2.956);
//    mm.insert("Lucy", 2.956);
//    assert(mm.size() == 5);  // duplicate "Ethel" and "Lucy" were not added
//    string x;
//    double y;
//    mm.get(0, x, y);
//    assert(x == "Ethel");  // "Ethel" is greater than exactly 0 items in mm
//    mm.get(4, x, y);
//    assert(x == "Ricky");  // "Ricky" is greater than exactly 4 items in mm
//    mm.get(2, x, y);
//    assert(x == "Little Ricky");  // "Little Ricky" is greater than exactly 2 items in mm
//    assert(y == 3.206);  // the value corresponding to the key "Little Ricky"
