#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor:public GraphObject {
public:
    Actor(int x, int y, int ID, int dir, int depth, int size, bool state);
    virtual void doSomething() = 0;
    int getStartPositionX() {return m_x;}
    int getStartPositionY() {return m_y;}
    int getImageID() {return m_imageID;}
    int getDirection() {return m_direction;}
    int getDepth() {return m_depth;}
    int getSize() {return m_size;}
    bool isAlive() {return m_state;}
    ~Actor();
private:
    int m_x;
    int m_y;
    int m_imageID;
    int m_direction;
    int m_depth;
    int m_size;
    bool m_state;
};

class Block:public Actor {
public:
    Block(int x, int y, int goodie);
    virtual void doSomething(){return;}
    void getBonked();
private:
    int m_goodie;

};

#endif // ACTOR_H_
