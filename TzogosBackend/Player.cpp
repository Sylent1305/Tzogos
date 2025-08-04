#include "Player.h"

#include <random>
#include <sstream>
#include <iomanip>

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

Player::Player(std::string name, std::string passwrd)
{
	this->name = name; 
	this->passwrd = passwrd;
	this->uuid = generateUUID();
	this->score = 0;
	this->chips = 0;
	this->clearHand();
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
		if (isEmpty(this->hand[i])) 
		{ // find an empty slot in the hand
			this->hand[i] = card; // add the card to the hand
			return; // exit after adding the card
		}
	}
	throw HandFullException(); // if no empty slot found, throw an exception
	
}

void Player::clearHand()
{
	for (int i = 0; i < HAND_SIZE; ++i) {
		this->hand[i] = Card(); // fill hand with empty cards 
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

int Player::getChips() const
{
	return this->chips;
}

void Player::setChips(int chips)
{
	if (chips < 0) {
		throw NegativeNumberException(); // chips cannot be negative
	}
	this->chips = chips; 
}

void Player::addChips(int chips)
{
	this->chips += chips; 
}

void Player::removeChips(int chips)
{
	if (this->chips < chips)
	{
		throw MissingChipsException(); // not enough chips
	}
	this->chips -= chips; 
}

std::string Player::toString() const
{
	std::ostringstream oss;
	oss << "Name: " << name << " | "
		<< "Chips: " << chips << " | "
		<< "UUID: " << uuid;
	return oss.str();
}

std::string Player::getName() const
{
	return this->name;
}

void Player::setName(const std::string& name)
{
	this->name = name; 
}

bool Player::operator==(const Player& other) const
{
	return this->uuid == other.uuid;
}

bool Player::operator!=(const Player& other) const
{
	return this->uuid!=other.uuid;
}

std::string Player::getUUID() const
{
	return this->uuid;
}

std::string Player::getPassword() const
{
	return this->passwrd;
}

void Player::setPassword(const std::string& passwrd)
{
	this->passwrd = passwrd;
}

