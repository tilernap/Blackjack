//Blackjack program classes
//Tyler Knapp
//Last Updated: 1/24/2017

#pragma once
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<vector>


using namespace std;


class card
{
	//Properties:
private:
	int value;
	int index;
	string number;
	string suit;
	string appearence = number + " of " + suit;

public:
	//Constructor
	card()
	{
		if (value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9 || value == 10)
		{
			number = to_string(value);
		}

	}

	//Actions:
	void set_value(int new_value)
	{
		value = new_value;
		if (value == 2 || value == 3 || value == 4 || value == 5 || value == 6 || value == 7 || value == 8 || value == 9 || value == 10)
		{
			number = to_string(value);
		}
		if (value == 1)
		{
			number == "A";
		}
		if (value == 11)
		{
			number = "J";
		}
		if (value == 12)
		{
			number == "Q";
		}
		if (value == 13)
		{
			number == "K";
		}
	}

	int get_value()
	{
		return value;
	}

	void set_index(int new_index)
	{
		index = new_index;
	}

	int get_index()
	{
		return index;
	}

	void set_number(string new_number)
	{
		number = new_number;
	}

	string get_number()
	{
		return number;
	}

	void set_suit(string new_suit)
	{
		number = new_suit;
	}

	string get_suit()
	{
		return suit;
	}

	void set_appearence(string new_appearence)
	{
		appearence = new_appearence;
	}

	string get_appearence()
	{
		return appearence;
	}

};


//Deck of cards
class deck
{
private:
	//Properties
	const int starting_number_of_cards = 52; //size of deck
	int current_number_of_cards; //How many cards are now in the deck
	vector<card> cards; //cards in the deck
						//Arrays used to translate int deck values to readable strings
	string suits[4] = { "Clubs","Spades","Diamonds","Hearts" };
	string ranks[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
public:
	//Constructor
	deck()
	{
		vector<int> card_index; //int values indexing cards
		vector<int> card_values; //vector containing values of cards
		vector<string> card_suits; //vector containing appearences of cards
		current_number_of_cards = starting_number_of_cards; //Setting numbner of cards to start at 52

								   //initializing index of deck
		for (int i = 0; i < starting_number_of_cards; i++)
		{
			card_index.push_back(i);
		}

		//initializing values of deck

		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= 13; j++)
			{
				card_values.push_back(j);
			}
		}


		string number;
		string suit;
		string value;

		//initializing appearences of deck
		//Returning string in form "'number' of 'suit'"
		for (int i = 0; i < starting_number_of_cards; i++)
		{
			suit = suits[i / 13];
			card_suits.push_back(value);
		}

		//setting up the deck full of cards with correct values
		card holder;
		for (int i = 0; i < starting_number_of_cards; i++)
		{
			holder.set_value(card_values[i]);
			holder.set_index(card_index[i]);
			holder.set_suit(card_suits[i]);
			cards.push_back(holder);
		}

	}

	//Actions:

	//Deals 1 card randomly, using numbered deck index
	card deal()
	{
		//Choosing card to deal
		srand(time(NULL));
		int num = rand() % cards.size();
		card dealt_card = cards[num];

		//Erasing drawn card from deck
		cards.erase(cards.begin() + (num - 1));

		return dealt_card;
	}

	void set_current_number_of_cards(int x)
	{
		current_number_of_cards = x;
	}
	int get_current_number_of_cards()
	{
		return current_number_of_cards;
	}
	
	int get_starting_number_of_cards()
	{
		return starting_number_of_cards;
	}


};


//A hand of cards
class hand
{
private:
	//Properties:
	vector<card> cards_held;
public:
	//Constructor:
	//(Dealing a new hand)
	hand()
	{

	}

	//Actions:
	card play_card(int num)
	{
		//Selecting card to be played
		card played = cards_held[num];
		//Deleting card from hand
		cards_held.erase(cards_held.begin() + (num - 1));
		//playing card
		return played;
	}

	void show_cards_held()
	{
		for (int i = 0; i < cards_held.size(); i++)
		{
			cout << cards_held[i].get_appearence() << endl;
		}
	}

	int get_total()
	{
		int total = 0;
		for (int i = 0; i < cards_held.size(); i++)
		{
			total += cards_held[i].get_value();
		}
		return total;
	}

	void add_card(deck current_deck)
	{
		cards_held.push_back(current_deck.deal());
	}
};


//Player
class player
{
private:
	//Properties:
	string name;
	int points;
	hand current_hand;
public:
	//Constructor:
	player()
	{
		points = 0;

	}
	//Actions:
	//Choosing a card to be played or moved.
	card choose(int choice)
	{
		return current_hand.play_card(choice);
	}

	void give_card(deck current_deck)
	{
		current_hand.add_card(current_deck);
	}

	int get_hand_total() //get total value of player's hand
	{
		return current_hand.get_total();
	}

	void show_current_hand()//shows players hand
	{
		current_hand.show_cards_held();
	}

	int get_points()//returns players points (chips ect...)
	{
		return points;
	}

	void set_name(string new_name) //Change player name
	{
		name = new_name;
	}

	string get_name() //get players name
	{
		return name;
	}

};
