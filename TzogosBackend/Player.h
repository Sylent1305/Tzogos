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
       Player& operator=(const Player& other);
       std::string getUUID() const;
	   std::string getPassword() const;
       void setPassword(const std::string& passwrd);
       int calculateScore();

       // Board helpers
       std::array<Card, HAND_ONBOARD_SIZE> getBoard() const;
       void setBoardCard(int index, const Card& card);
       void resetBoard();
       bool getBoardFaceUp(int index) const;
       void setBoardFaceUp(int index, bool faceUp);
       // Hand helpers
       void removeCardAt(int index);
       int findFirstNonEmptyIndex() const;

       //helper functions
       static bool isFlush(const std::array<Card, HAND_ONBOARD_SIZE>& hand);
       static bool isPair(const std::array<Card, HAND_ONBOARD_SIZE>& hand);
       static bool isStraight(const std::array<Card, HAND_ONBOARD_SIZE>& hand);
       static bool isSuitedPair(const std::array<Card, HAND_ONBOARD_SIZE>& hand);
       static bool isStraightFlush(const std::array<Card, HAND_ONBOARD_SIZE>& hand);


   private:  
       //properties  
       std::string _uuid;
       std::string _name;
       std::string _passwrd;
       std::array<Card, HAND_SIZE> _hand;  
	   std::array<Card, HAND_ONBOARD_SIZE> _handOnTable; // cards on the table for this player
       std::array<bool, HAND_ONBOARD_SIZE> _boardFaceUp;
       int _score;  
       int _chips;
};  

#endif // PLAYER_H