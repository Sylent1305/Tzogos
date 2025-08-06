#include "Card.h"


Card::Card()
{
}

Card::Card(bool isjoker)
{
}

Card::Card(int suit, int value, bool isjoker)
{
	_suit = suit;
	_value = value;
	_isjoker = isjoker;
}

Card::~Card()
{
	// Destructor does not need to do anything special for this class
}

std::string Card::toString() const
{
	if (_isjoker)
	{
		return "Joker";
	}
	std::string suitStr;
	switch (_suit)
	{
	case SPADES:   suitStr = "♠"; break;
	case HEARTS:   suitStr = "♥"; break;
	case DIAMONDS: suitStr = "♦"; break;
	case CLUBS:    suitStr = "♣"; break;
	default:       suitStr = ""; break;
	}
	std::string valueStr;
	if (_value >= TWO && _value <= TEN)
	{
		valueStr = std::to_string(_value); // For values 2-10, use the numeric value
	}
	else
	{
		switch (_value)
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

Card::Card(const Card& other)
{
	_suit = other._suit;
	_value = other._value;
	_isjoker = other._isjoker;
}

int Card::getSuit() const
{
	return _suit;
}

int Card::getValue() const
{
	return _value;
}

bool Card::isJoker() const
{
	return _isjoker;
}

void Card::setSuit(int suit)
{
	_suit = suit;
}

void Card::setValue(int value)
{
	_value = value;
}

