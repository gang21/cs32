//
//  MatchMaker.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef MatchMaker_hpp
#define MatchMaker_hpp

#include <stdio.h>
#include <string>

using namespace std;

class MatchMaker {
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    vector<EmailCount> IdentifyRankedMatches(string email, int threshold) const;
    
    
};

#endif /* MatchMaker_hpp */
