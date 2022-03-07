//
//  AttributeTranslator.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h

#include <stdio.h>
#include <string>
#include "provided.h"

using namespace std;

class AttributeTranslator {
public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(string filename);
    vector<AttValPair> FindCompatibleAttValPairs(const AttValPair& source) const;
private:
    vector<AttValPair> * m_translation;
};

#endif /* AttributeTranslator_h */
