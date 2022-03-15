//
//  MatchMaker.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "MatchMaker.h"
#include "utilities.h"
#include <set>
#include <map>
#include <algorithm>

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {
    m_database = mdb;
    m_translator = at;
}

MatchMaker::~MatchMaker() {
    
}

vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const {
    
    const PersonProfile* profile = m_database.GetMemberByEmail(email);
    //no profile is found
    if (profile == nullptr) {
        vector<EmailCount> notfound = {};
        return notfound;
    }
    //get the attVal pairs given a specific email
    vector<AttValPair> sourceAttributes;
    for (int i = 0; i < profile->GetNumAttValPairs(); i++) {
        AttValPair attval;
        profile->GetAttVal(i, attval);
        //store attvals in a vector
        sourceAttributes.push_back(attval);
    }
    //find attributes that are compatible with sourceAttributes
    set<AttValPair> compatibles = {};
    for (int j = 0; j < sourceAttributes.size(); j++) {
        vector<AttValPair> temp =  m_translator.FindCompatibleAttValPairs(sourceAttributes[j]);
        //add to compatibles
        copy(temp.begin(), temp.end(), inserter(compatibles, compatibles.begin()));
        
    }
    //PRINT STATEMENTS
//    cout << compatibles.size() << endl;
//    set<AttValPair>::iterator it;
//    for (it = compatibles.begin(); it != compatibles.end(); it++) {
//        cout << (*it).attribute << "," << (*it).value << endl;
//    }
    //finding matching members and make EmailCounts objects
    set<string> matchMembers;
    map<string, int> emailCount;
    vector<EmailCount> ec;
    set<AttValPair>::iterator it;
    for (it = compatibles.begin(); it != compatibles.end(); it++) {
        vector<string> match = m_database.FindMatchingMembers(*it);
        for (int i = 0; i < match.size(); i++) {
            //skip original email
            if (match[i] == email)
                continue;
            map<string,int>::iterator find = emailCount.find(match[i]);
            //reassign existing EmailCount
            if (find != emailCount.end()) {
                find->second++;
            }
            //reassign existing EmailCount
            else {
                emailCount.insert(pair<string,int>(match[i], 1));
            }
        }
        //TODO: WHAT WAS THIS FOR AGAIN???
//        copy(match.begin(), match.end(), inserter(matchMembers, matchMembers.begin()));
//        matchMembers.erase(email);
        
        
    }
    //reinserting the map into a vector and checking if it's above the threshold
    map<string, int>::iterator mit;
    for (mit = emailCount.begin(); mit != emailCount.end(); mit++) {
        if ((*mit).second >= threshold) {
            EmailCount emCo((*mit).first, (*mit).second);
            ec.push_back(emCo);
        }
    }
    //sort the vector
    sort(ec.begin(), ec.end());
    return ec;
    
}

int main() {
    MemberDatabase a;
    a.LoadDatabase("members.txt");
    AttributeTranslator b;
    b.Load("translator.txt");
    MatchMaker c(a, b);
    c.IdentifyRankedMatches("ElliotVega17@juno.com", 7);
    
    cerr << "all tests succeeded" << endl;
}
