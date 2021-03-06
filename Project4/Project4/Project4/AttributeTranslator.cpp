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
    //if file doesn't open properly
    if(!infile) {
        return false;
    }

    string line;
    while (!infile.eof()) {
        getline(infile, line);
        istringstream iss(line);
        string temp;
        vector<string> v;
        string att1;
        string val1;
        string att2;
        string val2;
        getline(iss, att1, ',');
        //checking for an emtpy line
        if (att1 == "")
            continue;
        getline(iss, val1, ',');
        getline(iss, att2, ',');
        getline(iss, val2, ',');
        
        //split into source and compatible attval
        string source = att1 + "," + val1;
        AttValPair compatible(att2, val2);
        
        //if source attribute doesn't exist
        vector<AttValPair> * search = m_compatiblePairs.search(source);
        if (search == nullptr) {
            vector<AttValPair> tempPairs;
            tempPairs.push_back(compatible);
            m_compatiblePairs.insert(source, tempPairs);        }
        //if source attribute exists
        else {
            //add into vector of strings
            search->push_back(compatible);
        }
    }
    return true;
}
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    string attval = source.attribute + "," + source.value;
    vector<AttValPair> * compatibles = m_compatiblePairs.search(attval);
    //no compatibles found
    if (compatibles == nullptr) {
        vector<AttValPair> empty = {};
        return empty;
    }
    return *compatibles;
}
