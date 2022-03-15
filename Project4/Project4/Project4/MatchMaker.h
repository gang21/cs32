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
#include "provided.h"
#include "MemberDatabase.h"
#include "AttributeTranslator.h"

using namespace std;

class MatchMaker {
public:
    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    ~MatchMaker();
    vector<EmailCount> IdentifyRankedMatches(string email, int threshold) const;
private:
    MemberDatabase m_database;
    AttributeTranslator m_translator;
};

#endif /* MatchMaker_hpp */
