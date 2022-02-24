#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
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
    int level = getLevel();
    ostringstream oss;
    oss.fill('0');
    oss << "level" << setw(2) << level << ".txt";
    levelFile = oss.str();
    
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
            //Goomba object
            if (lev.getContentsOf(i, j) == Level::goomba) {
                Goomba * g = new Goomba(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(g);
            }
            //Koopa object
            if (lev.getContentsOf(i, j) == Level::koopa) {
                Koopa * k = new Koopa(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(k);
            }
            //Piranha object
            if (lev.getContentsOf(i, j) == Level::piranha) {
                Piranha * p = new Piranha(this, i * SPRITE_WIDTH, j * SPRITE_HEIGHT);
                actors.push_back(p);
            }
        }
    }
        
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    if (m_status == GWSTATUS_FINISHED_LEVEL)
        setStatus(GWSTATUS_CONTINUE_GAME);
    if (m_status == GWSTATUS_PLAYER_DIED && getLives() > 0)
        setStatus(GWSTATUS_CONTINUE_GAME);
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
    
    //peach died
    if (!player->getState()) {
        playSound(SOUND_PLAYER_DIE);
        m_status = GWSTATUS_PLAYER_DIED;
        decLives();
    }
    
    //setting text
    ostringstream text;
    text.fill('0');
    text << "Lives: " << getLives() << "  Level: " << getLevel() << "  Points: " << setw(6) << getScore();
    if (getPeach()->getStarPower())
        text << " StarPower!";
    if (getPeach()->getShootPower())
        text << " ShootPower!";
    if (getPeach()->getJumpPower())
        text << " JumpPower!";
    string s = text.str();
    setGameStatText(s);

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

bool StudentWorld::overlap(int x, int y, Actor* &character) {
    //loop through all the actors
    for (Actor * n: actors) {
        //skip if actor given is itself
        if (((x >= n->getX() && x <= n->getX() + SPRITE_WIDTH - 1)
            || (x + SPRITE_WIDTH - 1 >= n->getX() && x + SPRITE_WIDTH - 1 <= n->getX() + SPRITE_WIDTH - 1))
            && ((y >=n->getY() && y <= n->getY() + SPRITE_HEIGHT - 1)
            || (y + SPRITE_HEIGHT - 1 >= n->getY() && y + SPRITE_HEIGHT - 1 <= n->getY() + SPRITE_HEIGHT - 1))) {
            if (n != nullptr && n->blocksMovement()) {
                character = n;
                return true;
            }
            character = n;
        }
    }
    return false;
}

bool StudentWorld::overlap(Actor * a, Actor * b) {
    if (((a->getX() >= b->getX() && a->getX() <= b->getX() + SPRITE_WIDTH - 1)
        || (a->getX() + SPRITE_WIDTH - 1 >= b->getX() && a->getX() + SPRITE_WIDTH - 1 <= b->getX() + SPRITE_WIDTH - 1))
        && ((a->getY() >=b->getY() && a->getY() <= b->getY() + SPRITE_HEIGHT - 1)
        || (a->getY() + SPRITE_HEIGHT - 1 >= b->getY() && a->getY() + SPRITE_HEIGHT - 1 <= b->getY() + SPRITE_HEIGHT - 1))) {
        return true;
    }
    return false;
}

void StudentWorld::addActor(Actor *a) {
    actors.push_back(a);
}

bool StudentWorld::blockableObject(int x, int y) {
    for (Actor * n : actors) {
        if (x >= n->getX() && x <= n->getX() + SPRITE_WIDTH - 1 && y >= n->getY() && y <= n->getY() + SPRITE_HEIGHT - 1) {
            if (n->blocksMovement())
                return true;
        }
    }
    return false;
}

bool StudentWorld::damagableObject(int x, int y, Actor* &character) {
    for (Actor * n : actors) {
        //skip Peach object
        if (n->getImageID() == IID_PEACH)
            continue;
        else if (x >= n->getX() && x <= n->getX() + SPRITE_WIDTH - 1 && y >= n->getY() && y <= n->getY() + SPRITE_HEIGHT - 1) {
            if (n->isDamagable()) {
                character = n;
                return true;
            }
        }
    }
    return false;
}

