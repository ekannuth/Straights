#include <vector>
#include <string>
#include "deck.h"
#include <iostream>
using namespace std;

#ifndef TABLE
#define TABLE

class Table {
    private:
    vector<Card> Clubs;
    vector<Card> Diamonds;
    vector<Card> Hearts;
    vector<Card> Spades;
    vector<Card> Played;
    public:
    void clearTable();
    void pushSpade(); // pushSpade put the seven of spades in the played vector
    vector<Card> getPlayed() const;
    vector<Card> getClubs() const;
    vector<Card> getDiamonds() const;
    vector<Card> getHearts() const;
    vector<Card> getSpades() const;
    static bool myfunction (Card card1, Card card2);
    void helpPrint();
    vector<Card> sortCards(vector<Card>myVector); 
    void pushTable(Card sample_card);
    void addClubs(Card sample_card);
    void addDiamonds(Card sample_card);
    void addHearts(Card sample_card);
    void addSpades(Card sample_card);
    void printTable();
    void addCard();
};


#endif
