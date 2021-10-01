#include <vector>
#include "table.h"

#ifndef PLAYER
#define PLAYER


using namespace std;

class InvalidValueException{};

class Player {
protected:
	int new_score = 0; // total score for the round for given player
	int old_score = 0; // old score from previous played rpund
	vector<Card> discards; // list of discards for the player in the current round
	vector<Card> curr_cards; // list of cards on hand for the player in the current round
	vector<Card> starting_hand;
	vector<Card> legal_moves;
	bool first_card;
	int id;
	bool type = false;
	bool advanced_type = false;
	int number_peeks = 2;
public:
	Player(){}
	int getPeeks();
	void noPeek();
	void dealCard(Deck d, const int x1, const int x2); // adds a card c to current hand
	bool whoHasSS();  //returns true if seven spades is in hand
	Card returnSS();
	void setOldscore();
	bool checkvalid();
	void fliptype();
	bool gettype();
	bool checkAdvanced();
	void setId(int val);
	bool haveCard(Card sample_card);
	bool checkCard(Card sample_card); //checks if card is in deck
	void getLegalmoves(Table sample_table);
	void pushScore(int score);
	void PushCard(Card sample_card, Table sample_table); // pushes card into table
	void discardCard(Card sample_card);
	int getTotalScore() const;
	void removeCardinHand(Card sample_card);
	void removeCardinLegal(Card sample_card);
	void printPlayCard(Card sample_card);
	void printPlayCard2(Card sample_card);
	void printHand();
	void printHand2();
	void printStartingHand();
	void printDiscard();
	int playCard(Card sample_card, Table &sample_table);
	int playCard2(Table &sample_table);
	int playCard3(Table &sample_table);
	void clearFields();
	bool checkCurrentHand(Card sample_card);
	vector<Card> getDiscards() const; // returns list of discards
	vector<Card> getcurr_cards() const;
	vector<Card> getlegal() const;
	vector<Card> getPlayed_cards() const;
//	Card makeCard(string val);
};

#endif


/*
bool Table::myfunction (Card* card1, Card* card2) { return (card1->getRankNumber() < card2->getRankNumber()); }

std::vector<Card *> Table::sortList(std::vector<Card *>myVector) {
    std::sort(myVector.begin(), myVector.end(), myfunction);
    return myVector;
}
*/

