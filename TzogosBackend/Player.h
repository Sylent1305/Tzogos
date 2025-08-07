#pragma once  
#ifndef PLAYER_H  
#define PLAYER_H  

#define HAND_SIZE 7 
#define HAND_ONBOARD_SIZE 2

#include "Card.h"
#include "Exception.h"
#include <array>  
#include <string>  

class Player  
{  
   public:  
	   Player();
       Player(std::string name,std::string passwrd);
       ~Player();  

       //methods  
       void addCard(const Card& card);
       void clearHand();
       std::array<Card, HAND_SIZE> getHand() const;
       int getScore() const;
       void setScore(int score);
	   int getChips() const;
	   void setChips(int chips);
	   void addChips(int chips);
	   void removeChips(int chips);
	   std::string toString() const;
	   std::string getName() const;
	   void setName(const std::string& name);
	   // Overloaded operators
	   bool operator==(const Player& other) const;
	   bool operator!=(const Player& other) const;
       std::string getUUID() const;
	   std::string getPassword() const;
       void setPassword(const std::string& passwrd);
       int calculateScore();

   private:  
       //properties  
       std::string _uuid;
       std::string _name;
       std::string _passwrd;
       std::array<Card, HAND_SIZE> _hand;  
	   std::array<Card, HAND_SIZE> _handOnTable; // cards on the table for this player
       int _score;  
       int _chips;
};  

#endif // PLAYER_H