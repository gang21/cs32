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
    m_pairs = nullptr;
    m_members = nullptr;
}

MemberDatabase::~MemberDatabase() {
    //TODO: implement this destructor
}

bool MemberDatabase::LoadDatabase(string filename) {
    ifstream infile;
    infile.open(filename);

    //file not uploaded properly
    if (!infile) {
        //TODO: delete this later
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
        //two members with the same email
        if (m_members->search(email) != nullptr)
            return false;
        //create a new member for the database
        PersonProfile * person = new PersonProfile(name, email);
        m_members->insert(email, person);
            
        //get the number of attVal pairs
        int n;
        cin >> n;
        cin.ignore();
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
            string pair = att + val;
            vector<string> * tempEmails = m_pairs->search(pair);
            tempEmails->push_back(email);
            m_pairs->insert(pair, *tempEmails);
        }
        //getting the empty line
        getline(infile, line);
    }
    //TODO: delete this later
    cout << "sucessssssssss" << endl;
    return true;
}

std::vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
    string pair = input.attribute + input.value;
    return *(m_pairs->search(pair));
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const {
    return *(m_members->search(email));
}

int main() {
    MemberDatabase a;
    a.LoadDatabase("members.txt");
    
}

