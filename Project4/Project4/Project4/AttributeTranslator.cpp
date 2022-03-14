//
//  AttributeTranslator.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "AttributeTranslator.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

AttributeTranslator::AttributeTranslator() {
    //constructor
}
AttributeTranslator::~AttributeTranslator() {
    //destructor
}
bool AttributeTranslator::Load(string filename) {
    ifstream infile;
    infile.open(filename);
    
    if(!infile) {
        return false;
    }

    string line;
    string att1;
    string val1;
    string att2;
    string val2;
    char comma;
    while (!infile.eof()) {
        getline(infile, line);
        string value;
        stringstream sstr(line);
//        m_compatiblePairs.insert(source, compatible);
    }
    return false;
}
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    vector<AttValPair> a;
    return a;
}

//int main() {
//    AttributeTranslator a;
//    a.Load("translator.txt");
//    cerr << "all tests succeeded" << endl;
//}
