// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// mario header file
// reference Mario.cpp

#if !defined(MARIO_H)
#define MARIO_H
#include <string>

class Mario {
    public:
        Mario(); // default contructor
        Mario(Input* in, Levels* lev); // overload constructor
        ~Mario(); // default destructor
        Input* input; // pointer to input
        Levels* levels; // pointer to levels
        std::string move(); // move function
        std::string turn(); // turn function
        int mRow; // row mario is on
        int mColumn; // column mario is on
        int power; // mario's power level
        int lives; // how many lives mario has
        int coins; // how many coins mario has
        int direction; // random direction mario will go
        char grab; // gets the char mario lands on
        int currLevel; // current level
        int winChance; // random chance to win against goomba, koopa, or boss
        int kills; // mario's kills on current life
        bool bossWin; // did mario defeat the boss
        bool won; // did mario win the game
};
#endif
