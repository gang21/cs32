#include "Actor.h"
#include "StudentWorld.h"
#include <iostream>

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

//Immovable class implementation
Immovable::Immovable(StudentWorld * sw, int x, int y, int ID, int depth) : Actor(sw, x, y, ID, depth, true) {
    m_damage = false;
}

void Immovable::bonk() {
    getWorld()->playSound(SOUND_PLAYER_BONK);
}

//Block class implementation
Block::Block(StudentWorld * sw, int x, int y, int goodie) : Immovable(sw, x, y, IID_BLOCK, 2) {
    m_goodie = goodie;
}

void Block::bonk() {
    if (m_goodie == -1)
        getWorld()->playSound(SOUND_PLAYER_BONK);
    else {
        releaseGoodie();
        getWorld()->playSound(SOUND_POWERUP_APPEARS);
        m_goodie = -1;
    }

}

void Block::releaseGoodie() {
    if (m_goodie == IID_FLOWER) {
        Flower * power = new Flower(getWorld(), getX(), getY() + 8);
        getWorld()->addActor(power);
    }
    if (m_goodie == IID_MUSHROOM) {
        Mushroom * power = new Mushroom(getWorld(), getX(), getY() + 8);
        getWorld()->addActor(power);
    }
    if (m_goodie == IID_STAR) {
        Star * power = new Star(getWorld(), getX(), getY() + 8);
        getWorld()->addActor(power);
    }
    
    
}

//Pipe class implementation
Pipe::Pipe(StudentWorld * sw, int x, int y) : Immovable(sw, x, y, IID_PIPE, 2)
{
}

//Flag class implementation
Flag::Flag(StudentWorld * sw, int x, int y, int ID) : Immovable(sw, x, y, ID, 1)
{
}

void Flag::doSomething() {
    if (!isAlive())
        return;
    if(getWorld()->overlap(this, getWorld()->getPeach())) {
        getWorld()->increaseScore(1000);
        setState(false);
        if (!isLastLevel())
            getWorld()->setStatus(GWSTATUS_FINISHED_LEVEL);
        else
            getWorld()->setStatus(GWSTATUS_PLAYER_WON);
    }

}


//Mario Class Implementation
Mario::Mario(StudentWorld * sw, int x, int y) : Flag(sw, x, y, IID_MARIO)
{
}

//Peach class implementation
Peach::Peach(StudentWorld * sw, int x, int y) : Actor(sw, x, y, IID_PEACH, 0, true) {
    m_healthPts = 1;
    m_tempInvincibility = 0;
    m_starPower = 0;
    m_shootPower = false;
    m_jumpPower = false;
    m_remaining_jump_distance = 0;
}

void Peach::jump() {
    //continue/begin jump
    if (m_remaining_jump_distance > 0) {
        //check for any blocks in her way
        if (getWorld()->overlap(getX(), getY() + 4)) {
            Actor * n = getWorld()->getActorAt(getX(), getY() + 8);
            if (n != nullptr)
                n->bonk();
           //getWorld()->playSound(SOUND_POWERUP_APPEARS); //FIXME: this needs to be specific for every diffent object (so call bonk() for specific objects)wq
            //TODO: object.bonk(); figure out how to do this part
            m_remaining_jump_distance = 0;
        }
        //move up
        else {
            moveTo(getX(), getY() + 4);
            m_remaining_jump_distance--;
        }
    }
    //check if she's falling
    else if (m_remaining_jump_distance == 0) {
        if (!getWorld()->overlap(getX(), getY() - 1)
            && !getWorld()->overlap(getX(), getY() - 2)
            && !getWorld()->overlap(getX(), getY() - 3)) {
            moveTo(getX(), getY() - 4);
        }
    }
}

