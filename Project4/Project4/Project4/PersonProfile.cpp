//
//  PersonProfile.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "PersonProfile.h"
#include <vector>

PersonProfile::PersonProfile(string name, string email) {
    m_name = name;
    m_email = email;
}

PersonProfile::~PersonProfile() {
    
}

string PersonProfile::GetName() const {
    return m_name;
}

string PersonProfile::GetEmail() const {
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval) {
    //TODO: check for repeats
    
    for (int i = 0; i < m_attVal->size(); i++) {
        if (m_attVal[i] == attval)
            return;
    }
    m_attVal->push_back(attval);
}

int PersonProfile::GetNumAttValPairs() const {
    return m_attVal->size();
}
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
    //TODO: fix this for radixTree
    if (attribute_num < 0 || attribute_num >= m_attVal->size())
        return false;
    attval = m_attVal[attribute_num];
    return true;
}
