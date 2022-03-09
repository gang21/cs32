//
//  MemberDatabase.cpp
//  Project4
//
//  Created by Gabriella Ang on 3/3/22.
//

#include "MemberDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

MemberDatabase::MemberDatabase() {
    
}

MemberDatabase::~MemberDatabase() {
    
}

bool MemberDatabase::LoadDatabase(string filename) {
    ifstream infile;
    infile.open(filename);
    string line;
    string name;
    string email;
    int attCount = 0;
    int nameEmail = 0;
    //file not uploaded properly
    if (!infile)
        return false;
    //TODO: delete all the cout statements
    while (getline(infile, line)) {
        stringstream iss(line);
        if (nameEmail == 0 && attCount == 0) {
            iss >> name;
            nameEmail = 1;
            cout << name << " - " << nameEmail << endl;
        }
        if (nameEmail == 1 && attCount == 0) {
            email = line;
            nameEmail = 2;
            PersonProfile * person = new PersonProfile(name, email);
            m_members->insert(email, person);
            cout << email << " - " << nameEmail << endl;
        }
        if (nameEmail == 2 && attCount == 0) {
            int num;
            iss.get(num);
            attCount = num;
            nameEmail = 0;
            cout << num << " - " << nameEmail << endl;
        }
        if (attCount > 0) {
            cout << line << " - " << attCount << endl;
            string att;
            string val;
            char comma;
            iss >> att;
            iss.get(comma);
            iss >> val;
            AttValPair * pair = new AttValPair(att, val);
            m_pairs->insert(email, pair);
            attCount--;
        }
    }
    return true;
}

std::vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    vector<string> it;
    return it;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const {
    PersonProfile * it;
    return it;
}

int main() {
    MemberDatabase a;
    a.LoadDatabase("members.txt");
    
}

