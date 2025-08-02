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
       Deck();  
       ~Deck();  
       void shuffle();  
       Card dealCard(); 
       void resetDeck();  

   private:  
       std::list<Card> deck;
};  

#endif
