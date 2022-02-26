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
        Flower * power = new Flower(getWorld(), getX(), getY() + SPRITE_HEIGHT);
        getWorld()->addActor(power);
    }
    if (m_goodie == IID_MUSHROOM) {
        Mushroom * power = new Mushroom(getWorld(), getX(), getY() + SPRITE_HEIGHT);
        getWorld()->addActor(power);
    }
    if (m_goodie == IID_STAR) {
        Star * power = new Star(getWorld(), getX(), getY() + SPRITE_HEIGHT);
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
        if (!isLastLevel()) {
            getWorld()->setStatus(GWSTATUS_FINISHED_LEVEL);
            getWorld()->playSound(SOUND_FINISHED_LEVEL);
        }
        else {
            getWorld()->setStatus(GWSTATUS_PLAYER_WON);
            getWorld()->playSound(SOUND_FINISHED_LEVEL);
        }
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
        Actor * n;
        if (getWorld()->overlap(getX(), getY() + 4, n) && n!= nullptr && n->blocksMovement()) {
                n->bonk();
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
        Actor * a;
        if (!getWorld()->overlap(getX(), getY() - 1, a)
            && !getWorld()->overlap(getX(), getY() - 2, a)
            && !getWorld()->overlap(getX(), getY() - 3, a)) {
            moveTo(getX(), getY() - 4);
        }
        else if (a != nullptr
                 && !a->blocksMovement()) {
            moveTo(getX(), getY() - 4);
        }
    }
}

