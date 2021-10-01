#include "controller.h"
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <istream>
 

void Controller::updateSeed(unsigned int val){
	seed = val;
}


void Controller::clearindex(){
	index = 0;
}


void Controller::increment(int &val){
	if (val == 3){
		val = 0;
	}
	else {
		val += 1;
	}
}

void Controller::newTable(){
	sample_table.clearTable();
}

void Controller::setRagequit(){
	if (index == 0){
		first_player.fliptype();
	}
	else if (index == 1){
		second_player.fliptype();
	}
	else if (index == 2){
		third_player.fliptype();
	}
	else {
		fourth_player.fliptype();
	}
}

bool Controller::checkRagequit(){
	if (index == 0){
		return first_player.gettype();
	}
	else if (index == 1){
		return second_player.gettype();
	}
	else if (index == 2){
		return third_player.gettype();
	}
	else {
		return fourth_player.gettype();
	}
}

bool Controller::checkadvance(){
	if (index == 0){
		return first_player.checkAdvanced();
	}
	else if (index == 1){
		return second_player.checkAdvanced();
	}
	else if (index == 2){
		return third_player.checkAdvanced();
	}
	else {
		return fourth_player.checkAdvanced();
	}
}

bool Controller::checkPlayer(Card new_card){
	if (index == 0){
		return first_player.checkCard(new_card);
	}
	else if (index == 1){
		return second_player.checkCard(new_card);
	}
	else if (index == 2){
		return third_player.checkCard(new_card);
	}
	else {
		return fourth_player.checkCard(new_card);
	}
}

void Controller::peek(){
	if (index == 0){
		second_player.printHand2();
	}
	else if (index == 1){
		return third_player.printHand2();
	}
	else if (index == 2){
		return fourth_player.printHand2();
	}
	else {
		return first_player.printHand2();
	}
}

bool Controller::checkDiscard(Card new_card){
	if (index == 0){
		return first_player.checkCurrentHand(new_card);
	}
	else if (index == 1){
		return second_player.checkCurrentHand(new_card);
	}
	else if (index == 2){
		return third_player.checkCurrentHand(new_card);
	}
	else {
		return fourth_player.checkCurrentHand(new_card);
	}
}


void Controller::playPrint(){
	if (index == 0){
		first_player.printHand();
	}
	else if (index == 1){
		second_player.printHand();
	}
	else if (index == 2){
		third_player.printHand();
	}
	else {
		fourth_player.printHand();
	}
}

void Controller::minuspeek(){
	if (index == 0){
		first_player.noPeek();
	}
	else if (index == 1){
		second_player.noPeek();
	}
	else if (index == 2){
		third_player.noPeek();
	}
	else {
		fourth_player.noPeek();
	}
}

int Controller::returnpeek(){
	if (index == 0){
		return first_player.getPeeks();
	}
	else if (index == 1){
		return second_player.getPeeks();
	}
	else if (index == 2){
		return third_player.getPeeks();
	}
	else {
		return fourth_player.getPeeks();
	}
}

int Controller::playPlayer(Card new_card){
	if (index == 0){
		return first_player.playCard(new_card, sample_table);
	}
	else if (index == 1){
		return second_player.playCard(new_card, sample_table);
	}
	else if (index == 2){
		return third_player.playCard(new_card, sample_table);
	}
	else {
		return fourth_player.playCard(new_card, sample_table);
	}
}

int Controller::playPlayer2(){
	if (index == 0){
		return first_player.playCard2(sample_table);
	}
	else if (index == 1){
		return second_player.playCard2(sample_table);
	}
	else if (index == 2){
		return third_player.playCard2(sample_table);
	}
	else {
		return fourth_player.playCard2(sample_table);
	}
}

int Controller::playPlayer3(){
	if (index == 0){
		return first_player.playCard3(sample_table);
	}
	else if (index == 1){
		return second_player.playCard3(sample_table);
	}
	else if (index == 2){
		return third_player.playCard3(sample_table);
	}
	else {
		return fourth_player.playCard3(sample_table);
	}
}



void Controller::playDiscard(Card new_card){
	if (index == 0){
		first_player.discardCard(new_card);
	}
	else if (index == 1){
		second_player.discardCard(new_card);
	}
	else if (index == 2){
		third_player.discardCard(new_card);
	}
	else {
		fourth_player.discardCard(new_card);
	}
}



