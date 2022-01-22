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
    Map m;
    m.insert("m", 1);
    assert(m.erase("m")); //erasing one item
    assert(m.size() == 0);
    assert(m.insert("M", 1));
    assert(m.size() == 1);
    
    //checking contains function
    assert(creatures.contains("Aardvark")); //checking contains
    assert(!creatures.contains("")); //checking false case
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
    
    //checking swap function
    Map cats;
    cats.insert("Siamese", 4);
    cats.insert("Sphinx", 3);
    cats.insert("Tabby", 2);
    cats.insert("Persian", 5);
    cats.swap(creatures);
    assert(cats.contains("Aardvark"));
    assert(cats.contains("Bear"));
    assert(cats.contains("Bee"));
    assert(cats.contains("Boar"));
    assert(cats.contains("Mammoth"));
    assert(cats.contains("Monkey"));
    assert(cats.contains("Narwal"));
    assert(cats.contains("Penguin"));
    assert(cats.size() == 8);
    assert(creatures.contains("Siamese"));
    assert(creatures.contains("Sphinx"));
    assert(creatures.contains("Tabby"));
    assert(creatures.contains("Persian"));
    assert(creatures.size() == 4);
    
    //checking copy constructor
    Map animals = creatures;
    assert(animals.size() == 4);
    assert(animals.contains("Siamese"));
    assert(animals.contains("Sphinx"));
    assert(animals.contains("Tabby"));
    assert(animals.contains("Persian"));
    assert(cats.size() == 8);

    //checking assignment operator
    cats = creatures;
    assert(cats.contains("Siamese"));
    assert(cats.contains("Sphinx"));
    assert(cats.contains("Tabby"));
    assert(cats.contains("Persian"));
    assert(cats.size() == 4);
//    creatures.dump();
    
    //checking merge function
    Map results;
    merge(creatures, cats, results); //checking for repeats
    assert(creatures.contains("Siamese"));
    assert(creatures.contains("Sphinx"));
    assert(creatures.contains("Tabby"));
    assert(creatures.contains("Persian"));
    assert(creatures.size() == 4);
    Map students = cats;
    assert(students.size() == 4);
    Map girls;
    girls.insert("Holly", 12);
    girls.insert("Belle", 12);
    girls.insert("Samantha", 11);
    girls.insert("Brianna", 13);
    girls.insert("Chloe", 12);
    Map boys;
    boys.insert("Bryan", 12);
    boys.insert("Emmett", 13);
    boys.insert("Joel", 13);
    boys.insert("Michael", 12);
    boys.insert("Baron", 12);
    boys.insert("Ian", 11);
    merge(girls, boys, students); //checking with existing values in result
//    students.dump();
    
    Map blues;
    Map reds;
    Map mix;
    blues.insert("cyan", 1);
    blues.insert("baby blue", 1);
    blues.insert("navy", 1);
    blues.insert("purple", 1);
    blues.insert("turquoise", 1);
    blues.insert("pastel", 1);
    blues.insert("blue", 1);
    reds.insert("red", 2);
    reds.insert("pink", 2);
    reds.insert("purple", 2);
    reds.insert("maroon", 2);
    merge(blues, reds, mix); //checking with duplicate keys, different values
//    mix.dump();
    
    //multiple duplicates, different values
    Map water;
    Map ocean;
    ocean.insert("water", 10000);
    ocean.insert("fish", 200);
    ocean.insert("algae", 1257);
    ocean.insert("sharks", 53);
    Map lake;
    lake.insert("water", 5000);
    lake.insert("plankton", 403);
    lake.insert("people", 12);
    lake.insert("algae", 32);
    assert(!merge(ocean, lake, water)); //returns false bc different values for duplicate keys
//    water.dump();
    //merging empty maps
    Map z;
    z.insert("stuff", 34);
    Map y;
    Map x;
    assert(merge(x,y,z));
    
    cerr << "All tests suceeded" << endl;
}
