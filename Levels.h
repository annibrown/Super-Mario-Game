// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// levels header file
// reference Levels.cpp

#if !defined(LEVELS_H)
#define LEVELS_H
#include "Input.h"
#include <string>

class Levels {
    public:
        Levels(); // default contructor
        Levels(Input* in); // overload constructor
        ~Levels(); // default destructor
        Input* input; // pointer to input
        int space;
        char character;
        int size;
        int bossA;
        int bossB;
        int warpA;
        int warpB;
        int levelCreating = 0;
        char*** levelArr;
        void initializeLevels();
        void printLevels();
};
#endif
