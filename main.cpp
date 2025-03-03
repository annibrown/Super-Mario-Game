// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// runs the game using the other classes
// outputs to the file


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Input.h"
#include "Levels.h"
#include "Mario.h"
using namespace std;

//main method
int main(int argc, char* argv[]) {
    // set seed for random generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // pointer to input object
    Input* input = new Input();
    // calls inInput
    input->inInput(argv[1]);
    // pointer to levels object
    Levels* levels = new Levels(input);

    // opens output file
    std::ofstream outFS;
    outFS.open(argv[2]);
    // if output file is open it's very sad
    if (!outFS.is_open()) {
        std::cout << "Could not open file :(" << std::endl;
        return 1;
    }

    // print all levels
    for (int i = 0; i < input->L; i++) {
        for (int j = 0; j < input->N; j++) {
            for (int x = 0; x < input->N; x++){
                outFS << levels->levelArr[i][j][x];
            }
            outFS << std::endl;
        }
        outFS << "==========" << std::endl;
    }

    // pointer to mario object
    Mario* mario = new Mario(input, levels);
    bool won = false;
    // prints mario's coords
    outFS << "Mario is starting in position: (" << mario->mRow << "," << mario->mColumn << ")" << std::endl;
    outFS << "==========" << std::endl;
    // game while loop
    while (mario->lives > 0 && mario->won == false) {

        // print current level
        for (int i = 0; i < input->N; i++) {
            for (int j = 0; j < input->N; j++){
                outFS << levels->levelArr[mario->currLevel][i][j];
            }
            outFS << "\n";
        }
        outFS << "==========\n";

        // prints mario's stats
        outFS << "Level: " << mario->currLevel << ". Mario is at position : (" << mario->mRow << "," << mario->mColumn << "). Mario is at power level " << mario->power << ". ";
        outFS << mario->turn();
        outFS << "Mario has " << mario->lives << " lives left. Mario has " << mario->coins << " coins. ";
        outFS << mario->move();
        outFS << "==========\n";
    }

    // prints if mario wins or dies
    if (mario->won == true) {
        outFS << "WE BEAT THE GAME! :)";
    } else if (mario->lives == 0) {
        outFS << "Mario died and we lost :(";
    }

    // delete objects
    delete input;
    delete levels;
    delete mario;

    return 0;
}
