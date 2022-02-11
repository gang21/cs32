////
////  mazequeue.cpp
////  HW2
////
////  Created by Gabriella Ang on 1/26/22.
////
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//class Coord {
//  public:
//    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
//    int r() const { return m_r; }
//    int c() const { return m_c; }
//  private:
//    int m_r;
//    int m_c;
//};
//
//bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
//         // Return true if there is a path from (sr,sc) to (er,ec)
//         // through the maze; return false otherwise
//    queue<Coord> coordQueue;
//    Coord start(sr, sc);
//    Coord end(er, ec);
//    coordQueue.push(start);
//    maze[sr][sc] = '*';
//
//    while (!coordQueue.empty()) {
//        Coord currentCoord = coordQueue.front();
//        coordQueue.pop();
//
//         if (currentCoord.r() == end.r() && currentCoord.c() == end.c()) {
//             return true;
//         }
//         //west
//         if (maze[currentCoord.r()][currentCoord.c() - 1] == '.') {
//             Coord west(currentCoord.r(), currentCoord.c() - 1);
//             coordQueue.push(west);
//             maze[currentCoord.r()][currentCoord.c() - 1] = '*';
//         }
//         //south
//         if (maze[currentCoord.r() + 1][currentCoord.c()] == '.') {
//             Coord south(currentCoord.r() + 1, currentCoord.c());
//             coordQueue.push(south);
//             maze[currentCoord.r() + 1][currentCoord.c()] = '*';
//         }
//         //east
//         if (maze[currentCoord.r()][currentCoord.c() + 1] == '.') {
//             Coord east(currentCoord.r(), currentCoord.c() + 1);
//             coordQueue.push(east);
//             maze[currentCoord.r()][currentCoord.c() + 1] = '*';
//         }
//         //north
//         if (maze[currentCoord.r() - 1][currentCoord.c()] == '.') {
//             Coord north(currentCoord.r() - 1, currentCoord.c());
//             coordQueue.push(north);
//             maze[currentCoord.r() - 1][currentCoord.c()] = '*';
//         }
//
////        //debugging purposes
////        for (int i = 0; i < nRows; i++) {
////            for (int j = 0; j < nCols; j++) {
////                cout << maze[i][j];
////            }
////            cout << endl;
////        }
////        cout << endl << endl;
//     }
//
//    return false;
//}
//
//int main() {
//                string maze[10] = {
//                    "XXXXXXXXXX",
//                    "X.X..X...X",
//                    "X....XXX.X",
//                    "X.XXXX.X.X",
//                    "X......XXX",
//                    "X.XX.X...X",
//                    "X.X..X.X.X",
//                    "X.X.XXXX.X",
//                    "X.X...X..X",
//                    "XXXXXXXXXX"
//                };
//
//                if (pathExists(maze, 10,10, 4,6, 1,1))
//                    cout << "Solvable!" << endl;
//                else
//                    cout << "Out of luck!" << endl;
//}
