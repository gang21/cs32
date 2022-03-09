//
//  PersonProfile.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "PersonProfile.h"
#include <vector>
#include <string>

PersonProfile::PersonProfile(std::string name, std::string email) {
    m_name = name;
    m_email = email;
}

PersonProfile::~PersonProfile() {
    
}

std::string PersonProfile::GetName() const {
    return m_name;
}

std::string PersonProfile::GetEmail() const {
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval) {
    set<string> * values = m_attVal->search(attval.attribute);
    if (values == nullptr) {
        m_pairVector.push_back(attval);
    }
    values->insert(attval.value);
}

int PersonProfile::GetNumAttValPairs() const {
    return m_pairVector.size();
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
    if (m_pairVector.empty()) {
        return false;
    }
    if (attribute_num < 0 || attribute_num >= m_pairVector.size()) {
        return false;
    }
    attval = m_pairVector[attribute_num];
    return true;
    
}
