//
//  AttributeTranslator.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <stdio.h>
#include "provided.h"
#include "PersonProfile.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <set>
//#include "RadixTree.h"

using namespace std;

class AttributeTranslator {
public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(string filename);
    vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
    RadixTree<set<string>> m_compatiblePairs;
};

#endif /* AttributeTranslator_h */
