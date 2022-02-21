#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

class StudentWorld;

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
    virtual bool isDamagable() = 0;
    void setState(bool state);
    bool getState();
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
    virtual bool isDamagable() {return true;}

private:
    void move();
    int m_healthPts;
    bool m_starPower;
    bool m_shootPower;
    bool m_jumpPower;
    bool m_tempInvincibility;
    int m_recharge;
    int m_remaining_jump_distance;
};

//Immovable Class
class Immovable : public Actor {
public:
    Immovable(StudentWorld * sw, int x, int y, int ID, int depth);
    virtual void doSomething() {return;}
    virtual void getBonked();
    virtual bool isDamagable() {return false;}
    virtual bool blocksMovement() {return true;}
private:
    bool m_damage;
    
};

//Block Class
class Block : public Immovable {
public:
    Block(StudentWorld * sw, int x, int y, int goodie = -1);
    virtual void getBonked();
    void releaseGoodie();
private:
    int m_goodie;
};

//Pipe Class
class Pipe : public Immovable {
public:
    Pipe(StudentWorld * sw, int x, int y);
};

//Flag Class
class Flag : public Immovable {
public:
    Flag(StudentWorld * sw, int x, int y, int ID = IID_FLAG);
    virtual void doSomething();
    virtual bool blocksMovement() {return false;}
    virtual bool isLastLevel() {return false;}
};

//Mario Class
class Mario : public Flag {
public:
    Mario(StudentWorld * sw, int x, int y);
    virtual bool isLastLevel() {return true;}
};

#endif // ACTOR_H_
