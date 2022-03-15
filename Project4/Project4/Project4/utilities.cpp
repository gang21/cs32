//
//  utilities.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/15/22.
//

#include <stdio.h>
#include "utilities.h"
#include <iostream>
using namespace std;

bool operator<(const AttValPair& pair1, const AttValPair& pair2) {
    if (pair1.attribute < pair2.attribute)
        return true;
    else if (pair1.attribute == pair2.attribute && pair1.value < pair2.value)
        return true;
    return false;
}

bool operator<(const EmailCount& c1, const EmailCount& c2) {
    if (c1.count > c2.count)
        return true;
    else if (c1.count == c2.count && c1.email < c2.email)
        return true;
    return false;
}
