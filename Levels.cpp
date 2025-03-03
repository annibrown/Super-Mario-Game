// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// creates 3d array, levels

#include <iostream>
#include "Input.h"
#include "Levels.h"

// default contructor
Levels::Levels() {
}

// overload constructor
Levels::Levels(Input* in) {
    input = in;
    initializeLevels();
}

// default destructor
Levels::~Levels() {
    delete[] levelArr;
}

// initializeLevels function
// creates a 3D array of all the levels and populates it with chars
// @return void
void Levels::initializeLevels() {
    levelArr = new char**[input->L];
    for (int a = 0; a < input->L; a++) {
        levelArr[a] = new char*[input->N];
        for (int b = 0; b < input->N; b++) {
            levelArr[a][b] = new char[input->N];
        }
    }

    if (input->coins + input->nothing + input->goombas + input->koopas + input->mushrooms == 100) {
        size = input->N*input->N;
        for (int x = 0; x < input->L; x++) {
            levelCreating++;
            for (int i = 0; i < input->N; i++) {
                for (int j = 0; j < input->N; j++) {
                    space = rand() % 100;
                    if (space >= 0 && space < input->coins) {
                        character = 'c';
                    } else if (space >= input->coins && space < (input->coins + input->nothing)) {
                        character = 'x';
                    } else if (space >= (input->coins + input->nothing) && space < (input->coins + input->nothing + input->goombas)) {
                        character = 'g';
                    } else if (space >= (input->coins + input->nothing + input->goombas) && space < (input->coins + input->nothing + input->goombas + input->koopas)) {
                    character = 'k';
                    } else if (space >= (input->coins + input->nothing + input->goombas + input->koopas) && space < 100) {
                        character = 'm';
                    }
                    levelArr[x][i][j] = character;
                }
            }
            bossA = rand() % input->N;
            bossB = rand() % input->N;
            levelArr[x][bossA][bossB] = 'b';
            if(levelCreating < input->L) {
                warpA = bossA;
                warpB = bossB;
                while (warpA == bossA && warpB == bossB) {
                warpA = rand() % input->N;
                warpB = rand() % input->N;
                }
                levelArr[x][warpA][warpB] = 'w';
            }
        }
    } else {
        std::cout << "percentages don't equal 100 :(" << std::endl;
    }
    return;
}
