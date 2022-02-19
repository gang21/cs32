#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "Level.h"
#include <string>


// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

//GameWorld* StudentWorld::createStudentWorld(string assetPath)
//{
//    return new StudentWorld(assetPath);
//}


StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    
}
//int StudentWorld::getBlockAt(int x, int y) {
//    for (Actor* i : actors) {
//        if ((i->getX() < x && i->getX() + SPRITE_WIDTH - 1 > x
//            && i->getY() < y && i->getY() + SPRITE_HEIGHT - 1 > y)
//            || (i->getX() + SPRITE_WIDTH - 1 < x && i->getX() + SPRITE_WIDTH - 1> x + SPRITE_WIDTH - 1
//            && i->getY() < y  + SPRITE_HEIGHT - 1 && i->getY() + SPRITE_HEIGHT - 1 > y + SPRITE_HEIGHT - 1))
//        {
//            return i->getImageID();
//        }
//    }
//    return -1;
//}

//checking for any overlap between Peach and actors
bool StudentWorld::overlap(int x, int y) {
    int aLeftBound = x;
    int aRightBound = x + SPRITE_WIDTH - 1;
    int aUpperBound = y;
    int aLowerBound = y + SPRITE_HEIGHT - 1;
    
    for (Actor * b : actors) {
    int bLeftBound = b->getX();
    int bRightBound = b->getX() + SPRITE_WIDTH - 1;
    int bUpperBound = b->getY();
    int bLowerBound = b->getY() + SPRITE_HEIGHT - 1;
    //checking if one sprite is on the left side of the other
    if (aLeftBound > bRightBound || bLeftBound > aRightBound)
        return false;
    //checking if one sprite is above the other
    if (aUpperBound < bLowerBound || bUpperBound < aLowerBound)
        return false;
    }
    return true;
}

int StudentWorld::init()
{
    Level lev(assetPath());
    levelFile = "level01.txt";
    lev.loadLevel(levelFile);
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            //Block Object
            if (lev.getContentsOf(i, j) == Level::block) {
                Block * b = new Block(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
                actors.push_back(b);
            }
            //Peach object
            if (lev.getContentsOf(i, j) == Level::peach)
                player = new Peach(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
        }
    }
        
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    player->doSomething();
//    decLives();
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    delete player;
}

