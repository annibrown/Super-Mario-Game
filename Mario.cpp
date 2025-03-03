// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// creates mario
// move and turn functions

#include <iostream>
#include "Input.h"
#include "Levels.h"
#include "Mario.h"
using namespace std;

// mario default constructor
Mario::Mario() {
}

// mario overload constructor
Mario::Mario(Input* in, Levels* lev) {
    input = in;
    levels = lev;
    currLevel = 0;
    while(true) {
        mRow = rand() % input->N;
        mColumn = rand() % input->N;
        if(levels->levelArr[currLevel][mRow][mColumn] != 'w' && levels->levelArr[currLevel][mRow][mColumn] != 'b') {
            levels->levelArr[currLevel][mRow][mColumn] = 'H';
            break;
        }
    }
    power = 0;
    lives = input->V;
    coins = 0;
    kills = 0;
    won = false;
}

// mario default destructor
Mario::~Mario() {

}

// move function
// @return string moveText
std::string Mario::move() {
    std::string moveText = "";
    if (bossWin == false) {
        moveText += "Mario will stay put.\n";
    } else {
        if (grab == 'w'){
            moveText += "Mario will WARP.\n";
        } else {
            direction = rand() % 4;
            if (direction == 0) {
                if (mColumn == 0) {
                    mColumn = input->N - 1;
                } else {
                    mColumn = mColumn - 1;
                }
                moveText += "Mario will move LEFT.\n";
            } else if (direction == 1) {
                if (mRow == input->N - 1) {
                    mRow = 0;
                } else {
                    mRow = mRow + 1;
                }
                moveText += "Mario will move DOWN.\n";
            } else if (direction == 2) {
                if (mColumn == input->N - 1) {
                    mColumn = 0;
                } else {
                    mColumn = mColumn + 1;
                }
                moveText += "Mario will move RIGHT.\n";
            } else {
                if (mRow == 0) {
                    mRow = input->N - 1;
                } else {
                    mRow = mRow - 1;
                }
                moveText += "Mario will move UP.\n";
            }
        }
    }
    grab = levels->levelArr[currLevel][mRow][mColumn];
    levels->levelArr[currLevel][mRow][mColumn] = 'H';
    return moveText;
}

// turn function
// @ return string turnText
std::string Mario::turn() {
    std::string turnText = "";
    if (bossWin == false) {
        grab = 'b';
    }

    // lands on coin
    if (grab == 'c') {
        turnText += "Mario collected a coin. ";
        coins++;
        levels->levelArr[currLevel][mRow][mColumn] = 'x';

    // lands on nothing
    } else if (grab == 'x') {
        turnText += "Mario visited an empty space. ";
        levels->levelArr[currLevel][mRow][mColumn] = 'x';
    
    // lands on goomba
    } else if (grab == 'g') {
        winChance = rand() % 5;
        if (winChance == 0) {
            turnText += "Mario encountered a goomba and lost. ";
            if (power == 0) {
                lives--;
                kills = 0;
            } else {
                power--;
            }
            levels->levelArr[currLevel][mRow][mColumn] = 'g';
        } else {
            turnText += "Mario encountered a goomba and won. ";
            kills++;
            if (kills == 7) {
                lives++;
            }
            levels->levelArr[currLevel][mRow][mColumn] = 'x';
        }
    
    // lands on koopa
    } else if (grab == 'k') {
        winChance = rand() % 20;
        if (winChance >= 0 && winChance < 7) {
            turnText += "Mario encountered a koopa and lost. ";
            if (power == 0) {
                lives--;
                kills = 0;
            } else {
                power--;
            }
            levels->levelArr[currLevel][mRow][mColumn] = 'k';
        } else {
            turnText += "Mario encountered a koopa and won. ";
            kills++;
            if (kills == 7) {
                lives++;
            }
            levels->levelArr[currLevel][mRow][mColumn] = 'x';
        }

    // lands on mushroom
    } else if (grab == 'm') {
        turnText += "Mario ate a mushroom. ";
        if (power < 2) {
            power++;
        }
        levels->levelArr[currLevel][mRow][mColumn] = 'x';
    
    // landed on boss
    } else if (grab == 'b') {
        bossWin = false;
        winChance = rand() % 2;
        if (winChance == 0) {
            turnText += "Mario encountered a boss and lost. ";
            if (power < 2) {
                lives--;
                kills = 0;
            } else {
                power = power - 2;
            }
        } else {
            turnText += "Mario encountered a boss and won. ";
            bossWin = true;
            levels->levelArr[currLevel][mRow][mColumn] = 'x';
            if (currLevel == input->L - 1) {
                won = true;
            } else {
                currLevel++;
            }  
        }

    // lands on warp
    } else if (grab == 'w') {
        turnText += "Mario found a warp pipe. ";
        currLevel++;
        mRow = rand() % input->N;
        mColumn = rand() % input->N;
    }
    return turnText;
}
