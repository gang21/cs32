//
//  eval.cpp
//  HW2
//
//  Created by Gabriella Ang on 1/26/22.
//

#include <stdio.h>
#include "Map.h"
#include <string>
#include <iostream>
#include <cassert>
#include <cctype>
#include <stack>

using namespace std;

string clearSpaces(string infix);
bool isValidInfix(string infix);
bool isPrecedent(char current, char top);

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
    
    //checking if it's a valid string
    postfix = "";
    int returnVal = 0;
    string modInfix = clearSpaces(infix);
    if (!isValidInfix(modInfix)) {
        return 1;
    }

    //return 2 if syntatically valid but no corresponding key/value in map
    char key;
    int value;
    bool found = false;
    for (int i = 0; i < modInfix.size(); i++) {
        if (isalpha(modInfix[i]) != 0) {
            for (int j = 0; j < values.size(); j++) {
                values.get(j, key, value);
                if (modInfix[i] == key) {
                    found = true;
                }
            }
            if (!found)
                returnVal = 2;
        }
    }
    
    //return 3 if it attempts to divide by 0
    
    
    //return 0 if all things go right
    
    return returnVal;
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

bool isValidInfix(string infix) {
    string cleanedInfix = clearSpaces(infix);
    //return 1 if it's not valid infix expression
    if (cleanedInfix == "")
        return false;
    //checking for invalid chars
    int openParen = 0;
    int closeParen = 0;
    for (int i = 0; i < cleanedInfix.size(); i++) {
        //checking if it's an alphabet letter
        if (isalpha(cleanedInfix[i]) != 0) {
            if (isupper(cleanedInfix[i]) != 0) {
                return false;
            }
            if (i < cleanedInfix.size() - 1) {
                if (isalpha(cleanedInfix[i+1]) != 0) {
                    return false;
                }
            }
        }
        //checking if two letters are next to each other
//        if (i < cleanedInfix.size() - 1) {
//            if (isalpha(cleanedInfix[i+1]) != 0) {
//                return false;
//            }
//        }
        //checking if it's an operator
        else if (cleanedInfix[i] != '+'
                 && cleanedInfix[i] != '-'
                 && cleanedInfix[i] != '*'
                 && cleanedInfix[i] != '/'
                 && cleanedInfix[i] != '('
                 && cleanedInfix[i] != ')') {
            return false;
        }
        //checking for correct number of parentheses
        if (cleanedInfix[i] == '(') {
            openParen++;
            //checking for expression in parentheses
            if (i < cleanedInfix.size() - 1 && cleanedInfix[i+1] == ')')
                return false;
        }
        
        else if (cleanedInfix[i] ==')')
            closeParen++;
        if (closeParen > openParen)
            return false;
        //checking for no double operators in a row
        if (i < cleanedInfix.size() - 1) {
            if ((cleanedInfix[i] == '+'
                || cleanedInfix[i] == '-'
                || cleanedInfix[i] == '*'
                || cleanedInfix[i] == '/'
                 || cleanedInfix[i] == '(')
                && (cleanedInfix[i+1] == '+'
                || cleanedInfix[i+1] == '-'
                || cleanedInfix[i+1] == '*'
                || cleanedInfix[i+1] == '/'
                || cleanedInfix[i+1] == ')'))
                return false;
        }
        
        //checking for an operator after a ')' or before a '('
        if (cleanedInfix[i] == '(' && i != 0) {
            if(cleanedInfix[i-1] != '+'
               && cleanedInfix[i-1] != '-'
               && cleanedInfix[i-1] != '*'
               && cleanedInfix[i-1] != '/'
               && cleanedInfix[i-1] != '(') {
                return false;
            }
        }
            
        if (cleanedInfix[i] == ')' && i != cleanedInfix.size() - 1) {
            if(cleanedInfix[i+1] != '+'
                && cleanedInfix[i+1] != '-'
                && cleanedInfix[i+1] != '*'
                && cleanedInfix[i+1] != '/'
                && cleanedInfix[i+1] != ')') {
                return false;
            }
        }
    }
    //checking for the same number of open and close parentheses
    //if infix is valid
    if (openParen != closeParen) {
        return false;
    }
    return true;
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string postFix = "";
    for (int i = 0; i < infix.size(); i++) {
        if (isalpha(infix[i]) != 0) {
            postFix += infix[i];
        }
        else if (infix[i] == '(') {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')') {
            char pop = operators.top();
            while (pop != '(') {
                pop = operators.top();
                operators.pop();
                if (pop != '(') {
                    postFix += pop;
                }
            }
        }
        else {  //current item is an operator
            if (operators.empty()) {
                operators.push(infix[i]);
            }
            else if (operators.top() == '(') {
                operators.push(infix[i]);
            }
            else if (isPrecedent(infix[i], operators.top())) {
                operators.push(infix[i]);
            }
            else if (!isPrecedent(infix[i], operators.top())) {
                char pop = operators.top();
                operators.pop();
                postFix += pop;
                operators.push(infix[i]);
            }
        }
    }
    
    while(operators.size() != 0) {
        char pop = operators.top();
        operators.pop();
        postFix += pop;
    }
    return postFix;
}

bool isPrecedent(char current, char top) {
    if (current == '+' || current == '-') {
        if (top == '*' || top == '/') {
            return false;
        }
    }
    else if (current == '*' || current == '/') {
        if (top == '+' || top == '-') {
            return true;
        }
    }
    return false;
}

int main() {
    assert(clearSpaces("  a +   ( d   * d)") == "a+(d*d)");
    assert(isValidInfix("a+b"));
    assert(!isValidInfix(""));
    assert(!isValidInfix("y(*o)"));
    assert(isValidInfix("a+(b)"));
    assert(!isValidInfix("a+(b"));
    assert(!isValidInfix("a+)b"));
    assert(isValidInfix("(a+b) * (c/d)"));
    assert(!isValidInfix("E"));
    assert(!isValidInfix("((a+b)c) + d"));
    assert(isValidInfix("((a+b) * c) + d"));
    assert(!isValidInfix("ab"));
    
    Map m;
    string postfix;
    int result;
    m.insert('a', 2);
    m.insert('b', 3);
    m.insert('c', 4);
    assert(evaluate("a+  b", m, postfix, result) == 0);
    assert(evaluate("a+  (b", m, postfix, result) == 1);
    assert(evaluate("e+b", m, postfix, result) == 2);
    
    assert(infixToPostfix("a*b*c") == "ab*c*");
    assert(infixToPostfix("a+a*e") == "aae*+");
    assert(infixToPostfix("(z+e)*c") == "ze+c*");
    assert(infixToPostfix("(a-b)*(c/d)") == "ab-cd/*");
    assert(infixToPostfix("((a/z*d)+c)") == "az/d*c+");
    
    cerr << "all tests suceeded" << endl;
    
}
