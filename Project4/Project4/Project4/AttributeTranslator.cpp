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
    
    string line;
    string att1;
    string val1;
    string att2;
    string val2;
    char comma;
    while (getline(infile, line)) {
        istringstream iss(line);
        iss >> att1;
        iss.get(comma);
        iss >> val1;
        iss.get(comma);
        iss >> att2;
        iss.get(comma);
        iss >> val2;
    }
    
    
    
    
    
    
    
}
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    
}
