//
//  MemberDatabase.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "MemberDatabase.h"

MemberDatabase::MemberDatabase() {
    
}

MemberDatabase::~MemberDatabase() {
    
}

bool MemberDatabase::LoadDatabase(string filename) {
    return false;
}

std::vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    vector<string> it;
    return it;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const {
    PersonProfile * it;
    return it;
}
