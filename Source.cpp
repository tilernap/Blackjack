//Blackjack program
//Tyler Knapp
//Last Updated: 8/26/2016

#include <iostream>
#include "Class.h"

using namespace std;

int main()
{
	cout << "Welcome to Tyler Knapp's Blackjack." << endl;

	cout << "What is your name?" << endl;
	player p1;
	string name;
	cin >> name;
	p1.set_name(name);
	cout << "Hello " << p1.get_name() << "." << endl;

	cout << "--------RULES---------" << endl;
	cout << "The game will be played with a single deck." << endl;
	cout << "Dealer will hit soft 17 and player cannot surrender." << endl;
	cout << "Player can split an unlimited number of times, but can only hit once while splitting Aces." << endl;



	return 0;
}
