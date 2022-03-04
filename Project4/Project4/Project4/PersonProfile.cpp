//
//  PersonProfile.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "PersonProfile.h"

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
    m_profile.insert(attribute, value);
}

int PersonProfile::GetNumAttValPairs() const {
    
}
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
    
}
