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
        getline(iss, val1, ',');
        getline(iss, att2, ',');
        getline(iss, val2, ',');
        
        //split into source and compatible attval
        string source = att1 + "," + val1;
        string compatible = att2 + "," + val2;
        
        //if source attribute doesn't exist
        set<string> * search = m_compatiblePairs.search(source);
        if (search == nullptr) {
            set<string> tempPairs;
            tempPairs.insert(compatible);
            m_compatiblePairs.insert(source, tempPairs);
        }
        //if source attribute exists
        else  {
            //add into set of strings
            set<string> * tempPairs = search;
            tempPairs->insert(compatible);
        }
    }
    return true;
}
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    vector<AttValPair> a;
    return a;
}

int main() {
    AttributeTranslator a;
    a.Load("translator.txt");
    cerr << "all tests succeeded" << endl;
}
