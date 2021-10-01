#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>
#include "deck.h"
#include "player.h"
#include "controller.h"

using namespace std;

int main(int argc, char**argv){
    unsigned int seed_value;
    if (argc > 2){
        cerr << "Too many arguments" << endl;
        exit(1);
    }
    if (argc == 2){
        seed_value = stoi(argv[1]);
    }
    Controller game;
    game.setupGame();
    game.clearindex();
    game.updateSeed(seed_value);
    game.playGame();
    game.Playround();
}
    
