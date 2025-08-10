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
        Deck(int gamemode);  
        ~Deck();  
        // methods
        void shuffle();
        Card dealCard();
        void resetDeck(int gamemode);
        void dealHand(std::list<Player>& players, int amountofcards);
        void emptyDeck();
    private:
        //properties
        std::list<Card> _deck;
        bool _limitJoker;
};  

#endif // DECK_H
