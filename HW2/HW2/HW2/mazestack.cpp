//
//  mazestack.cpp
//  HW2
//
//  Created by Gabriella Ang on 1/26/22.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Coord {
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
         // Return true if there is a path from (sr,sc) to (er,ec)
         // through the maze; return false otherwise
    
    stack<Coord> coordStack;
    Coord start(sr, sc);
    coordStack.push(start);
    maze[sr][sc] = '*';
    
    while (!coordStack.empty()) {
        
    }
    return false;
}

int main() {
    
}

