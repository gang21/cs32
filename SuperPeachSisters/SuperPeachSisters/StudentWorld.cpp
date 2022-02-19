#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include "Level.h"
#include <vector>
using namespace std;


// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

GameWorld* createStudentWorld(string assetPath)
{
    return new StudentWorld(assetPath);
}


StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    
}

int StudentWorld::init()
{
    Level lev(assetPath());
    string level_file = "level03.txt";
    lev.loadLevel(level_file);
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

