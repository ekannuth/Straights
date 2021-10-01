#include "table.h"
#include <algorithm>

using namespace std;


bool Table::myfunction (Card card1, Card card2){ return (card1.getRank() < card2.getRank());}

vector<Card> Table::sortCards(vector<Card>myVector) {
    sort(myVector.begin(), myVector.end(), myfunction);
    return myVector;
}


//adds Card into Vector of CLubs
void Table::addClubs(Card sample_card){
    Clubs.push_back(sample_card);
}


void Table::addDiamonds(Card sample_card){
    Diamonds.push_back(sample_card);
}


void Table::addHearts(Card sample_card){
    Hearts.push_back(sample_card);
}
    

void Table::clearTable(){
    Clubs.clear();
    Diamonds.clear();
    Hearts.clear();
    Spades.clear();
    Played.clear();
}

void Table::pushTable(Card sample_card){
    if (sample_card.getSuit() == Suit::CLUB){
        addClubs(sample_card);
        Played.push_back(sample_card);
    }
    else if (sample_card.getSuit() == Suit::HEART){
        addHearts(sample_card);
        Played.push_back(sample_card);
    }
    else if (sample_card.getSuit() == Suit::SPADE){
        addSpades(sample_card);
        Played.push_back(sample_card);
    }
    else { // diamonds case
        addDiamonds(sample_card);
        Played.push_back(sample_card);
    }
}

void Table::addSpades(Card sample_card){
    Spades.push_back(sample_card);
}



vector<Card> Table::getPlayed() const {
    return Played;
}


vector<Card> Table::getClubs() const {
    return Clubs;
}


vector<Card> Table::getDiamonds() const {
    return Diamonds;
}


vector<Card> Table::getHearts() const {
    return Hearts;
}



vector<Card> Table::getSpades() const {
    return Spades;
}

void Table::printTable(){
    int index = 0;
    int size = getPlayed().size();
    cout <<"Cards on the table:" << endl;
    index = 0;
    size = Clubs.size();
    Clubs = sortCards(Clubs);
    cout <<"Clubs:";

    while (index < size){
        cout << " ";
        Clubs[index].printCard();
        index += 1;
    }
    cout << endl;
    index = 0;
    size = Diamonds.size();
    Diamonds = sortCards(Diamonds);
    cout <<"Diamonds:";
    while (index < size){
        cout << " ";
        Diamonds[index].printCard();
        index += 1;
    }
    cout << endl;
    index = 0;
    size = Hearts.size();
    Hearts = sortCards(Hearts);
    cout <<"Hearts:";
    while (index < size){
        cout << " ";
        Hearts[index].printCard();
        index += 1;
    }
    cout << endl;
    index = 0;
    size = Spades.size();
    Spades = sortCards(Spades);
    cout <<"Spades:";
    while (index < size){
        cout << " ";
        Spades[index].printCard();
        index += 1;
    }
    cout << endl;
}

