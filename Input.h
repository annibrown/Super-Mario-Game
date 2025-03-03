// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// input header file
// reference Input.cpp

#if !defined(INPUT_H)
#define INPUT_H
#include <string>

class Input {
    public:
        int L; // number of levels
        int N; // dimention of the grid
        int V; // number of initial lives
        int coins; // percentage of positions with coins in each level
        int nothing; // percentage of positions with nothing
        int goombas; // percentage of positions with goombas
        int koopas; // % positions w/koopas
        int mushrooms; // % positions w/mushrooms
        Input(); // default contructor
        ~Input(); // default destructor
        void inInput(std::string fileIn);
    private:
        std::string fileText;
        int holder;
        int line;
};
#endif
