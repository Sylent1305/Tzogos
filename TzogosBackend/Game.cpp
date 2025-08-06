#include "Game.h"


Game::Game(int maxHands, std::list<Player> players)
{
}

Game::~Game()
{
}

int Game::getRoundNum() const
{
	return 0;
}

int Game::getHandNumber() const
{
	return 0;
}

int Game::getMaxHands() const
{
	return 0;
}

int Game::getGameState() const
{
	return 0;
}

void Game::setRoundNum(int round)
{
}

void Game::setHandNumber(int hand)
{
}

void Game::setMaxHands(int max)
{
}

void Game::setGameState(int state)
{
}

void Game::setGameMode(int mode)
{
	_gameMode = mode;
}

int Game::getMaxPlayers() const
{
	return _maxPlayers;
}

int Game::getGameMode() const
{
	return _gameMode;
}

std::list<Player> Game::getPlayerTurnOrder() const
{
	return _player_turn_order;
}

void Game::setPlayerTurnOrder(const std::list<Player>& players)
{
	if (players.empty())
	{
		throw PlayerNotFoundException(); // throw exception if no players are provided
	}
	_player_turn_order = players; // set the player turn order to the provided list of players
}

void Game::addPlayerToTurnOrder(const Player& player)
{
	// choose randomly one player , place new player after the old one and let a complete hand to play 
}

void Game::removePlayerFromTurnOrder(const Player& player)
{
	auto it = std::find(_player_turn_order.begin(), _player_turn_order.end(), player);
	if (it != _player_turn_order.end())
	{
		_player_turn_order.erase(it); // remove player from turn order
	}
	else
	{
		throw PlayerNotFoundException(); // throw exception if player not found
	}
}

void Game::clearPlayerTurnOrder()
{
	_player_turn_order.clear(); 
}

void Game::shufflePlayerTurnOrder()
{
	std::vector<Card> temp(_player_turn_order.begin(), _player_turn_order.end()); // temp vector
	std::random_device rd;
	std::mt19937 eng(rd());
	std::shuffle(temp.begin(), temp.end(), eng); // suffle
	_player_turn_order.assign(temp.begin(), temp.end()); // back to list
}
