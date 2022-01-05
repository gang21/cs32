//
//  History.cpp
//  Project1
//
//  Created by Gabriella Ang on 1/5/22.
//

#include "History.h"
#include <iostream>

using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            attackCount[i][j] = '.';
        }
    }
}

bool History::record(int r, int c) {
    if (r < 1 || r > m_rows || c < 1 || c > m_cols) {
        return false;
    }
    if (attackCount[r-1][c-1] == '.') {
        attackCount[r-1][c-1] = 'A';
    }
    else if (attackCount[r-1][c-1] == 'Z') {
        attackCount[r-1][c-1] = 'Z';
    }
    else {
        attackCount[r-1][c-1]++;
    }
    return true;
}

void History::display() const {
    clearScreen();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << attackCount[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
