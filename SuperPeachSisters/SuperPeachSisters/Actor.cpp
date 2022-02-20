#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

//Actor class implementation
//constructor
Actor::Actor(StudentWorld * sw, int x, int y, int ID, int depth, bool state) :  GraphObject(ID, x, y), m_world(sw)
{
//    m_world = sw;
    setSize(1);
    setDirection(0);
    m_imageID = ID;
    m_depth = depth;
    m_state = state;
}
void Actor::setState(bool state) {
    m_state = state;
}

bool Actor::getState() {
    return m_state;
}
//Immovable class implementation
Immovable::Immovable(StudentWorld * sw, int x, int y, int ID, int depth) : Actor(sw, x, y, ID, depth, true) {
    m_damage = false;
}

bool Immovable::isDamagable() {
    return m_damage;
}

bool Immovable::blocksMovement() {
    return true;
}


void Immovable::getBonked() {
    getWorld()->playSound(SOUND_PLAYER_BONK);
}

//Block class implementation
Block::Block(StudentWorld * sw, int x, int y, int goodie) : Immovable(sw, x, y, IID_BLOCK, 2) {
    m_goodie = goodie;
}

void Block::getBonked() {
    if (m_goodie == -1)
        getWorld()->playSound(SOUND_PLAYER_BONK);
    else
        //TODO: fix this part lol
        getWorld()->playSound(SOUND_PLAYER_POWERUP);
}

//Pipe class implementation
Pipe::Pipe(StudentWorld * sw, int x, int y) : Immovable(sw, x, y, IID_PIPE, 2)
{
}

//Goal class implementation
Goal::Goal(StudentWorld * sw, int x, int y, int ID, bool lastLev) : Immovable(sw, x, y, ID, 1)
{
    m_lastLevel = lastLev;
}

bool Goal::isLastLevel() {
    return m_lastLevel;
}

void Goal::doSomething() {
    if (!isAlive())
        return;
    //TODO: check overlap
    getWorld()->increaseScore(1000);
    setState(false);
//    if (!isLastLevel())

}
//Peach class implementation
Peach::Peach(StudentWorld * sw, int x, int y) : Actor(sw, x, y, IID_PEACH, 0, true) {
    m_healthPts = 1;
    m_tempInvincibility = false;
    m_starPower = false;
    m_shootPower = false;
    m_jumpPower = false;
    m_remaining_jump_distance = 0;
}

void Peach::jump() {
    if(m_jumpPower)
        m_remaining_jump_distance += 4;
    if (m_remaining_jump_distance > 0) {
        if (!getWorld()->overlap(getX(), getY() + 4))
            moveTo(getX(), getY() + 4);
        else {
            getWorld()->playSound(SOUND_PLAYER_BONK);
        }
    }
    m_remaining_jump_distance -= 4;
}

void Peach::move() {
    int keyPressed;
    getWorld()->getKey(keyPressed);
    jump();
    switch (keyPressed) {
        case KEY_PRESS_RIGHT:
            setDirection(0);
            //checking for overlap
            if (getWorld()->overlap(getX() + 4, getY()))
                getWorld()->playSound(SOUND_PLAYER_BONK);
            else
                moveTo(getX() + 4, getY());
            break;
        case KEY_PRESS_LEFT:
            setDirection(180);
            if (getWorld()->overlap(getX() - 4, getY()))
                getWorld()->playSound(SOUND_PLAYER_BONK);
            else
                moveTo(getX() - 4, getY());
            break;
        case KEY_PRESS_UP:
            m_remaining_jump_distance = 24;
            jump();
            break;
            
        default:
            break;
    }
}
void Peach::doSomething() {
    //checking if she's alive
    if (!isAlive())
        return;
    //moving if key is pressed
    move();
//
//    //checking current invincibility
//    if (m_starPower) {
//        //TODO: decrement tick by 1 (figure out how to do this)
//        if (/*FIXME: tick == 0*/0 == 1)
//            m_starPower = false;
//    }
//
//    //checking temporary invincibility
//    if (m_tempInvincibility) {
//        //TODO: decrement tick by 1
//        if (/*FIXME: tick == 0*/0 == 1)
//            m_tempInvincibility = false;
//    }
//
//    //recharge mode
//    if (m_shootPower) {
//        if (m_recharge > 0)
//            m_recharge--;
//        //else
//            //shoot fireball
//    }

}

void Peach::getBonked() {
    return;
}
