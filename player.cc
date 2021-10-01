#include "player.h"
using namespace std;

void Player::fliptype(){
	type = true;
}

bool Player::gettype(){
	return type;
}

bool Player::checkvalid(){
	if (curr_cards.size() == 0){
		return false;
	}
	else {
		return true;
	}
}


// deals each player the required cards from x1 and x2 in the deck
void Player::dealCard(Deck d, const int x1, const int x2)
{
	int index = x1;
	while (index < x2)
	{
		curr_cards.push_back(d.getCard(index));
		starting_hand.push_back(d.getCard(index));
		index += 1;
	}
}

// boolean to determine which player has the seven of spades
bool Player::whoHasSS()
{
	int index = 0;
	int size = curr_cards.size();
	while (index < size)
	{
		Card c = curr_cards[index];
		if (c.getRank() == SEVEN && c.getSuit() == SPADE)
		{
			first_card = true;
			return true;
		}
		else
		{
			index += 1;
		}
	}
	return false;
}

//Player method to change/set the id of the player
void Player::setId(int val)
{
	id = val;
}

//gets the total score of the player
int Player::getTotalScore() const
{
	return new_score + old_score;
}

// returns: vector of discarded cards
vector<Card> Player::getDiscards() const
{
	return discards;
}

// returns: vector of player's current cards
vector<Card> Player::getcurr_cards() const
{
	return curr_cards;
}

// returns: vector of player's legal cards
vector<Card> Player::getlegal() const
{
	return legal_moves;
}



void Player::pushScore(int score)
{
	new_score += score;
}

// updates the legal moves vector to contain all legal moves from current hand
void Player::getLegalmoves(Table sample_table)
{
	int index = 0;
	int size = curr_cards.size();
	int table_size = sample_table.getPlayed().size();
	while (index < size)
	{
		if (table_size == 0 && (first_card == true))
		{
			Card ss_card(SEVEN, SPADE);
			legal_moves.push_back(ss_card);
			first_card = false;
			break;
		}
		int val = 0;
		int size2 = sample_table.getPlayed().size();
		while (val < size2)
		{
			if (curr_cards[index].getRank() == Rank::SEVEN)
			{
				if (haveCard(curr_cards[index]) == true)
				{
					val += 1;
				}
				else
				{
					legal_moves.push_back(curr_cards[index]);
					val += 1;
				}
			}
			if (
				((curr_cards[index].getRank() + 1 == sample_table.getPlayed()[val].getRank()) ||
				 (curr_cards[index].getRank() - 1 == sample_table.getPlayed()[val].getRank())) &&
				(curr_cards[index].getSuit() == sample_table.getPlayed()[val].getSuit()))
			{
				if (haveCard(curr_cards[index]) == true)
				{
					val += 1;
				}
				else
				{
					legal_moves.push_back(curr_cards[index]);
					val += 1;
				}
			}
			else
			{
				val += 1;
			}
		}
		index += 1;
	}
}

// goes through legal moves checking if I have the Card already
bool Player::haveCard(Card sample_card)
{
	int index = 0;
	int size = legal_moves.size();
	while (index < size)
	{
		if (legal_moves[index].getRank() == sample_card.getRank() && legal_moves[index].getSuit() == sample_card.getSuit())
		{
			return true;
		}
		else
		{
			index += 1;
		}
	}
	return false;
}

int Player::getPeeks(){
	return number_peeks;
}

void Player::noPeek(){
	number_peeks = number_peeks - 1;
}

void Player::printHand()
{
	int index = 0;
	int size = curr_cards.size();
	cout << "Your hand:";
	while (index < size)
	{
		cout << " ";
		printPlayCard2(curr_cards[index]);
		index += 1;
	}
	cout << endl;
	index = 0;
	size = legal_moves.size();
	cout << "Legal plays:";
	while (index < size)
	{
		cout << " ";
		printPlayCard2(legal_moves[index]);
		index += 1;
	}
	cout << endl;
}

void Player::printHand2()
{
	int index = 0;
	int size = curr_cards.size();
	cout << "This is the next player's hand:";
	while (index < size)
	{
		cout << " ";
		printPlayCard2(curr_cards[index]);
		index += 1;
	}
	cout << endl;
	index = 0;
	size = legal_moves.size();
	cout << "Legal plays:";
	while (index < size)
	{
		cout << " ";
		printPlayCard2(legal_moves[index]);
		index += 1;
	}
	cout << endl;
}


// check if card is in legal move
bool Player::checkCard(Card sample_card)
{
	int index = 0;
	int size = legal_moves.size();
	while (index < size)
	{
		if (sample_card.getRank() == legal_moves[index].getRank() && sample_card.getSuit() == legal_moves[index].getSuit())
		{
			return true;
		}
		else
		{
			index += 1;
		}
	}
	return false;
}



int Player::playCard(Card sample_card, Table &sample_table)
{
	if (sample_card.getRank() == SEVEN && sample_card.getSuit() == SPADE)
	{
		printPlayCard(sample_card);
		sample_table.pushTable(sample_card);
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		getLegalmoves(sample_table);
		return 1;
	}
	else if (checkCard(sample_card) == true)
	{
		printPlayCard(sample_card);
		sample_table.pushTable(sample_card);
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		getLegalmoves(sample_table);
		return 1;
	}
	else
	{
		return 0;
	}
}


