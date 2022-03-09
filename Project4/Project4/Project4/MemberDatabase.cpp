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

    //file not uploaded properly
    if (!infile) {
        cout << "failureeeee" << endl;
        return false;
    }
        //looping through each member's data
        while (!(infile.eof())) {
            string line;
            string name;
            string email;
            
            //get name
            getline(infile, line);
            name = line;
            
            //get email
            getline(infile, line);
            email = line;
            
            //create a new member for the database
            PersonProfile * person = new PersonProfile(name, email);
            m_members->insert(email, person);
            
            //get the number of attVal pairs
            int n;
            cin >> n;
            cin.ignore(10000, '\n');
            //adding all attVal pairs
            for (int i = 0; i < n; i++) {
                getline(infile, line);
                istringstream iss(line);
                string att;
                string val;
                char comma;
                iss >> att;
                iss.get(comma);
                iss >> val;
                AttValPair pair(att, val);
                m_pairs->insert(email, pair);
            }
            //getting the empty line
            getline(infile, line);
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

