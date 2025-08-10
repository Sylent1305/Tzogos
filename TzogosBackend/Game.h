#pragma once
#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>
#include <random>
#include "Player.h"
#include "Deck.h"

enum GameState
{
	NOT_STARTED,
	IN_PROGRESS,
	COMPLETED
};

enum Round_Num
{
	FIRST_ROUND = 1, // first card face down , second card face up
	SECOND_ROUND, //first card face down , second card face down
	THIRD_ROUND, //first card face up, second card face down
	FINAL_ROUND
};

enum GameMode
{
	SD = 1, // SUDDEN DEATH , default mode
	TD, // Till death
	DD, // Double the deck, double the jokers
	SDD, // Sudden death double deck
	JL, // restricts one joker each player per hand
	SD_JL, // Sudden death with joker limit
	TD_JL, // Till death with joker limit
	SDD_JL, // Sudden death double deck with joker limit
	TDD_JL // Till death double deck with joker 
};

enum BonusScore
{
	NO_BONUS = 0,
	FLUSH = 3,
	STRAIGHT = 5,
	PAIR = 7,
	SFLUSH = 10,
	SUITED_PAIR = 12
};

class Game
{
	public:
		Game(int maxHands, std::list<Player> players );
		~Game();
		int getRoundNum() const;
		int getHandNumber() const;
		int getMaxHands() const;
		int getGameState() const;
		void setRoundNum(int round);
		void setHandNumber(int hand);
		void setMaxHands(int max);
		void setGameState(int state);
		void setGameMode(int mode);
		int getMaxPlayers() const;
		int getGameMode() const;
		std::list<Player> getPlayerTurnOrder() const;
		void setPlayerTurnOrder(const std::list<Player>& players);
		void addPlayerToTurnOrder(const Player& player);
		void removePlayerFromTurnOrder(const Player& player);
		void clearPlayerTurnOrder();
		void shufflePlayerTurnOrder(); 
		void dealHand();
		void resetGame();
		void startGame();
		void endGame();
		void nextRound();
		void nextHand();
		void setDeck(const Deck& deck);
		Deck getDeck() const;
		std::string toString() const; // for debugging purposes
		std::list<Player> getPlayers() const; 
		void showdown(); // determine the winner of the round based on players' boards

		// betting
		void setAnte(int ante);
		int getAnte() const;
		int getPot() const;
		void anteUp();
		void betRaise(Player& player, int amount);
		void call(Player& player);
		void check(Player& player);
		void fold(Player& player, bool placedOnlyOneCard);

		// round actions
		void placeCard(Player& player, int handIndex, int boardIndex, bool faceUp);
		void useJokerSwap(Player& actor, Player& target, int targetBoardIndex, int actorHandIndex);
		void endRoundResolve();

		// full game flow
		void startBettingRound();

	private:
		void playRoundPattern(bool firstFaceUp, bool secondFaceUp, bool hasCommunity);

		int _roundNum; // Round_Num Enum
		int _handNumber; // to keep count when the next game will start
		int _maxHands; // define when creating a game in order to limit the number of hands in a game , each hand contains 4 rounds
		int _gameState; // GameState Enum
		int _maxPlayers; // maximum number of players in a game
		int _currentPlayersAmount; // current number of players in the game
		int _gameMode; // GameMode Enum
		int _currentRaise; // the current raise amount in the current hand
		Player _lastRaisePlayer; // the player who made the last raise in the current hand
		Deck _deck; // deck of cards used in the game
		Deck _trashPile; // cards that are discarded during the game
		std::list<Player> _players_still_in_round; // list of players in the game
		std::list<Player> _player_turn_order; // list of players in the order they will play
		int _pot = 0;
		int _ante = 0;
};
#endif // GAME_H