//removes card passed in parameter from current hand
void Player::removeCardinHand(Card sample_card)
{
	int index = 0;
	int size = curr_cards.size();
	vector<Card> new_cards;
	while (index < size)
	{
		if (sample_card.getRank() == curr_cards[index].getRank() && sample_card.getSuit() == curr_cards[index].getSuit())
		{
			index += 1;
		}
		else
		{
			new_cards.push_back(curr_cards[index]);
			index += 1;
		}
	}
	curr_cards.clear();
	curr_cards = new_cards;
}

//removes card passed in parameter from legal move hand
void Player::removeCardinLegal(Card sample_card)
{
	int index = 0;
	int size = legal_moves.size();
	vector<Card> new_cards;
	while (index < size)
	{
		if (sample_card.getRank() == legal_moves[index].getRank() && sample_card.getSuit() == legal_moves[index].getSuit())
		{
			index += 1;
		}
		else
		{
			new_cards.push_back(legal_moves[index]);
			index += 1;
		}
	}
	legal_moves.clear();
	legal_moves = new_cards;
}

void Player::printPlayCard(Card sample_card)
{
	vector<string> suits = {"C", "D", "H", "S"};
	vector<string> ranks = {"A", "2", "3", "4", "5", "6",
							"7", "8", "9", "T", "J", "Q", "K"};
	cout << "Player " << id << " plays " << ranks[sample_card.getRank()] << suits[sample_card.getSuit()] <<"."<< endl;
}

void Player::printPlayCard2(Card sample_card)
{
	vector<string> suits = {"C", "D", "H", "S"};
	vector<string> ranks = {"A", "2", "3", "4", "5", "6",
							"7", "8", "9", "T", "J", "Q", "K"};
	cout << ranks[sample_card.getRank()] << suits[sample_card.getSuit()];
}

//discards a specific card from hand
void Player::discardCard(Card sample_card)
{
	int size = legal_moves.size();
	if (size == 0)
		{
			removeCardinLegal(sample_card);
			removeCardinHand(sample_card);
			discards.push_back(sample_card);
			pushScore(sample_card.getValue());
			cout << "Player " << id << " discards ";
			printPlayCard2(sample_card);
			cout << ".";
			cout<< endl;
		}
		else
		{

		}
}

void Player::clearFields()
{
	discards.clear();
	curr_cards.clear();
	legal_moves.clear();
	new_score = 0;
}

bool Player::checkAdvanced(){
	return advanced_type;
}

bool Player::checkCurrentHand(Card sample_card){
	int index = 0;
	int size = curr_cards.size();
	while (index < size)
	{
		if ((sample_card.getRank() == curr_cards[index].getRank() 
		&& sample_card.getSuit() == curr_cards[index].getSuit()) && legal_moves.size() == 0)
		{
			return true;
		}
		else
		{
			index += 1;
		}
	}
	return false;
}

void Player::printStartingHand(){
	int index = 0;
	int size = starting_hand.size();
	while (index < size){
		printPlayCard2(starting_hand[index]);
		cout << " ";
		index += 1;
	}
}

void Player::setOldscore(){
	old_score = new_score + old_score;

}


void Player::printDiscard(){
	int index = 0;
	int size = discards.size();
	cout << "Player" << "<" << id << ">'s " << "discards:";
	while (index < size)
	{
		cout << " ";
		printPlayCard2(discards[index]);
		index += 1;
	}
	cout << endl;
	cout << "Player" << "<" << id << ">'s " << "score: ";
	int final_score = old_score + new_score;
	cout << old_score << " + " << new_score << " = " << final_score << endl;
}


int Player::playCard2(Table &sample_table)
{
    int size = legal_moves.size();
    if (size != 0){
        Card sample_card = legal_moves.at(0);
        printPlayCard(sample_card);
		sample_table.pushTable(sample_card);
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		getLegalmoves(sample_table);
		return 1;
    }
	else
	{
		Card sample_card = curr_cards[0];
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		discards.push_back(sample_card);
		pushScore(sample_card.getValue());
		cout << "Player " << id << " discards ";
		printPlayCard2(sample_card);
		cout << ".";
		cout << endl;
		return 0;
	}
}


int Player::playCard3(Table &sample_table)
{
    int size = legal_moves.size();
    if (size != 0){
        Card sample_card = legal_moves.at(0);
		int index2 = 1;
		while (index2 < size){
			if (legal_moves[index2].getRank() > sample_card.getRank()){
				sample_card = legal_moves[index2];
			}
			else {
				index2 +=1;
			}
		}
        printPlayCard(sample_card);
		sample_table.pushTable(sample_card);
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		getLegalmoves(sample_table);
		return 1;
    }
	else
	{
		Card sample_card = curr_cards[0];
		int index = 1;
		int curr_size = curr_cards.size();
		while (index < curr_size){
			if (curr_cards[index].getRank() < sample_card.getRank()){
				sample_card = curr_cards[index];
			}
			else {
				index +=1;
			}
		}
		removeCardinLegal(sample_card);
		removeCardinHand(sample_card);
		discards.push_back(sample_card);
		pushScore(sample_card.getValue());
		cout << "Player " << id << " discards ";
		printPlayCard2(sample_card);
		cout << ".";
		cout << endl;
		return 0;
	}
}
