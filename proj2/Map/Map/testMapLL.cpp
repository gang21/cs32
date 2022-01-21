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
    assert(creatures.empty() && creatures.size() == 0); //checking that the list is empty empty
    assert(creatures.insert("Penguin", 12)); //checking insert
    assert(creatures.insert("Monkey", 1)); //checking insert add to front
    assert(creatures.insert("Bee", 102)); //checking insert add to front
    assert(creatures.insert("Aardvark", 2)); //checking insert add to front
    assert(creatures.insert("aardvark", 403)); //checking insert adding to end
    assert(creatures.insert("zebra", 403)); //checking insert adding to end
    assert(creatures.insert("Narwal", 37)); //checking insert adding to middle
    assert(creatures.insert("Mammoth", 98)); //checking insert adding to middle
    assert(creatures.insert("Bear", 7)); //checking insert adding to middle
    
    creatures.dump();

    cerr << "All tests suceeded" << endl;
}
