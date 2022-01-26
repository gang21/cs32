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

int evaluate(string infix, const Map& values, string& postfix, int& result);
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
