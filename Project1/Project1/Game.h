//
//  game.h
//  Project1
//
//  Created by Gabriella Ang on 1/5/22.
//

#ifndef game_h
#define game_h

#include <stdio.h>
class Mesa;

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nGarks);
    ~Game();

        // Mutators
    void play();

  private:
    Mesa* m_mesa;
};

#endif /* game_h */
