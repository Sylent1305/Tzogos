#pragma once  
#ifndef CARD_H  
#define CARD_H  
    
#include <string>

enum CardSuit
{
	NONE = 0, // for jokers
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
	JOKER = 0 // for jokers
};

class Card
{
    public:
		//constructor and destructor
		Card() : suit(NONE), value(JOKER), isjoker(true) {} // Default constructor for Joker
		Card(int suit, int value, bool isjoker = false);
        ~Card();

		//public methods
		std::string toString() const;

    private:
		//methods
		int getSuit() const;
		int getValue() const;
		bool isJoker() const;
		void setSuit(int suit);
		void setValue(int value);

		//properties
		bool isjoker;
	    int suit; // look at enum declartion
	    int value; // 2-14 (11=Jack, 12=Queen, 13=King, 14=Ace, 0=Joker)

};

#endif