void Peach::move() {
    jump();
    int keyPressed;
    getWorld()->getKey(keyPressed);
    switch (keyPressed) {
        case KEY_PRESS_SPACE: {
            if (!m_shootPower)
                break;
            if (m_recharge > 0) {
                break;
            }
            getWorld()->playSound(SOUND_PLAYER_FIRE);
            m_recharge = 8;
            if (getDirection() == 0) {
                PeachFireball * peachFire = new PeachFireball(getWorld(), getX() + 4, getY(), getDirection());
                getWorld()->addActor(peachFire);
            }
            if (getDirection() == 180) {
                PeachFireball * peachFire = new PeachFireball(getWorld(), getX() - 4, getY(), getDirection());
                getWorld()->addActor(peachFire);
            }
            break;
        }
        case KEY_PRESS_RIGHT: {
            setDirection(0);
            //checking for overlap and block of movement
            Actor * n;
            if (getWorld()->overlap(getX() + 4, getY(), n) && n != nullptr && n->blocksMovement()) {
                    getWorld()->playSound(SOUND_PLAYER_BONK);
            }
            else
                moveTo(getX() + 4, getY());
            break;
        }
        case KEY_PRESS_LEFT: {
            setDirection(180);
            Actor * n;
            if (getWorld()->overlap(getX() - 4, getY(), n) && n != nullptr && n->blocksMovement()) {
                    getWorld()->playSound(SOUND_PLAYER_BONK);
            }
            else
                moveTo(getX() - 4, getY());
            break;
        }
        case KEY_PRESS_UP: {
            Actor * n;
            if (getWorld()->overlap(getX(), getY() - 1, n)
                && getWorld()->overlap(getX(), getY() - 2, n)
                && getWorld()->overlap(getX(), getY() - 3, n)) {
                m_remaining_jump_distance = 8;
            }
            if (m_jumpPower)
                m_remaining_jump_distance *= 1.5;
            getWorld()->playSound(SOUND_PLAYER_JUMP);
            jump();
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
    if (m_recharge > 0)
        m_recharge--;
    if (m_starPower > 0) {
        m_starPower--;
    }
    if(m_tempInvincibility > 0) {
        m_tempInvincibility--;
        Actor * n;
        if (getWorld()->overlap(getX(), getY(), n) && n != nullptr) {
            n->bonk();
        }
    }
    //move if key is pressed
    move();
    

}

void Peach::bonk() {
    //Peach is invincible
    Actor * n;
    if (m_starPower > 0 || m_tempInvincibility > 0) {
        getWorld()->overlap(getX(), getY(), n);
            n->bonk();
            return;
    }
    m_healthPts--;
    
    if (m_healthPts == 1)  {
        getWorld()->playSound(SOUND_PLAYER_HURT);
        m_tempInvincibility = 10;
        m_shootPower = false;
        m_jumpPower = false;
        return;
    }
    else
        setState(false);
}

void Peach::increaseHitPoints() {
    if (m_healthPts == 2)
        return;
    m_healthPts++;
}
bool Peach::getStarPower() {
    if (m_starPower > 0)
        return true;
    return false;
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
    Actor * n;
    //move down
    if (!(getWorld()->overlap(getX(), getY() - 2, n) && n != nullptr && n->blocksMovement())) {
        moveTo(getX(), getY() - 2);
    }
    //to the right
    if (getDirection() == 0) {
        if (getWorld()->overlap(getX() + 2, getY(), n) && n != nullptr && n->blocksMovement()) {
            setDirection(180);
            return;
        }
        else {
            moveTo(getX() + 2, getY());
        }
    }
    //to the left
    if (getDirection() == 180) {
        if (getWorld()->overlap(getX() - 2, getY(), n) && n != nullptr && n->blocksMovement()){
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

//Projectile class implementation
Projectile::Projectile(StudentWorld * sw, int x, int y, int ID, int dir) : Actor(sw, x, y, ID, 1, true) {
    setDirection(dir);
}

void Projectile::move() {
    //move down
    if (!getWorld()->blockableObject(getX(), getY() - 2)
        && !getWorld()->blockableObject(getX(), getY() - 1)) {
        moveTo(getX(), getY() - 2);
    }
    //to the right
    if (getDirection() == 0) {
        if (getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 2, getY())
            && getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 1, getY())) {
            setState(false);
            return;
        }
        else {
            moveTo(getX() + 2, getY());
        }
    }
    //to the left
    if (getDirection() == 180) {
        if (getWorld()->blockableObject(getX() - 2, getY())
            && getWorld()->blockableObject(getX() - 1, getY())) {
            setState(false);
            return;
        }
        else {
            moveTo(getX() - 2, getY());
        }
    }
}

void Projectile::doSomething() {
    //damaged an actor
    if (causeDamage()) {
        setState(false);
        return;
    }
    move();
    
}

//Piranha Fireball class implementation
PiranhaFireball::PiranhaFireball(StudentWorld * sw, int x, int y, int dir) : Projectile(sw, x, y, IID_PIRANHA_FIRE, dir)
{
}

bool PiranhaFireball::causeDamage() {
    if (getWorld()->overlap(this, getWorld()->getPeach())) {
        getWorld()->getPeach()->bonk();
        return true;
    }
    return false;
}

//Peach Fireball class implementation
PeachFireball::PeachFireball(StudentWorld * sw, int x, int y, int dir) : Projectile(sw, x, y, IID_PEACH_FIRE, dir)
{
}

bool PeachFireball::causeDamage() {
    Actor * n;
    if (getWorld()->damagableObject(getX(), getY(), n)) {
        n->bonk();
        return true;
    }
    return false;
}

void PeachFireball::move() {
    //move down
    if (!(getWorld()->blockableObject(getX(), getY() - 2))
        && !(getWorld()->blockableObject(getX(), getY() - 1))) {
        moveTo(getX(), getY() - 2);
    }
    //to the right
    if (getDirection() == 0) {
        if (getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 2, getY())
            && getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 1, getY())) {
            setState(false);
            return;
        }
        else {
            cout << "Fireball: (" << getX() << ", " << getY() << ")" << endl;
            moveTo(getX() + 2, getY());
        }
    }
    //to the left
    if (getDirection() == 180) {
        if (getWorld()->blockableObject(getX() - 2, getY())
            && getWorld()->blockableObject(getX() - 1, getY())) {
            setState(false);
            return;
        }
        else {
            moveTo(getX() - 2, getY());
        }
    }
}

//Shell class implementation
Shell::Shell(StudentWorld * sw, int x, int y, int dir) : Projectile(sw, x, y, IID_SHELL, dir)
{
}

bool Shell::causeDamage() {
    Actor * n;
    if(getWorld()->damagableObject(getX(), getY(), n)) {
        n->bonk();
        return true;
    }
    return false;
}

void Shell::move() {
    //to the right
    if (getDirection() == 0) {
        if (getWorld()->blockableObject(getX() + SPRITE_WIDTH + 1, getY())
            && getWorld()->blockableObject(getX() + SPRITE_WIDTH, getY())) {
            setState(false);
            return;
        }
        else {
            moveTo(getX() + 2, getY());
        }
    }
    //to the left
    if (getDirection() == 180) {
        if (getWorld()->blockableObject(getX() - 2, getY())
            && getWorld()->blockableObject(getX() - 1, getY())) {
            setState(false);
            return;
        }
        else {
            moveTo(getX() - 2, getY());
        }
    }
}


//Monster class implementation
Monster::Monster(StudentWorld * sw, int x, int y, int ID) : Actor(sw, x, y, ID, 1, true) {
    int randomize = randInt(0, 180);
    if (randomize == 1)
        setDirection(180);
    else
        setDirection(0);
}

void Monster::doSomething() {
    //return if not alive
    if (!getState())
        return;
    
    if (getWorld()->overlap(this, getWorld()->getPeach())) {
        getWorld()->getPeach()->bonk();
        return;
    }
    move();
}

void Monster::move() {
    if (getDirection() == 0) {
        if (!getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 1, getY())
            && getWorld()->blockableObject(getX() + SPRITE_WIDTH - 1 + 1, getY() - 1)) {
            moveTo(getX() + 1, getY());
        }
        else
            setDirection(180);
    }
    else if (getDirection() == 180) {
        if (!getWorld()->blockableObject(getX() - 1, getY())
            && getWorld()->blockableObject(getX() - 1, getY() - 1))
            moveTo(getX() - 1, getY());
        else
            setDirection(0);
    }
}

