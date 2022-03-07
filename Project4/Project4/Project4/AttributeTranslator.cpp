//
//  AttributeTranslator.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "AttributeTranslator.h"
#include <vector>
#include <fstream>

AttributeTranslator::AttributeTranslator() {
    //constructor
}
AttributeTranslator::~AttributeTranslator() {
    //destructor
}
bool AttributeTranslator::Load(string filename) {
    ifstream file;
    int i;
    file.open(filename);
    
    if(!file)
        return false;
    
    while (file >> i) {
        
    }
}
vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
    
}
