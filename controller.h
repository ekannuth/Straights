#include "player.h"
#include "table.h"
#include <vector>

class InvalidCommandException{};
class InvalidDiscardException{};
class InvalidDeckException{};
class InvalidDiscardException2{};
class InvalidPeekException{};

class Controller {
    Player first_player;
    Player second_player;
    Player third_player;
    Player fourth_player;
    Table sample_table;
    Card new_card;
    bool type = false;
    unsigned int seed = 0;
    int index = 0;
    public:
    void newTable();
    int getindex();
    void clearindex();
    void updateSeed(unsigned int val);
    void setupGame();
    void playGame();
    int returnpeek();
    void minuspeek();
    void playCard(Card sample_card, Table &sample_table, 
					Player &player_2);
    bool checkPlayer(Card new_card);
    bool checkadvance();
    bool checkDiscard(Card new_card);
    void Playround();
    void setRagequit();
    bool checkRagequit();
    void peek();
    int playPlayer(Card new_card);
    int playPlayer2();
    int playPlayer3();
    void playDiscard2();
    void printRagequit();
    void playDiscard(Card new_card);
    void playPrint();
    void dolegal();
    void increment(int &val);
    void printWinner();
    void printDeck();
};
