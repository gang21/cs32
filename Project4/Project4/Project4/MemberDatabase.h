//
//  MemberDatabase.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h

#include <stdio.h>
#include <string>
#include "PersonProfile.h"

using namespace std;

class MemberDatabase {
public:
    MemberDatabase();
    ~MemberDatabase();
    bool LoadDatabase(string filename);
    std::vector<string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(string email) const;
private:
    
};

#endif /* MemberDatabase_h */
