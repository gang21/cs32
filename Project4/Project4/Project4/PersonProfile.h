//
//  PersonProfile.hpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h

#include <stdio.h>
#include <string>
#include <vector>
#include "RadixTree.h"
#include "provided.h"

using namespace std;

class PersonProfile {
public:
    PersonProfile(string name, string email);
    ~PersonProfile();
    string GetName() const;
    string GetEmail() const;
    void AddAttValPair(const AttValPair& attval);
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
private:
    string m_name;
    string m_email;
    RadixTree<AttValPair> m_tree;
    vector<AttValPair> * m_attVal;
};

#endif /* PersonProfile_h */
