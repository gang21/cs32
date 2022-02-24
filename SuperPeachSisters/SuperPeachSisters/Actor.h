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
    virtual void bonk() = 0;
    virtual bool isDamagable() = 0;
    virtual bool blocksMovement() = 0;
    void setState(bool state) {m_state = state;}
    bool getState() {return m_state;}
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
    virtual void bonk();
    virtual bool isDamagable() {return true;}
    virtual bool blocksMovement() {return false;}
    void increaseHitPoints() {m_healthPts++;}
    //mutators
    void setStarPower(int ticks) {m_starPower = ticks;}
    void setShootPower(bool shoot) {m_shootPower = shoot;}
    void setJumpPower(bool jump) {m_jumpPower = jump;}
    //accessors
    bool getStarPower() {return m_starPower;}
    bool getJumpPower() {return m_jumpPower;}
    bool getShootPower() {return m_shootPower;}

private:
    void jump();
    void move();
    int m_healthPts;
    int m_starPower;
    bool m_shootPower;
    bool m_jumpPower;
    int m_tempInvincibility;
    int m_recharge;
    int m_remaining_jump_distance;
};

//Immovable Class
class Immovable : public Actor {
public:
    Immovable(StudentWorld * sw, int x, int y, int ID, int depth);
    virtual void doSomething() {return;}
    virtual void bonk();
    virtual bool isDamagable() {return false;}
    virtual bool blocksMovement() {return true;}
private:
    bool m_damage;
    
};

//Block Class
class Block : public Immovable {
public:
    Block(StudentWorld * sw, int x, int y, int goodie = -1);
    virtual void bonk();
private:
    void releaseGoodie();
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

//Goodies Class
class Goodies : public Actor {
public:
    Goodies(StudentWorld * sw, int x, int y, int ID);
    virtual void doSomething();
    virtual bool isDamagable() {return false;}
    virtual bool blocksMovement() {return false;}
    virtual void bonk() {return;}
    void move();
    
    //accessors
    int getPointValue() {return m_points;}
    int getPower() {return m_power;}
    //mutators
    void setPointValue(int points) {m_points = points;}
    void setPower(int power) {m_power = power;}
    
private:
    int m_points;
    int m_power;
};

//Flower Class
class Flower : public Goodies {
public:
    Flower(StudentWorld * sw, int x, int y);
};

//Mushroom Class
class Mushroom : public Goodies {
public:
    Mushroom(StudentWorld * sw, int x, int y);
};

//Star Class
class Star : public Goodies {
public:
    Star(StudentWorld * sw, int x, int y);
};

//Projectile Class
class Projectile : public Actor {
public:
    Projectile(StudentWorld * sw, int x, int y, int ID, int dir);
    virtual void doSomething() = 0;
    virtual bool isDamagable() {return false;}
    virtual bool blocksMovement() {return false;}
    virtual void bonk() {return;}
    virtual bool causeDamage() = 0;
    virtual void move();
};

//Piranha Fireball Class
class PiranhaFireball : public Projectile {
public:
    PiranhaFireball(StudentWorld * sw, int x, int y, int dir);
    virtual bool causeDamage();
    virtual void doSomething();
    
};

//Peach Fireball Class
class PeachFireball : public Projectile {
public:
    PeachFireball(StudentWorld * sw, int x, int y, int dir);
    virtual bool causeDamage();
    virtual void doSomething();
    virtual void move();
};

//Shell Class
class Shell : public Projectile {
public:
    Shell(StudentWorld * sw, int x, int y, int dir);
    virtual bool causeDamage();
    virtual void doSomething();
};

//Monster Class
class Monster : public Actor {
public:
    Monster(StudentWorld * sw, int x, int y, int ID);
    virtual void doSomething();
    virtual void bonk();
    virtual bool isDamagable() {return true;}
    virtual bool blocksMovement() {return false;}
    virtual void move();
};

//Goomba Class
class Goomba : public Monster {
public:
    Goomba(StudentWorld * sw, int x, int y);
};

//Koopa Class
class Koopa : public Monster {
public:
    Koopa(StudentWorld * sw, int x, int y);
    virtual void bonk();
};

//Piranha Class
class Piranha : public Monster {
public:
    Piranha(StudentWorld * sw, int x, int y);
    virtual void doSomething();
private:
    int m_firing_delay;
};


#endif // ACTOR_H_
