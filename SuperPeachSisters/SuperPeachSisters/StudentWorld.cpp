#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
    return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

//constructor
StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}

//destructor
StudentWorld::~StudentWorld() {
    cleanUp();
}

int StudentWorld::init()
{
    Level lev(assetPath());
    string levelFile = "level01.txt";
    lev.loadLevel(levelFile);
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            //Block Object
            if (lev.getContentsOf(i, j) == Level::block) {
                Block * b = new Block(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(b);
            }
            //Pipe object
            if (lev.getContentsOf(i, j) == Level::pipe) {
                Pipe * p = new Pipe(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(p);
            }
            //Peach object
            if (lev.getContentsOf(i, j) == Level::peach)
                player = new Peach(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
            //Flag object
            if (lev.getContentsOf(i, j) == Level::flag) {
                Flag * f = new Flag(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(f);
            }
            //Mario object
            if (lev.getContentsOf(i, j) == Level::mario) {
                Mario * m = new Mario(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(m);
            }
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
    
    //clear all actors in vector
    for (Actor * n: actors) {
        delete n;
    }
    actors.clear();
}

bool StudentWorld::overlap(int x, int y) {
    //loop through all the actors
    for (Actor * n: actors) {
        //bottom left corner
        if (x >= n->getX() && x <= n->getX() + SPRITE_WIDTH - 1
            && y >=n->getY() && y <= n->getY() + SPRITE_HEIGHT - 1) {
            return true;
        }
        //bottom right corner
        if (x + SPRITE_WIDTH - 1 >= n->getX() && x + SPRITE_WIDTH - 1 <= n->getX() + SPRITE_WIDTH - 1
            && y >=n->getY() && y <= n->getY() + SPRITE_HEIGHT - 1)
            return true;
        //top left corner
        if (x >= n->getX() && x <= n->getX() + SPRITE_WIDTH - 1
            && y + SPRITE_HEIGHT - 1 >=n->getY() && y + SPRITE_HEIGHT - 1 <= n->getY() + SPRITE_HEIGHT - 1) {
            return true;
        }
        if (x + SPRITE_WIDTH - 1 >= n->getX() && x + SPRITE_WIDTH - 1 <= n->getX() + SPRITE_WIDTH - 1
            && y + SPRITE_HEIGHT - 1 >=n->getY() && y + SPRITE_HEIGHT - 1 <= n->getY() + SPRITE_HEIGHT - 1) {
            return true;
        }
    }
    return false;
}
