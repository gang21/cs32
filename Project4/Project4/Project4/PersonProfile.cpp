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
    
}

int PersonProfile::GetNumAttValPairs() const {
    return m_pairVector.size();
}
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
    //TODO: fix this for radixTree
    return false;

}
