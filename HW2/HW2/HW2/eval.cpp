//
//  eval.cpp
//  HW2
//
//  Created by Gabriella Ang on 1/26/22.
//

#include <stdio.h>
#include "Map.h"
#include <string>

using namespace std;

int evaluate(string infix, const Map& values, string& postfix, int& result) {
    // Evaluates an integer arithmetic expression
    //   If infix is a syntactically valid infix integer expression whose
    //   only operands are single lower case letters (whether or not they
    //   appear in the values map), then postfix is set to the postfix
    //   form of the expression; otherwise postfix may or may not be
    //   changed, result is unchanged, and the function returns 1.  If
    //   infix is syntactically valid but contains at least one lower
    //   case letter operand that does not appear in the values map, then
    //   result is unchanged and the function returns 2.  If infix is
    //   syntactically valid and all its lower case operand letters
    //   appear in the values map, then if evaluating the expression
    //   (using for each letter in the expression the value in the map
    //   that corresponds to it) attempts to divide by zero, then result
    //   is unchanged and the function returns 3; otherwise, result is
    //   set to the value of the expression and the function returns 0.
    
    
    //return 1 if is it is not just single lower case letters (not valid integer expression)
       
    //return 2 if syntatically valid but no corresponding key/value in map
    
    //return 3 if it attempts to divide by 0
    
    
    //return 0 if all things go right
    
    return -1;
}

string clearSpaces(string infix) {
    string cleanedString = "";
    if (infix.size() == 0) {
        cleanedString = "";
    }
    else if (infix.size() == 1 && infix != " ") {
        cleanedString = infix;
    }
    
    else {
        for (int i = 0; i < infix.size(); i++) {
            if (infix[i] == ' ')
                continue;
            cleanedString += infix[i];
        }
    }
    return cleanedString;
}

int main() {
    
}
