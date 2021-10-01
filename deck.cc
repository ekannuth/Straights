#include "deck.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

void Deck::makeDeck(){
	Suit suits[4] = { CLUB, DIAMOND, HEART, SPADE };
	Rank ranks[13] = { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE, TEN, JACK, QUEEN, KING };
	for (int i = 0; i < 4; i++) {
		// go through the 4 suits
		for (int j = 0; j < 13; j++) {
			// 13 ranks per suit
			cards.push_back(Card(ranks[j],suits[i]));
		}
	}	
}


Card Deck::getCard(int x1){
	return cards[x1];
}

void Deck::setSeed(unsigned int seed) { new_seed = seed; }

void Deck::shuffle() {
    std::default_random_engine rng{ new_seed };
	for ( int i = 0; i < 1000; i++ ) {
		std::shuffle(cards.begin(), cards.end(), rng );		
	}
}



