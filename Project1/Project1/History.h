//
//  History.hpp
//  Project1
//
//  Created by Gabriella Ang on 1/5/22.
//

#ifndef History_h
#define History_h

#include "globals.h"
#include <stdio.h>

class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
      private:
        int m_rows;
        int m_cols;
        char attackCount[MAXROWS][MAXCOLS];
    };

#endif /* History_h */
