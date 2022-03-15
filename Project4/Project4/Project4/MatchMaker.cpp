//
//  MatchMaker.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "MatchMaker.h"
#include "utilities.h"
#include <set>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {
    m_database = mdb;
    m_translator = at;
}

MatchMaker::~MatchMaker() {
    
}

vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const {
    const PersonProfile* profile = m_database.GetMemberByEmail(email);
    if (profile == nullptr) {
        vector<EmailCount> notfound = {};
        return notfound;
    }
    vector<AttValPair> sourceAttributes;
    //get the attVal pairs given a specific email
    for (int i = 0; i < profile->GetNumAttValPairs(); i++) {
        AttValPair attval;
        profile->GetAttVal(i, attval);
        //store attvals in a vector
        sourceAttributes.push_back(attval);
    }
    //find attributes that are compatible with sourceAttributes
    //TODO: make this work
    set<AttValPair> compatibles = {};
    for (int j = 0; j < sourceAttributes.size(); j++) {
        
        //TODO: check for duplicates
        vector<AttValPair> temp =  m_translator.FindCompatibleAttValPairs(sourceAttributes[j]);
        //add to compatibles
        copy(temp.begin(), temp.end(), inserter(compatibles, compatibles.begin()));
        
    }
    cout << compatibles.size() << endl;
    set<AttValPair>::iterator it;
    for (it = compatibles.begin(); it != compatibles.end(); it++) {
        cout << (*it).attribute << "," << (*it).value << endl;
    }
    //finding matching members
    set<string> matchMembers;
    for (it = compatibles.begin(); it != compatibles.end(); it++) {
        vector<string> match = m_database.FindMatchingMembers(*it);
        copy(match.begin(), match.end(), inserter(matchMembers, matchMembers.begin()));
    }
    cout << matchMembers.size() << endl;
    set<string>::iterator be;
    for (be = matchMembers.begin(); be != matchMembers.end(); be++) {
        cout << (*be) << endl;
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
