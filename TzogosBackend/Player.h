#pragma once  
#ifndef PLAYER_H  
#define PLAYER_H  

#define HAND_SIZE 7  

#include "Card.h"
#include "Exception.h"
#include <array>  
#include <string>  

class Player  
{  
   public:  
       Player();  
       ~Player();  

       //methods  
       void addCard(const Card& card);
       void clearHand();
       std::array<Card, HAND_SIZE> getHand() const;
       int getScore() const;
       void setScore(int score);

   private:  
       //properties  
       std::array<Card, HAND_SIZE> hand;  
       int score;  

};  

#endif // PLAYER_H