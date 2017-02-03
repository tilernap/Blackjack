# Blackjack
Blackjack played in the console.


Classes.h
Holds the classes used in the blackjack program. Should be robust enough to be picked up and used in another card game, possibly hearts after this. Thinking of merging the "hand" and "player" classes, since it seems that it is an unnecessary abstraction.

OptimalPlay.h
Holds the function that sould return basic strategy values given the player's cards and the dealer's up card. The idea is to return a char value and house these in a large matrix that is accessed by the function. The indices of the matrix are determined by a chart found online.

DealerLogic.h
Holds the logic governing how the dealer must react to the cards infront of him. Not too crazy, just worried about handling aces.

Source.cpp
Where it all comes together with a menu and main game loop.
