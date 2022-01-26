//
//  mazestack.cpp
//  HW2
//
//  Created by Gabriella Ang on 1/26/22.
//

#include <iostream>

class Coord {
  public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
  private:
    int m_r;
    int m_c;
};




