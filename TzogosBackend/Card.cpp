#include "Card.h"


Card::Card(int suit, int value, bool isjoker)
{
	this->suit = suit;
	this->value = value;
	this->isjoker = isjoker;
}

Card::~Card()
{
	// Destructor does not need to do anything special for this class
}

std::string Card::toString() const
{
	if (isJoker)
	{
		return "Joker";
	}
	std::string suitStr;
	switch (suit)
	{
	case SPADES:   suitStr = "♠"; break;
	case HEARTS:   suitStr = "♥"; break;
	case DIAMONDS: suitStr = "♦"; break;
	case CLUBS:    suitStr = "♣"; break;
	default:       suitStr = ""; break;
	}
	std::string valueStr;
	if (value >= TWO && value <= TEN)
	{
		valueStr = std::to_string(value); // For values 2-10, use the numeric value
	}
	else
	{
		switch (value)
		{
		case JOKER:  valueStr = "Joker"; break;
		case JACK:   valueStr = "J"; break;
		case QUEEN:  valueStr = "Q"; break;
		case KING:   valueStr = "K"; break;
		case ACE:    valueStr = "A"; break;
		default:     valueStr = "Unknown Value"; break;
		}
	}
	return valueStr + suitStr;
}

int Card::getSuit() const
{
	return this->suit;
}

int Card::getValue() const
{
	return this->value;
}

bool Card::isJoker() const
{
	return this->isjoker;
}

void Card::setSuit(int suit)
{
	this->suit = suit;
}

void Card::setValue(int value)
{
	this->value = value;
}