void Controller::dolegal(){
	if (index == 0){
		second_player.getLegalmoves(sample_table);
		third_player.getLegalmoves(sample_table);
		fourth_player.getLegalmoves(sample_table);
	}
	else if (index == 1){
		first_player.getLegalmoves(sample_table);
		third_player.getLegalmoves(sample_table);
		fourth_player.getLegalmoves(sample_table);
	}
	else if (index == 2){
		first_player.getLegalmoves(sample_table);
		second_player.getLegalmoves(sample_table);
		fourth_player.getLegalmoves(sample_table);
	}
	else {
		first_player.getLegalmoves(sample_table);
		second_player.getLegalmoves(sample_table);
		third_player.getLegalmoves(sample_table);
	}
}

void Controller::setupGame(){
	string answer1;
    string answer2;
    string answer3;
    string answer4;
	cout << "Is Player1 a human (h) or a computer (c)?" << endl << ">";
    cin >> answer1;
    while (!(answer1 == "h" || answer1 == "c")) {
        cout << "Please enter a valid player type. Is Player1 a human (h) or a computer (c)?" << endl << ">";
        cin >> answer1;
    }
    if (answer1 == "c"){
        setRagequit();
    }
    cout << "Is Player2 a human (h) or a computer (c)?" << endl << ">";
    cin >> answer2;
    while (!(answer2 == "h" || answer2 == "c")) {
        cout << "Please enter a valid player type. Is Player2 a human (h) or a computer (c)?" << endl << ">";
        cin >> answer2;
    }
    increment(index);
    if (answer2 == "c"){
        setRagequit();
    }
    cout << "Is Player3 a human (h) or a computer (c)?" << endl << ">";
    cin >> answer3;
    while (!(answer3 == "h" || answer3 == "c")) {
        cout << "Please enter a valid player type. Is Player3 a human (h) or a computer (c)?" << endl << ">";
        cin >> answer3;
    }
    increment(index);
    if (answer3 == "c"){
        setRagequit();
    }
    cout << "Is Player4 a human (h) or a computer (c)?" << endl << ">";
    cin >> answer4;
    while (!(answer4 == "h" || answer4 == "c")) {
        cout << "Please enter a valid player type. Is Player4 a human (h) or a computer (c)?" << endl << ">";
        cin >> answer4;
    }
    increment(index);
    if (answer4 == "c"){
        setRagequit();
    }
}	



//assuming the person with the 7 of spades just played it on to the table
void Controller::playGame()
{
	Deck my_deck;
	my_deck.setSeed(seed);
	my_deck.makeDeck();
	my_deck.shuffle();
	first_player.dealCard(my_deck, 0, 13);
	first_player.setId(1);

	second_player.dealCard(my_deck, 13, 26);
	second_player.setId(2);

	third_player.dealCard(my_deck, 26, 39);
	third_player.setId(3);

	fourth_player.dealCard(my_deck, 39, 52);
	fourth_player.setId(4);
	Table game_board;
	if (first_player.whoHasSS() == true)
	{
		cout << "A new round begins. It's Player 1's turn to play." << endl;
		first_player.getLegalmoves(game_board);
		second_player.getLegalmoves(game_board);
		third_player.getLegalmoves(game_board);
		fourth_player.getLegalmoves(game_board);
		index = 0;
	}
	else if (second_player.whoHasSS() == true)
	{
		cout << "A new round begins. It's Player 2's turn to play." << endl;
		second_player.getLegalmoves(game_board);
		third_player.getLegalmoves(game_board);
		fourth_player.getLegalmoves(game_board);
		first_player.getLegalmoves(game_board);
		index = 1;
	}
	else if (third_player.whoHasSS() == true)
	{
		cout << "A new round begins. It's Player 3's turn to play." << endl;
		third_player.getLegalmoves(game_board);
		fourth_player.getLegalmoves(game_board);
		first_player.getLegalmoves(game_board);
		second_player.getLegalmoves(game_board);
		index = 2;
	}
	else if (fourth_player.whoHasSS() == true)
	{
		cout << "A new round begins. It's Player 4's turn to play." << endl;
		fourth_player.getLegalmoves(game_board);
		first_player.getLegalmoves(game_board);
		second_player.getLegalmoves(game_board);
		third_player.getLegalmoves(game_board);
		index = 3;

	}
}

void Controller::printDeck(){
		first_player.printStartingHand();
		cout << endl;
		second_player.printStartingHand();
		cout << endl;
		third_player.printStartingHand();
		cout << endl;
		fourth_player.printStartingHand();
		cout << endl;
}

void Controller::printRagequit(){
	if (index == 0){
		cout << "Player 1 ragequits. A computer will now take over" << endl;
	}
	else if (index == 1){
		cout << "Player 2 ragequits. A computer will now take over" << endl;
	}
	else if (index == 2){
		cout << "Player 3 ragequits. A computer will now take over" << endl;
	}
	else {
		cout << "Player 4 ragequits. A computer will now take over" << endl;
	}
}

