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
    set<AttValPair>::iterator it;
    for (it = compatibles.begin(); it != compatibles.end(); it++) {
        vector<string> match = m_database.FindMatchingMembers(*it);
        for (int i = 0; i < match.size(); i++) {
            //skip original email
            if (match[i] == email)
                continue;
            map<string,int>::iterator find = emailCount.find(match[i]);
            //insert new EmailCount
            if (find == emailCount.end()) {
                emailCount.insert(pair<string,int>(match[i], 1));
            }
            //reassign existing EmailCount
            else {
                find->second++;
            }
        }
        
        copy(match.begin(), match.end(), inserter(matchMembers, matchMembers.begin()));
        matchMembers.erase(email);
    }
    
    map<string, int>::iterator bleh;
    for (bleh = emailCount.begin(); bleh != emailCount.end(); bleh++) {
        cout << (*bleh).first << "," << (*bleh).second << endl;
    }
    //PRINT STATEMENTS
    cout << matchMembers.size() << endl;
//    set<string>::iterator be;
//    for (be = matchMembers.begin(); be != matchMembers.end(); be++) {
//        cout << (*be) << endl;
//    }
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
    
    cerr << "all tests succeeded" << endl;
}
