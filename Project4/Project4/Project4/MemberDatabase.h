//
//  MemberDatabase.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef MemberDatabase_h
#define MemberDatabase_h

#include <stdio.h>

class MemberDatabase {
public:
    MemberDatabase();
    ~MemberDatabase();
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
    
};

#endif /* MemberDatabase_h */
