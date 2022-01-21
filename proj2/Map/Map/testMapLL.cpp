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
    //checking empty and size functions
    assert(creatures.empty() && creatures.size() == 0); //checking that the list is empty empty
    assert(creatures.insert("Penguin", 12)); //checking insert
    assert(!creatures.empty());
    //checking insert function
    assert(creatures.insert("Monkey", 1)); //checking insert add to front
    assert(creatures.insert("Bee", 102)); //checking insert add to front
    assert(creatures.insert("", 95)); //checking empty string
    assert(creatures.insert("Aardvark", 2)); //checking insert add to front
    assert(creatures.insert("aardvark", 403)); //checking insert adding to end
    assert(creatures.insert("zebra", 403)); //checking insert adding to end
    assert(creatures.insert("Narwal", 37)); //checking insert adding to middle
    assert(creatures.insert("Mammoth", 98)); //checking insert adding to middle
    assert(creatures.insert("Bear", 7)); //checking insert adding to middle
    assert(!creatures.insert("zebra", 3)); //checking for duplicate cases
    //checking size function
    assert(creatures.size() == 10); //checking size function
    //checking update function
    assert(creatures.update("zebra", 402)); //checking for update function
    assert(!creatures.update("Zebra", 402)); //checking for noexistent key
    //checking insertOrUpdate function
    assert(creatures.insertOrUpdate("Mammoth", 32)); //checking for update
    assert(creatures.insertOrUpdate("Boar", 6)); //checking for insert
    //checking erase function
    assert(creatures.erase("")); //checking erase function in the front
    assert(!creatures.erase("bee")); //checking nonexistent key
    assert(creatures.erase("zebra")); //checking erase function at the end
    assert(creatures.erase("aardvark")); //checking erase function in the middle
    //checking contains function
    assert(creatures.contains("Aardvark")); //checking contains
    assert(!creatures.contains("")); //checking false case
    creatures.dump();
    //checking get function (two parameters)
    double result;
    creatures.get("Bear", result);
    assert(result == 7); //checking that it works
    creatures.get("Aardvark", result);
    assert(result == 2); //checking that it works
    assert(!creatures.get("zebra", result)); //checking for a nonexistent key
    //checking get function (three parameters)
    string animal;
    double count;
    assert(creatures.get(1, animal, count));
    assert(animal == "Bear" && count == 7); //checking that it works
    assert(creatures.get(7, animal, count));
    assert(animal == "Penguin" && count == 12); //checking that it works
    assert(!creatures.get(8, animal, count)); //checking out of bounds
    
    
    
    cerr << "All tests suceeded" << endl;
}
