//Returns the optimal play according to basic strategy with one deck

#pragma once
#include<vector>
#include"Classes.h"

//p1=players 1st card
//p2=players 2nd card
//d=dealers up card


//The idea: store string values in a large matrix. Use user cards as indices.
//Dealer upcard are row headings: 2-A
//Player total row headings: 17+-5, A9-A2, AA88-22

//image of chart used
//http://www.blackjackclassroom.com/single-deck-basic-strategy.png
string OptimalPlay(card p1, card p2, card d)
{
	string s = "stay";
	string h = "hit";
	string d = "double";
	string sp = "split";

	//matrix holding chart values
	vector<vector<string>> chart;
	

}

