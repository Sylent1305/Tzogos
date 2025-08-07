#pragma once  
#ifndef CARD_H  
#define CARD_H  
    
#include <string>

enum CardSuit
{
	NONE = 0, // for jokers and empty cards
	SPADES = 1,
	HEARTS = 2,
	DIAMONDS = 3,
	CLUBS = 4
};

enum CardValue
{
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	ACE = 14,
	JOKER = 0, // for jokers
	EMPTY = -1 // for empty cards
};

class Card
{
    public:
		//constructor and destructor
		Card(); //_suit(NONE), _value(EMPTY), _isjoker(false) 
		Card(bool isjoker); // _suit(NONE), _value(JOKER), _isjoker(true)
		Card(int suit, int value, bool isjoker = false);
        ~Card();

		//public methods
		int getSuit() const;
		int getValue() const;
		bool isJoker() const;
		void setSuit(int suit);
		void setValue(int value);
		void setIsJoker(bool isjoker);
		std::string toString() const;
		
		//copy constractor
		Card(const Card& other); //_suit(other.suit), _value(other.value), _isjoker(other.isjoker) {}

    private:
		//properties
		bool _isjoker;
	    int _suit; // look at enum declartion
	    int _value; // 2-14 (11=Jack, 12=Queen, 13=King, 14=Ace, 0=Joker)

};

#endif
