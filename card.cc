#include "card.h"
#include <string>
#include <vector>
using namespace std;




Card::Card(Rank r,Suit s){
    rank = r;
    suit = s;
}

// returns the associated suit with card
Suit Card::getSuit() const{
	return suit;
}

// returns the associated rank with card
Rank Card::getRank() const{
	return rank;
}

// returns: associated game point value for the card (rank + 1)
int Card::getValue() const
{
	return getRank() + 1;
}



//creates card from passed string in order to make card 
Rank Card::makeRank(string val){
	Rank r;
	char string1 = val.at(0);
	if ('A' == string1){
		r = Rank::ACE;
	}
	else if ('2' == string1){
		r = Rank::TWO;
	}
	else if ('3' == string1){
		r = Rank::THREE;
	}
	else if ('4' == string1){
		r = Rank::FOUR;
	}
	else if ('5' == string1){
		r = Rank::FIVE;
	}
	else if ('6' == string1){
		r = Rank::SIX;
	}
	else if ('7' == string1){
		r = Rank::SEVEN;
	}
	else if ('8' == string1){
		r = Rank::EIGHT;
	}
	else if ('9' == string1){
		r = Rank::NINE;
	}
	else if ('J' == string1){
		r = Rank::JACK;
	}
	else if ('Q' == string1){
		r = Rank::QUEEN;
	}
	else if ('K' == string1){
		r = Rank::KING;
	}
	//case where first character is 10
	else if ('T' == string1){
		r = Rank::TEN;
	}
	return r;
}

Suit Card::makeSuit(string val){
	Suit s;
	char string1 = val.at(1);
	if ('C' == string1){
		s = Suit::CLUB;
	}
	else if ('D' == string1){
		s = Suit::DIAMOND;
	}
	else if ('H' == string1){
		s = Suit::HEART;
	}
	else if ('S' == string1){
		s = Suit::SPADE;
	}
	return s;
}


Card Card::makeCard(string val){
	return Card(makeRank(val),makeSuit(val));
}

void Card::printCard(){
	vector<string> ranks = { "A", "2", "3", "4", "5", "6",
		"7", "8", "9", "T", "J", "Q", "K" };
	cout << ranks[getRank()];
}

