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
    string level_file = "level01.txt";
    Level::LoadResult result = lev.loadLevel(level_file);
    vector<Block> blocks;
//    for (int i = 0; i < GRID_WIDTH; i++) {
//        for (int j = 0; j < GRID_HEIGHT; j++) {
//            //Block Object
//            if (result.getContentsOf(i, j) == '#') {
//                Block b(this, i, j);
//                blocks.push_back(b);
//            }
//            //Peach object
//        }
//    }
        
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

