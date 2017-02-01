//Dealer logic
#include "Classes.h"
#include<iostream>
#include<vector>


char DealerLogic(card up, card down)
{
	int total = up.get_value() + down.get_value();
	bool aces = false; //does the dealer have an ace
					   //checking
	if (up.get_value == 1 || down.get_value == 1)
	{
		aces == true;
	}

	//dealer hits less than 17
	if (total<17)
	{
		return 'h';
	}
	//dealer hits on soft 17
	if (total == 17 && aces == true)
	{
		return 'h';
	}
	//dealer stays on hard 17
	if (total == 17 && aces == false)
	{
		return 's';
	}
	//dealer stays everywhere else
	else
	{
		return 's';
	}
}
