#ifndef DECK
#define DECK
#include <iostream>
#include "card.h"
#include <vector>

using namespace std;



class Deck {
    private:
    vector<Card> cards;
    unsigned int new_seed;
    public:
        Deck(){}; // create the deck
        void makeDeck();
        void shuffle();
        Card getCard(int x1);
        void setSeed(unsigned int seed);
};



#endif
