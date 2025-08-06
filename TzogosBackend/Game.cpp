#include "Game.h"


Game::Game(int maxHands, std::list<Player> players)
{
	_maxHands = maxHands;
	_handNumber = 0;
	_roundNum = FIRST_ROUND;
	_gameState = NOT_STARTED;
	_maxPlayers = 6; // default max players
	setPlayerTurnOrder(players); // set the player turn order
	_gameMode = SD; // default game mode
}

Game::~Game()
{
}

int Game::getRoundNum() const
{
	return _roundNum;
}

int Game::getHandNumber() const
{
	return _handNumber;
}

int Game::getMaxHands() const
{
	return _maxHands;
}

int Game::getGameState() const
{
	return _gameState;
}

void Game::setRoundNum(int round)
{
	if (round < FIRST_ROUND || round > FINAL_ROUND)
	{
		throw std::out_of_range("Invalid round number"); // throw exception if round number is invalid
	}
	_roundNum = round; // set the round number
}

void Game::setHandNumber(int hand)
{
	if (hand < 0 || hand > _maxHands)
	{
		throw std::out_of_range("Invalid hand number"); // throw exception if hand number is invalid
	}
	_handNumber = hand; // set the hand number
}

void Game::setMaxHands(int max)
{
	if (max <= 0)
	{
		throw std::out_of_range("Max hands must be greater than 0"); // throw exception if max hands is invalid
	}
	_maxHands = max; // set the maximum number of hands
}

void Game::setGameState(int state)
{
	if (state < NOT_STARTED || state > COMPLETED)
	{
		throw std::out_of_range("Invalid game state"); // throw exception if game state is invalid
	}
	_gameState = state; // set the game state
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
	if (_player_turn_order.size() >= _maxPlayers)
	{
		throw std::out_of_range("Cannot add more players, maximum limit reached"); // throw exception if max players limit is reached
	}
	std::list<Player> temp(_player_turn_order); // save current turn order
	shufflePlayerTurnOrder(); 
	Player firstPlayer = _player_turn_order.front();
	_player_turn_order = temp;
	// now find first player in temp 
	auto it = std::find(_player_turn_order.begin(), _player_turn_order.end(), firstPlayer); 
	if (it != _player_turn_order.end())
	{
		_player_turn_order.insert(std::next(it), player); // insert new player after the first player
	}
	else
	{
		throw PlayerNotFoundException(); // throw exception if first player not found
	}
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

void Game::dealHand()
{
	_deck.dealHand(_player_turn_order, 7); 
}

void Game::resetGame()
{
	_deck.resetDeck();
	for (Player& player : _player_turn_order)
	{
		player.clearHand(); // Clear each player's 
	}
}

void Game::startGame()
{
	_gameState = IN_PROGRESS; // Set the game state to in progress
	_handNumber = 0; // Reset hand number
	_roundNum = FIRST_ROUND; // Reset round number
	_deck.resetDeck(); // Reset the deck
	dealHand(); // Deal the initial hand to players
}

void Game::endGame()
{
	_gameState = COMPLETED;
}

void Game::nextRound()
{
	_roundNum++;
}

void Game::nextHand()
{
	_handNumber++;
	if (_handNumber >= _maxHands)
	{
		endGame(); // End the game if the maximum number of hands is reached
	}
	else
	{
		for (Player player : _player_turn_order)
		{
			player.clearHand();
		}
		dealHand(); // Deal a new hand to players
	}
}


void Game::setDeck(const Deck& deck)
{
	_deck = deck;
}

Deck Game::getDeck() const
{
	return _deck;
}

std::string Game::toString() const
{
	return "not implemented yet";
}

std::list<Player> Game::getPlayers() const
{
	return _player_turn_order;
}

void Game::showdown()
{
	int maxScore = 0; 
	Player* winner = nullptr;
	for(Player & player : _players_still_in_round)
	{
		player.CalculateScore(); 
		if (player.getScore() > maxScore)
		{
			maxScore = player.getScore();
			winner = &player; 
		}
	}

}
