//
//  testNewMap.cpp
//  Map
//
//  Created by Gabriella Ang on 1/14/22.
//

#include "newMap.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {

    Map dogBreeds;
    KeyType breed[6] = {"yorkie", "golden doodle", "husky", "border collie", "pug", "maltese"};
    ValueType rating[6] = {4.2, 10, 6.6, 7.9, 4.3, 8.1};
    for (int i = 0; i < 6; i++) {
        dogBreeds.insert(breed[i], rating[i]);
    }
    assert(dogBreeds.size() == 6);
    Map a(1000);
    Map b(5);
    Map c;
    ValueType v = 13;
    for (int n = 0; n < 5; n++)
        assert(b.insert(breed[n], v));
    assert(!b.insert(breed[5], v));
    a.swap(b);
    assert(!a.insert(breed[5], v)  &&  b.insert(breed[5], v));

    Map myFavoriteColors(5);
    assert(myFavoriteColors.size() == 0 && myFavoriteColors.empty());
    myFavoriteColors.insert("light pink", 9.8);
    myFavoriteColors.insert("mauve", 6.2);
    assert(myFavoriteColors.size() == 2 && !myFavoriteColors.empty());
    assert(myFavoriteColors.contains("light pink"));
    assert(!myFavoriteColors.contains("Light pink"));
    assert(myFavoriteColors.contains("mauve"));
    myFavoriteColors.insert("cyan", 7.3);
    assert(!myFavoriteColors.insert("mauve", 5.2));
    myFavoriteColors.insert("lavender", 4.2);
    myFavoriteColors.insert("sunshine yellow", 7.4);
    assert(myFavoriteColors.size() == 5);
    assert(!myFavoriteColors.insert("white", 8.1));
    assert(myFavoriteColors.size() == 5);
    assert(myFavoriteColors.update("light pink", 10));
    assert(!myFavoriteColors.update("blue", 10));

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

    Map malesGPA;
    assert(malesGPA.empty() && malesGPA.size() == 0);
    malesGPA.insert("Seth", 3.69);
    malesGPA.insert("Enoch", 3.80);
    malesGPA.insert("Trevor", 4.9);
    malesGPA.insert("Stephen", 3.93);
    malesGPA.insert("Bryan", 3.32);
    assert(malesGPA.size() == 5);

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

cerr << "all tests suceeded" << endl;
}






