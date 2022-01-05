//
//  gark.h
//  Project1
//
//  Created by Gabriella Ang on 1/5/22.
//

#ifndef gark_h
#define gark_h

#include <stdio.h>
class Mesa;

class Gark
{
  public:
        // Constructor
    Gark(Mesa* mp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();
    bool getAttacked(int dir);

  private:
    Mesa* m_mesa;
    int   m_row;
    int   m_col;
    int   m_health;
};

#endif /* gark_h */
