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
        //two members with the same email
        if (m_members.search(email) != nullptr) {
            return false;
        }
        //create a new member for the database
        PersonProfile person(name, email);
//        m_members.insert(email, *person);
            
        //get the number of attVal pairs
        getline(infile, line);
        int n = stoi(line);
        //adding all attVal pairs
        for (int i = 0; i < n; i++) {
            string att;
            string val;
            getline(infile, line);
            istringstream iss(line);
            getline(iss, att, ',');
            getline(iss, val, ',');
            string pair = line;
            //insert AttValPair into m_members attributes
            AttValPair attval(att, val);
            person.AddAttValPair(attval);
            vector<string> * search = m_pairs.search(pair);
            //no pairs in the vector (make a new vector)
            if (search == nullptr) {
                vector<string> tempEmails;
                tempEmails.push_back(email);
                m_pairs.insert(pair, tempEmails);
            }
            //add to the vector
            else {
                vector<string> * tempEmails = search;
                tempEmails->push_back(email);
            }
        }
        //inserting the PersonProfile into the member database
        m_members.insert(email, person);
        
        //getting the empty line
        getline(infile, line);
    }
    return true;
}

std::vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    string pair = input.attribute + "," + input.value;
    vector<string> * matches = m_pairs.search(pair);
    if (matches == nullptr) {
        vector<string> empty = {};
        return empty;
    }
    return *matches;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const {
    return m_members.search(email);
}
