//
//  MatchMaker.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "MatchMaker.h"
#include <set>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {
    m_database = mdb;
    m_translator = at;
}

MatchMaker::~MatchMaker() {
    
}

vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const {
    const PersonProfile* profile = m_database.GetMemberByEmail(email);
    vector<AttValPair> sourceAttributes;
    //get the attVal pairs given a specific email
    for (int i = 0; i < profile->GetNumAttValPairs(); i++) {
        AttValPair attval;
        profile->GetAttVal(i, attval);
        //store attvals in a vector
        sourceAttributes.push_back(attval);
    }
    //find attributes that are compatible with sourceAttributes
    vector<AttValPair> compatibles;
    for (int j = 0; j < sourceAttributes.size(); j++) {
        compatibles = m_translator.FindCompatibleAttValPairs(sourceAttributes[0]);
//        cout << compatibles.size() << endl;
    }
    for (int k = 0; k < compatibles.size(); k++) {
        cout << compatibles[k].attribute + "," << compatibles[k].value << endl;
    }
    vector<EmailCount> a;
    return a;
}

int main() {
    MemberDatabase a;
    a.LoadDatabase("members.txt");
    AttributeTranslator b;
    b.Load("translator.txt");
    MatchMaker c(a, b);
    c.IdentifyRankedMatches("AbFow2483@charter.net", 2);
}
