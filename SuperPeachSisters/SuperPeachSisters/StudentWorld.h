#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Peach;
class Block;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    int getBlockAt(int x, int y);
//    bool overlap(Actor a, Actor b);
        


private:
    Peach* player;
};

#endif // STUDENTWORLD_H_
