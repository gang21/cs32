//
//  testMapLL.cpp
//  Map
//
//  Created by Gabriella Ang on 1/19/22.
//

#include <stdio.h>
#include <iostream>
#include "Map.h"
#include <cassert>

using namespace std;

int main() {
    Map creatures;
    assert(creatures.empty() && creatures.size() == 0);
    assert(creatures.insert("Monkey", 12));
    assert(creatures.insert("Penguin", 1));
    assert(creatures.size() == 2 && !creatures.empty());
    assert(creatures.erase("Monkey"));
    assert(creatures.size() == 1);
    assert(!creatures.contains("Monkey"));
    assert(creatures.contains("Penguin"));
    assert(creatures.insert("", 11));
    assert(!creatures.insert("Penguin", 5));
    assert(creatures.size() == 2);
    assert(creatures.insert("Barnacle", 23));
    assert(creatures.insert("Crab", 3));
    assert(creatures.insert("Lamb", 10));
    assert(creatures.insert("Aardvark", 31));
    assert(creatures.insert("Beetle", 1));
    assert(creatures.insert("Manatee", 2));
    assert(!creatures.insert("Manatee", 2));
    assert(creatures.size() == 8);
    assert(creatures.update("Crab", 34));
    assert(!creatures.update("Vulture", 24));
    creatures.dump();
    
    cerr << "All tests suceeded" << endl;
}
