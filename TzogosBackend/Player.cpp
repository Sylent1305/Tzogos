#include "Player.h"

#include <random>
#include <sstream>
#include <iomanip>
#include "Game.h"

// One-time RNG setup (thread-safe if needed)
static thread_local std::mt19937_64 gen(std::random_device{}());
static thread_local std::uniform_int_distribution<uint64_t> dis;

std::string generateUUID()
{
	uint64_t part1 = dis(gen);
	uint64_t part2 = dis(gen);

	part1 = (part1 & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;  // version 4
	part2 = (part2 & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;  // variant 1

	std::ostringstream oss;
	oss << std::hex << std::setfill('0')
		<< std::setw(8) << (uint32_t)(part1 >> 32) << "-"
		<< std::setw(4) << (uint16_t)(part1 >> 16) << "-"
		<< std::setw(4) << (uint16_t)(part1) << "-"
		<< std::setw(4) << (uint16_t)(part2 >> 48) << "-"
		<< std::setw(12) << (part2 & 0x0000FFFFFFFFFFFFULL);

	return oss.str();
}

Player::Player()
{
	_name = "Guest";
	_passwrd = "";
	_uuid = generateUUID();
	_score = 0;
	_chips = 0;
	clearHand();
}

Player::Player(std::string name, std::string passwrd)
{
	//add an implementaion in order to validate through db the name and password then pull chips from db
	_name = name; 
	_passwrd = passwrd;
	_uuid = generateUUID();
	_score = 0;
	_chips = 0;
	clearHand();
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
		if (isEmpty(_hand[i])) 
		{ // find an empty slot in the hand
			_hand[i] = card; // add the card to the hand
			return; // exit after adding the card
		}
	}
	throw HandFullException(); // if no empty slot found, throw an exception
	
}
//reset hand and hand on table of player
void Player::clearHand()
{
	for (int i = 0; i < HAND_SIZE; ++i) {
		_hand[i] = Card(); // fill hand with empty cards 
	}
	for (int i = 0; i < HAND_ONBOARD_SIZE; i++)
	{
		_handOnTable[i] = Card();
	}
}

std::array<Card, HAND_SIZE> Player::getHand() const
{
	return std::array<Card, HAND_SIZE>();
}

int Player::getScore() const
{
	return _score;
}

void Player::setScore(int score)
{
	if (score < 0) {
		throw InvalidCardValueException(); // score cannot be negative
	}
	_score = score; // set the score
}

int Player::getChips() const
{
	return _chips;
}

void Player::setChips(int chips)
{
	if (chips < 0) 
	{
		throw NegativeNumberException(); // chips cannot be negative
	}
	_chips = chips; 
}

void Player::addChips(int chips)
{
	_chips += chips; 
}

void Player::removeChips(int chips)
{
	if (_chips < chips)
	{
		throw MissingChipsException(); // not enough chips
	}
	_chips -= chips; 
}

std::string Player::toString() const
{
	std::ostringstream oss;
	oss << "Name: " << _name << " | "
		<< "Chips: " << _chips << " | "
		<< "UUID: " << _uuid;
	return oss.str();
}

std::string Player::getName() const
{
	return _name;
}

void Player::setName(const std::string& name)
{
	_name = name; 
}

bool Player::operator==(const Player& other) const
{
	return _uuid == other._uuid;
}

bool Player::operator!=(const Player& other) const
{
	return _uuid!=other._uuid;
}

std::string Player::getUUID() const
{
	return _uuid;
}

std::string Player::getPassword() const
{
	return _passwrd;
}

void Player::setPassword(const std::string& passwrd)
{
	_passwrd = passwrd;
}

int Player::calculateScore()
{
	_score = 0; 
	if (_handOnTable.empty())
	{
		throw HandEmptyException(); // cannot calculate score if hand is empty
	}
	for (const Card& card : _handOnTable)
	{
		//raw score calculations
		if (card.isJoker())
		{
			_score += JOKER; // jokers do not contribute to score
		}
		else
		{
			_score += card.getValue(); // add the value of the card to the score
		}

	}
	//why a temp hand is needed here? idk, but it works so idc.
	std::array<Card, HAND_ONBOARD_SIZE> tempHand;
	tempHand[0] = _handOnTable[0];
	tempHand[1] = _handOnTable[1];
	if (isFlush(tempHand))
	{
		_score += FLUSH; // add flush bonus if both cards have the same suit
		return _score;
	}
	if (isPair(tempHand))
	{
		_score += PAIR; // add pair bonus if both cards have the same value
		return _score;
	}
	if (isStraight(tempHand))
	{
		_score += STRAIGHT; // special case for Ace and Two
		return _score;
	}
	if (isSuitedPair(tempHand))
	{
		_score += SUITED_PAIR; // add suited pair bonus if both cards have the same suit and value
		return _score;
	}
	if (isStraightFlush(tempHand))
	{
		_score += SFLUSH; // add straight flush bonus if both cards are jokers
		return _score;
	}
	return _score;
}

bool isFlush(const std::array<Card, HAND_ONBOARD_SIZE>& hand)
{
	return hand[0].getSuit() == hand[1].getSuit();
}

bool isPair(const std::array<Card, HAND_ONBOARD_SIZE>& hand)
{
	return hand[0].getValue() == hand[1].getValue();
}

bool isStraight(const std::array<Card, HAND_ONBOARD_SIZE>& hand)
{
	int diff = std::abs(hand[0].getValue() - hand[1].getValue());
	return diff == 1 || (diff == 12 && (hand[0].getValue() == ACE || hand[1].getValue() == ACE)); // special case for Ace and Two
}

bool isSuitedPair(const std::array<Card, HAND_ONBOARD_SIZE>& hand)
{
	return isFlush(hand) && isPair(hand);
}

bool isStraightFlush(const std::array<Card, HAND_ONBOARD_SIZE>& hand)
{
	return isFlush(hand) && isStraight(hand);
}
