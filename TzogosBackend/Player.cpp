#include "Player.h"


Player::Player()
{
	score = 0;
}
Player::~Player()
{
	// destructor is not needed
}

bool isEmpty(const Card& card)
{
	return card.getValue() == EMPTY && card.getSuit() == NONE;
}

void Player::addCard(const Card& card)
{
	for (int i = 0; i < HAND_SIZE; ++i) {
		if (isEmpty(hand[i])) 
		{ // find an empty slot in the hand
			hand[i] = card; // add the card to the hand
			return; // exit after adding the card
		}
	}
	throw HandFullException(); // if no empty slot found, throw an exception
	
}

void Player::clearHand()
{
	for (int i = 0; i < HAND_SIZE; ++i) {
		hand[i] = Card(); // fill hand with empty cards 
	}
}

std::array<Card, HAND_SIZE> Player::getHand() const
{
	return std::array<Card, HAND_SIZE>();
}

int Player::getScore() const
{
	return this->score;
}

void Player::setScore(int score)
{
	if (score < 0) {
		throw InvalidCardValueException(); // score cannot be negative
	}
	this->score = score; // set the score
}

