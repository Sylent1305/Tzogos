#pragma once
#ifndef EXCEPTION_H
#include <stdexcept> // Include standard exception header for custom exceptions

class HandFullException : public std::runtime_error
{
public:
    HandFullException() : std::runtime_error("Hand is full. Cannot add more cards.") {}
};

class InvalidCardException : public std::runtime_error
{
public:
	InvalidCardException() : std::runtime_error("Invalid card. Cannot add to hand.") {}
};

class InvalidPlayerException : public std::runtime_error
{
public:
	InvalidPlayerException() : std::runtime_error("Invalid player. Cannot perform action.") {}
};

class DeckEmptyException : public std::runtime_error
{
public:
	DeckEmptyException() : std::runtime_error("Deck is empty. Cannot deal more cards.") {}
};

class GameOverException : public std::runtime_error
{
public:
	GameOverException() : std::runtime_error("Game is over. Cannot perform action.") {}
};

class InvalidMoveException : public std::runtime_error
{
public:
	InvalidMoveException() : std::runtime_error("Invalid move. Cannot perform action.") {}
};

class CardNotFoundException : public std::runtime_error
{
public:
	CardNotFoundException() : std::runtime_error("Card not found in hand. Cannot perform action.") {}
};

class PlayerNotFoundException : public std::runtime_error
{
public:
	PlayerNotFoundException() : std::runtime_error("Player not found. Cannot perform action.") {}
};

class InvalidGameStateException : public std::runtime_error
{
public:
	InvalidGameStateException() : std::runtime_error("Invalid game state. Cannot perform action.") {}
};

class InvalidCardValueException : public std::runtime_error
{
public:
	InvalidCardValueException() : std::runtime_error("Invalid card value. Cannot perform action.") {}
};

class InvalidCardSuitException : public std::runtime_error
{
public:
	InvalidCardSuitException() : std::runtime_error("Invalid card suit. Cannot perform action.") {}
};

class InvalidActionException : public std::runtime_error
{
public:
	InvalidActionException() : std::runtime_error("Invalid action. Cannot perform action.") {}
};

class NegativeNumberException : public std::runtime_error
{
public:
	NegativeNumberException() : std::runtime_error("Negative number encountered. Cannot perform action.") {}
};

class MissingChipsException : public std::runtime_error
{
public:
	MissingChipsException() : std::runtime_error("Not enough chips. Cannot perform action.") {}
};

class HandEmptyException : public std::runtime_error
{
public:
	HandEmptyException() : std::runtime_error("Hand is empty. Cannot perform action.") {}
};
#endif // EXCEPTION_H