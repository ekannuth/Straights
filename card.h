#ifndef CARD
#define CARD
#include <iostream>
#include <string>

using namespace std;

enum Suit { CLUB, DIAMOND, HEART, SPADE};

// enum of possible ranks for cards
enum Rank {
	ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
	EIGHT, NINE, TEN, JACK, QUEEN, KING,
};


class Card {
    private:
        Rank rank;
        Suit suit;
    public:
        Card(){};
        Card(Rank rank,Suit suit);
        Suit getSuit() const;
        Rank getRank() const;
        int getValue() const;  /// scoring value of card
        Rank makeRank(string val);
        Suit makeSuit(string val);
        Card makeCard(string val);
        void printCard();
};



#endif