void Monster::bonk() {

    //Damaged by Peach with invincibility
    if (getWorld()->overlap(this, getWorld()->getPeach())) {
        getWorld()->playSound(SOUND_PLAYER_KICK);
    }
    //damaged by Peach fireball
    getWorld()->increaseScore(100);
    setState(false);
}

//Goomba class implementation
Goomba::Goomba(StudentWorld * sw, int x, int y) : Monster(sw, x, y, IID_GOOMBA)
{
}

//Koopa class implementation
Koopa::Koopa(StudentWorld * sw, int x, int y) : Monster(sw, x, y, IID_KOOPA)
{
}

void Koopa::bonk() {
    //Damaged by Peach with invincibility
    if (getWorld()->overlap(this, getWorld()->getPeach()))
            getWorld()->playSound(SOUND_PLAYER_KICK);
    getWorld()->increaseScore(100);
    Shell * s = new Shell(getWorld(), getX(), getY(), getDirection());
    getWorld()->addActor(s);
    setState(false);
}

//Piranha class implementation
Piranha::Piranha(StudentWorld * sw, int x, int y) : Monster(sw, x, y, IID_PIRANHA), m_firing_delay(0)
{
}

void Piranha::doSomething() {
    if (!getState())
        return;
    
    increaseAnimationNumber();
    
    //overlaps with Peach
    if (getWorld()->overlap(this, getWorld()->getPeach())) {
        getWorld()->getPeach()->bonk();
        return;
    }
    //Peach not in range
    if (!(getWorld()->getPeach()->getY() <= 1.5 * SPRITE_HEIGHT + getY())
        || !(getWorld()->getPeach()->getY() >= getY() - (1.5 * SPRITE_HEIGHT))) {
        return;
    }
    //setting direction to face Peach
    if (getWorld()->getPeach()->getX() > getX())
        setDirection(0);
    else if (getWorld()->getPeach()->getX() < getX())
        setDirection(180);
    
    //checking if it can fire or not
    if (m_firing_delay > 0) {
        m_firing_delay--;
        return;
    }
    //checking if Peach is in range
    //peach is on the right
    if (getDirection() == 0) {
        if (getWorld()->getPeach()->getX() < getX() + (8 * SPRITE_WIDTH)) {
            PiranhaFireball * p = new PiranhaFireball(getWorld(), getX(), getY(), getDirection());
            getWorld()->addActor(p);
            getWorld()->playSound(SOUND_PIRANHA_FIRE);
            m_firing_delay = 40;
        }
    }
    //peach is on the left
    if (getDirection() == 180) {
        if (getWorld()->getPeach()->getX() > getX() - (8 * SPRITE_WIDTH)) {
            PiranhaFireball * p = new PiranhaFireball(getWorld(), getX(), getY(), getDirection());
            getWorld()->addActor(p);
            getWorld()->playSound(SOUND_PIRANHA_FIRE);
            m_firing_delay = 40;
        }
    }
}
