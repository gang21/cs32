#include "Actor.h"
#include "StudentWorld.h"

//Actor class implementation

//constructor
Actor::Actor(int x, int y, int ID, int dir, int depth, int size, bool state) : GraphObject(ID, x, y)
{
    m_x = x;
    m_y = y;
    m_imageID = ID;
    m_direction = dir;
    m_depth = depth;
    m_size = size;
    m_state = state;
}

//Block class implementation
Block::Block(int x, int y, int goodie) : Actor(x, y, IID_BLOCK, 0, 2, 1, true) {
    m_goodie = goodie;
}
