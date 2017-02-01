//Blackjack program
//Tyler Knapp
//Last Updated: 8/26/2016

#include <iostream>
#include "Classes.h"
#include "OptimalPlay.h"

using namespace std;

int main()
{
	player p1; //player
	hand dealer; //dealer

	cout << "Welcome to Tyler Knapp's Blackjack." << endl;

	cout << "What is your name?" << endl;
	
	string name;
	cin >> name;
	p1.set_name(name);
	cout << "Hello " << p1.get_name() << "." << endl;
	cout << endl;

	//rules being used
	cout << "--------RULES---------" << endl;
	cout << "The game will be played with a single deck." << endl;
	cout << "Dealer will hit soft 17 and player cannot surrender." << endl;
	cout << "Player can split an unlimited number of times, but can only hit once while splitting Aces." << endl;
	system("pause");


	string userinput;//string to capture user input
	int bet; // used to capture player's bet
	string end; //to determine if user wants to leave for sure


	
	do //main game loop
	{
		deck useddeck;
		int threshold = .75;
		do //loop determines when a shuffle is needed
		{
			//Player bets before deal
			cout << "Current chips: $" << p1.get_points() << endl;
			cout << "Place your bet: ";
			cin >> bet;
			//Dealing cards to player and dealer
			cout << "Dealing..." << endl;
			for (int i = 0; i < 2; i++)
			{
				p1.give_card(useddeck);
				dealer.add_card(useddeck);
			}
			
			do //loop for player action, is presented with options
			{

			} while (p1.get_hand_total()<21);


		} while (useddeck.get_current_number_of_cards>(useddeck.get_starting_number_of_cards*.25));






		if (userinput == "exit")
		{
			cout << "Are you sure you want to exit? (y/n)" << endl;
			cin >> end;
		}
	} while (end!="y");

	cout << "You ended with " << p1.get_points << " dollars." << endl;
	cout << "Thanks for playing!" << endl;

	return 0;
}
