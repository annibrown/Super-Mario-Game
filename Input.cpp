// Annika Brown
// annbrown@chapman.edu
// Super Mario Game
// creates input object
// reads in from input file and stores it in variables in the input object

#include <iostream>
#include <fstream>
#include "Input.h"

// default contructor
Input::Input() {
}

// default destructor
Input::~Input() {
}

// inInput function
// @return void
void Input::inInput(std::string fileIn) {
    std::ifstream inFile(fileIn);
    line = 0;
    while (getline(inFile, fileText)) {
        line++;
        holder = stoi(fileText);
        if (line == 1) {
            L = holder;
        } else if (line == 2) {
            N = holder;
        } else if (line == 3) {
            V = holder;
        } else if (line == 4) {
            coins = holder;
        } else if (line == 5) {
            nothing = holder;
        } else if (line == 6) {
            goombas = holder;
        } else if (line == 7) {
            koopas = holder;
        } else if (line == 8) {
            mushrooms = holder;
        }
    }
    inFile.close();
    return;
}
