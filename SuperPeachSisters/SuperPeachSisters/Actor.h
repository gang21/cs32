#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject {
public:
    Actor(StudentWorld * sw, int x, int y, int ID, int depth, bool state);
    virtual void doSomething() = 0;
    int getImageID() {return m_imageID;}
    int getDepth() {return m_depth;}
    bool isAlive() {return m_state;}
    StudentWorld* getWorld() {return m_world;}
    virtual void getBonked() = 0;
    ~Actor() {return;}
private:
    StudentWorld* m_world;
    int m_imageID;
    int m_depth;
    bool m_state;
};

//Peach Class
class Peach:public Actor {
public:
    Peach(StudentWorld * sw, int x, int y);
    virtual void doSomething();
    bool gainTempInvincibility();
    void jump();
    virtual void getBonked();
    
private:
    int m_healthPts;
    bool m_starPower;
    bool m_shootPower;
    bool m_jumpPower;
    bool m_tempInvincibility;
    int m_recharge;
    int m_remaining_jump_distance;
};

//Block Class
class Block : public Actor {
public:
    Block(StudentWorld * sw, int x, int y, int goodie = -1);
    virtual void doSomething(){return;}
    virtual void getBonked();
private:
    int m_goodie;

};
#endif // ACTOR_H_
