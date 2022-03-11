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
#include <vector>
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
    RadixTree<PersonProfile*> m_members; //email addresses - personProfile
    RadixTree<vector<string>> m_pairs; //attValPairs - string
    
    
    
};

#endif /* MemberDatabase_h */
