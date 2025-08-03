#pragma once  
#ifndef DECK_H  
#define DECK_H  

#include <list>  
#include <algorithm>
#include <random>    

#include "Card.h"
#include "Player.h"

class Deck  
{  
   public:  
        // Constructor and Destructor
        Deck();  
        ~Deck();  
        // methods
        void shuffle();
        Card dealCard();
        void resetDeck();
        void dealRound(std::list<Player> players, int amountofcards);
    private:
        //properties
        std::list<Card> deck;
};  

#endif
