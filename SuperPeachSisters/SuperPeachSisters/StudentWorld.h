#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include <string>
#include <vector>
#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"

using namespace std;


// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp


class StudentWorld : public GameWorld
{
public:
    StudentWorld(string assetPath);
    ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    bool overlap(int x, int y, Actor* &character);
    bool overlap(Actor * a, Actor * b);
    bool blockableObject(int x, int y);
    bool damagableObject(int x, int y, Actor* &character);
    //mutators
    void setStatus(int status) {m_status = status;}
    //accessors
    int getStatus() {return m_status;}
    Peach* getPeach() {return player;}
    void addActor(Actor* a);
//    Actor* getActorAt(int x, int y);
    
private:
    Peach* player;
    vector<Actor*> actors;
    string levelFile;
    int m_status;
    
};
#endif // STUDENTWORLD_H_