//player 4 played the last card which is a seven on spades
//player 1 is the first person to act
void Controller::Playround()
{
	while (true)
	{
		//check if reaches 80
	//	int table_size = sample_table.getPlayed().size();
		if (fourth_player.getTotalScore() >= 80 || first_player.getTotalScore() >= 80 
		|| second_player.getTotalScore() >= 80 || third_player.getTotalScore() >= 80)
		{
			break;
		}
		if (first_player.checkvalid() == false && second_player.checkvalid() == false 
			&& third_player.checkvalid() == false && fourth_player.checkvalid() == false){
			first_player.printDiscard();
			second_player.printDiscard();
			third_player.printDiscard();
			fourth_player.printDiscard();
			first_player.setOldscore();
			second_player.setOldscore();
			third_player.setOldscore();
			fourth_player.setOldscore();
			fourth_player.clearFields();
			first_player.clearFields();
			second_player.clearFields();
			third_player.clearFields();
			newTable();
			playGame();
			seed += 1;
			continue;
		}
		string command;
		string input;
		try {
			if (checkRagequit() == false){
				sample_table.printTable();
				playPrint();
				cin >> command;
			if (command == "quit"){
				type = true;
				break;
			}
			else if (command == "advanced"){
				setRagequit();
				cout <<"You just made the computer play advanced!"<<endl;
			}
			else if (command == "ragequit"){
				setRagequit();
				printRagequit();
			}
			else if (command == "peek"){
				if (returnpeek() >= 1){
					minuspeek();
					cout <<"Right now you are peeking into the next player's hand. Make a smart choice!" << endl;
					peek();
					throw InvalidPeekException{};
				}
				else {
					cout << "You already peeked too many times." << endl;
					throw InvalidPeekException{};
				}
			}
			else if (command == "deck"){
				printDeck();
				throw InvalidDeckException{};
			}
			else {
				cin >> input;
				}
			}
			if (command == "deck"){
				printDeck();
				throw InvalidDeckException{};
			}
			if (command != "play" && command != "discard" && 
			command != "quit" && checkRagequit() == false)
			{
				throw InvalidCommandException{};
			}
			Card c;
			if (checkRagequit() != true){
				new_card = c.makeCard(input);
			}
			if (command == "play" || checkRagequit() == true){
					if (checkPlayer(new_card) == false && command == "play"){
						throw InvalidValueException{};
					}
					else {
						if (checkRagequit() == true){
							if (command == "advanced"){
								playPlayer3();
								dolegal();
								increment(index);
							}
							else {
							playPlayer2();
							dolegal();
							increment(index);
							}
						}
						else {
						playPlayer(new_card);
						dolegal();
						increment(index);
						}
					}
			}
			else if (command == "discard"){
				if (checkDiscard(new_card) == true){
					playDiscard(new_card);
					increment(index);
				}
				else {
					throw InvalidDiscardException2{};
				}
			}
			else if (command == "quit"){
				break;
			}
		}
		catch (InvalidPeekException &i){
			continue;
		}
		catch (InvalidDeckException &i){
			continue;
		}
		catch (InvalidValueException &i){
		cout << "This Card is not in your legal plays. Please play another card" << endl;
		}
		catch (InvalidCommandException &i)
		{
			cout << "Invalid command! Please enter a valid command." << endl;
			continue;
		}
		catch (InvalidDiscardException &i)
		{
			cout << "You have a legal play. You may not discard" << endl;
		}
		catch (InvalidDiscardException2 &i)
		{
			cout << "This card is not in your hand. Please discard another card." << endl;
		}
	}
	if (type != true){
	first_player.printDiscard();
	second_player.printDiscard();
	third_player.printDiscard();
	fourth_player.printDiscard();
	vector<int> final_scores{0,0,0,0};
    final_scores.at(0) = first_player.getTotalScore();
    final_scores.at(1) = second_player.getTotalScore();
    final_scores.at(2) = third_player.getTotalScore();
    final_scores.at(3) = fourth_player.getTotalScore();
    auto it = min_element(begin(final_scores), end(final_scores));
    int lowestScore = *it;
    for (unsigned int i = 0; i < 4; ++i) {
        if (final_scores.at(i) == lowestScore) {
			if (i == 0){
				cout << "Player1" << " wins!" << endl;
			}
			else if (i == 1){
				cout << "Player2" << " wins!" << endl;
			}
			else if (i == 2){
				cout << "Player3" << " wins!" << endl;
			}
			else if (i ==3){
				cout << "Player4" << " wins!" << endl;
			}
        }
   	 }
	}
}


