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
    m_status = GWSTATUS_CONTINUE_GAME;
    player = nullptr;
}

//destructor
StudentWorld::~StudentWorld() {
    cleanUp();
}

int StudentWorld::init()
{
    Level lev(assetPath());
    //determining level file
    if (getLevel() == 1)
        levelFile = "level01.txt";
    if (getLevel() == 2)
        levelFile = "level02.txt";
    if (getLevel() == 3)
        levelFile = "level03.txt";
    
    lev.loadLevel(levelFile);
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            //Block Object
            if (lev.getContentsOf(i, j) == Level::block) {
                Block * b = new Block(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(b);
            }
            //Star Goodie Block
            if (lev.getContentsOf(i, j) == Level::star_goodie_block) {
                Block * s = new Block(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, IID_STAR);
                actors.push_back(s);
            }
            //Mushroom Goodie Block
            if (lev.getContentsOf(i, j) == Level::mushroom_goodie_block) {
                Block * m = new Block(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, IID_MUSHROOM);
                actors.push_back(m);
            }
            //Flower Goodie Block
            if (lev.getContentsOf(i, j) == Level::flower_goodie_block) {
                Block * f = new Block(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT, IID_FLOWER);
                actors.push_back(f);
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
    //actors do something
    for (Actor * n : actors) {
        if (n->getState()) {
            n->doSomething();
        }
    }
    //delete any dead objects
    auto it = actors.begin();
    while (it != actors.end()) {
        if (!(*it)->getState()) {
            delete *it;
            actors.erase(it);
        }
        else
            ++it;
    }
    //peach's move
    player->doSomething();
    
    if (!player->getState()) {
        playSound(SOUND_PLAYER_DIE);
        m_status = GWSTATUS_PLAYER_DIED;
    }
    
//    decLives();
    return m_status;
}

void StudentWorld::cleanUp()
{
    if (player != nullptr)
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

bool StudentWorld::overlap(Actor * a, Actor * b) {
    //bottom left corner
    if (a->getX() >= b->getX() && a->getX() <= b->getX() + SPRITE_WIDTH - 1
        && a->getY() >= b->getY() && a->getX() <= b->getY() + SPRITE_HEIGHT - 1) {
        return true;
    }
    //bottom right corner
    if (a->getX() + SPRITE_WIDTH - 1 >= b->getX() && a->getX() + SPRITE_WIDTH - 1 <= b->getX() + SPRITE_WIDTH - 1
        && a->getY() >= b->getY() && a->getY() <= b->getY() + SPRITE_HEIGHT - 1)
        return true;
    //top left corner
    if (a->getX() >= b->getX() && a->getX() <= b->getX() + SPRITE_WIDTH - 1
        && a->getY() + SPRITE_HEIGHT - 1 >= b->getY() && a->getY()+ SPRITE_HEIGHT - 1 <= b->getY() + SPRITE_HEIGHT - 1) {
        return true;
    }
    if (a->getX() + SPRITE_WIDTH - 1 >= b->getX() && a->getX() + SPRITE_WIDTH - 1 <= b->getX() + SPRITE_WIDTH - 1
        && a->getY() + SPRITE_HEIGHT - 1 >= b->getY() && a->getY() + SPRITE_HEIGHT - 1 <= b->getY() + SPRITE_HEIGHT - 1) {
        return true;
    }
    return false;
}

void StudentWorld::addActor(Actor *a) {
    actors.push_back(a);
}

Actor* StudentWorld::getActorAt(int x, int y) {
    //loop through actors
    for (Actor* n : actors) {
        //check for overlap (increments of 4)
        if ((n->getX() == x && n->getY() == y)
            || (n->getX() + 4 == x && n->getY() == y)
            || (n->getX() - 4 == x && n->getY() == y)
            || (n->getX() == x && n->getY() + 4 == y)
            || (n->getX() == x && n->getY() - 4 == y)
            || (n->getX() + 4 == x && n->getY() + 4 == y)
            || (n->getX() + 4 == x && n->getY() - 4 == y)
            || (n->getX() - 4 == x && n->getY() + 4 == y)
            || (n->getX() - 4 == x && n->getY() - 4 == y)) {
            return n;
        }
    }
    return nullptr;
}
