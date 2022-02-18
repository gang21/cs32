#include "Actor.h"
#include "StudentWorld.h"

//Actor class implementation

//constructor
Actor::Actor(StudentWorld * sw, int x, int y, int ID, int depth, bool state) : GraphObject(ID, x, y)
{
    m_world = sw;
    setSize(1);
    setDirection(0);
    m_imageID = ID;
    m_depth = depth;
    m_state = state;
}

//Block class implementation
Block::Block(StudentWorld * sw, int x, int y, int goodie) : Actor(sw, x, y, IID_BLOCK, 2, true) {
    m_goodie = goodie;
}

void Block::getBonked() {
    if (m_goodie == -1) {
        getWorld()->playSound(SOUND_PLAYER_BONK);
    }
    else {
        getWorld()->playSound(SOUND_POWERUP_APPEARS);
        //TODO: function for object to release
    }
    return;
}

//Peach class implementation
Peach::Peach(StudentWorld * sw, int x, int y) : Actor(sw, x, y, IID_PEACH, 0, true) {
    m_healthPts = 1;
    m_tempInvincibility = false;
    m_starPower = false;
    m_shootPower = false;
    m_jumpPower = false;
    
}

bool Peach::gainTempInvincibility() {
    if (m_jumpPower || m_shootPower) {
        //if this is equal to some other attacker
            //lose power
            //gain temp invisibility for some ticks
            //return true
    }
    return false; //FIXME: fix this lol
}


void Peach::doSomething() {
    //checking if she's alive
    if (!isAlive())
        return;

    //checking current invincibility
    if (m_starPower) {
        //TODO: decrement tick by 1 (figure out how to do this)
        if (/*FIXME: tick == 0*/0 == 1)
            m_starPower = false;
    }

    //checking temporary invincibility
    if (m_tempInvincibility) {
        //TODO: decrement tick by 1
        if (/*FIXME: tick == 0*/0 == 1)
            m_tempInvincibility = false;
    }

    //recharge mode
    if (m_shootPower) {
        if (m_recharge > 0)
            m_recharge--;
        //else
            //shoot fireball
    }

}