void Peach::move() {
    jump();
    int keyPressed;
    getWorld()->getKey(keyPressed);
    switch (keyPressed) {
        case KEY_PRESS_RIGHT: {
            setDirection(0);
            //checking for overlap and block of movement
            Actor * n = getWorld()->getActorAt(getX() + 8, getY());
            if (getWorld()->overlap(getX() + 4, getY()) && n != nullptr && n->blocksMovement()) {
                    getWorld()->playSound(SOUND_PLAYER_BONK);
            }
            else
                moveTo(getX() + 4, getY());
            break;
        }
        case KEY_PRESS_LEFT: {
            setDirection(180);
            Actor * n = getWorld()->getActorAt(getX() - 8, getY());
            if (getWorld()->overlap(getX() - 4, getY()) && n != nullptr && n->blocksMovement()) {
                    getWorld()->playSound(SOUND_PLAYER_BONK);
            }
            else
                moveTo(getX() - 4, getY());
            break;
        }
        case KEY_PRESS_UP: {
            if (getWorld()->overlap(getX(), getY() - 1)
                && getWorld()->overlap(getX(), getY() - 2)
                && getWorld()->overlap(getX(), getY() - 3)) {
                m_remaining_jump_distance = 8;
            }
            if (m_jumpPower)
                m_remaining_jump_distance *= 1.5;
            getWorld()->playSound(SOUND_PLAYER_JUMP);
            jump();
            break;
        }
        case KEY_PRESS_SPACE: {
            if (!m_shootPower)
                break;
            if (m_recharge > 0) {
                m_recharge--;
                break;
            }
            getWorld()->playSound(SOUND_PLAYER_FIRE);
            m_recharge = 8;
            //TODO: Create fireball object
            break;
        }
        default:
            break;
    }
}
void Peach::doSomething() {
    //checking if she's alive
    if (!isAlive())
        return;
    //move if key is pressed
    move();
    //TODO: finish implementing the rest of this function
}

void Peach::bonk() {
    //Peach is invincible
    if(m_starPower > 0|| m_tempInvincibility)
        return;
    
    m_healthPts--;
    m_tempInvincibility = 10;
    m_shootPower = false;
    m_jumpPower = false;
    
    if (m_healthPts >= 1)
        getWorld()->playSound(SOUND_PLAYER_HURT);
    if (m_healthPts == 0) {
        setState(false);
    }
}

//Goodies class implementation
Goodies::Goodies(StudentWorld * sw, int x, int y, int ID) : Actor(sw, x, y, ID, 1, true)
{
}

void Goodies::doSomething() {
    if (getWorld()->overlap(getWorld()->getPeach(), this)) {
        getWorld()->increaseScore(getPointValue());
        if (m_power == IID_FLOWER)
            getWorld()->getPeach()->setShootPower(true);
        if (m_power == IID_MUSHROOM)
            getWorld()->getPeach()->setJumpPower(true);
        if (m_power == IID_STAR)
            getWorld()->getPeach()->setStarPower(150);
        setState(false);
        getWorld()->playSound(SOUND_PLAYER_POWERUP);
        return;
    }
    move();
}

void Goodies::move() {
    if (!getWorld()->overlap(getX(), getY() - 2)) { //FIXME: overlap with blockMovement function
        moveTo(getX(), getY() - 2);
    }
    //to the right
    if (getDirection() == 0) {
        if (getWorld()->overlap(getX() + 2, getY())) {
            setDirection(180);
            return;
        }
        else {
            moveTo(getX() + 2, getY());
        }
    }
    //to the left
    if (getDirection() == 180) {
        if (getWorld()->overlap(getX() - 2, getY())) {
            setDirection(0);
            return;
        }
        else {
            moveTo(getX() - 2, getY());
        }
    }
}

//Flower class implementation
Flower::Flower(StudentWorld * sw, int x, int y) : Goodies(sw, x, y, IID_FLOWER) {
    setPointValue(50);
    setPower(IID_FLOWER);
}

//Mushroom class implementation
Mushroom::Mushroom(StudentWorld * sw, int x, int y) : Goodies(sw, x, y, IID_MUSHROOM) {
    setPointValue(75);
    setPower(IID_MUSHROOM);
}

//Star class implementation
Star::Star(StudentWorld * sw, int x, int y) : Goodies(sw, x, y, IID_STAR) {
    setPointValue(100);
    setPower(IID_STAR);
}
