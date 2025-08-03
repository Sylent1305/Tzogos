#pragma once  
#ifndef DECK_H  
#define DECK_H  

#include <list>  
#include <algorithm>
#include <random>    

#include "Card.h"

class Deck  
{  
   public:  
        // Constructor and Destructor
        Deck();  
        ~Deck();  

    private:
        // methods
        void shuffle();
        Card dealCard();
        void resetDeck();
        void dealRound(std::list<Player> players,int amountofcards, bool isfinalround);

        //properties
        std::list<Card> deck;
};  

#endif
