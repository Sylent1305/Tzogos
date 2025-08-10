#include "Game.h"
#include <algorithm>
#include <functional>
#include <iostream>

static const char* COL_RED_     = "\x1b[38;2;255;0;0m";      // hearts
static const char* COL_LBLUE_   = "\x1b[38;2;173;216;230m";  // diamonds
static const char* COL_LIME_    = "\x1b[38;2;0;255;0m";      // clubs
static const char* COL_ORANGE_  = "\x1b[38;2;255;165;0m";    // spades
static const char* COL_MAGENTA_ = "\x1b[38;2;255;0;255m";    // joker
static const char* COL_GRAY_    = "\x1b[38;2;160;160;160m";  // empty
static const char* RESET_       = "\x1b[0m";
static const char* colorForSuit_(int suit, bool isJoker) {
	if (isJoker) return COL_MAGENTA_;
	switch (suit) {
		case HEARTS:   return COL_RED_;
		case DIAMONDS: return COL_LBLUE_;
		case CLUBS:    return COL_LIME_;
		case SPADES:   return COL_ORANGE_;
		default:       return RESET_;
	}
}
static std::string cardColored_(const Card& c) {
	return std::string(colorForSuit_(c.getSuit(), c.isJoker())) + c.toString() + RESET_;
}
static std::string handColored_(const Player& p) {
	auto hand = p.getHand();
	std::string out;
	for (size_t i = 0; i < hand.size(); ++i) {
		const Card& c = hand[i];
		if (c.getValue() == EMPTY) {
			out += std::string(COL_GRAY_) + "[]" + RESET_;
		} else {
			out += cardColored_(c);
		}
		if (i + 1 < hand.size()) out += " ";
	}
	return out;
}
static void printHands_(const std::list<Player>& players, const char* header) {
	std::cout << header << std::endl;
	for (const Player& p : players) {
		std::cout << "  " << p.getName() << ": " << handColored_(p) << std::endl;
	}
}


Game::Game(int maxHands, std::list<Player> players)
{
	_maxHands = maxHands;
	_handNumber = 0;
	_roundNum = FIRST_ROUND;
	_gameState = NOT_STARTED;
	_maxPlayers = 6;
	setPlayerTurnOrder(players);
	_gameMode = SD;
	_currentRaise = 0;
	_pot = 0;
	_ante = 0;
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
		throw std::out_of_range("Invalid round number");
	}
	_roundNum = round;
}

void Game::setHandNumber(int hand)
{
	if (hand < 0 || hand > _maxHands)
	{
		throw std::out_of_range("Invalid hand number");
	}
	_handNumber = hand;
}

void Game::setMaxHands(int max)
{
	if (max <= 0)
	{
		throw std::out_of_range("Max hands must be greater than 0");
	}
	_maxHands = max;
}

void Game::setGameState(int state)
{
	if (state < NOT_STARTED || state > COMPLETED)
	{
		throw std::out_of_range("Invalid game state");
	}
	_gameState = state;
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
		throw PlayerNotFoundException();
	}
	_player_turn_order = players;
	_players_still_in_round = players;
}

void Game::addPlayerToTurnOrder(const Player& player)
{
	if (_player_turn_order.size() >= _maxPlayers)
	{
		throw std::out_of_range("Cannot add more players, maximum limit reached");
	}
	std::list<Player> temp(_player_turn_order);
	shufflePlayerTurnOrder(); 
	Player firstPlayer = _player_turn_order.front();
	_player_turn_order = temp;
	auto it = std::find(_player_turn_order.begin(), _player_turn_order.end(), firstPlayer); 
	if (it != _player_turn_order.end())
	{
		_player_turn_order.insert(std::next(it), player);
	}
	else
	{
		throw PlayerNotFoundException();
	}
}

void Game::removePlayerFromTurnOrder(const Player& player)
{
	auto it = std::find(_player_turn_order.begin(), _player_turn_order.end(), player);
	if (it != _player_turn_order.end())
	{
		_player_turn_order.erase(it);
	}
	else
	{
		throw PlayerNotFoundException();
	}
}

void Game::clearPlayerTurnOrder()
{
	_player_turn_order.clear(); 
}

void Game::shufflePlayerTurnOrder()
{
	std::vector<Player> temp(_player_turn_order.begin(), _player_turn_order.end());
	std::random_device rd;
	std::mt19937 eng(rd());
	std::shuffle(temp.begin(), temp.end(), eng);
	_player_turn_order.assign(temp.begin(), temp.end());
}

void Game::dealHand()
{
	_deck.dealHand(_player_turn_order, 7); 
	_players_still_in_round = _player_turn_order;
	for (Player& p : _players_still_in_round)
	{
		p.resetBoard();
	}
}

void Game::resetGame()
{
	_deck.resetDeck(_gameMode);
	for (Player& player : _player_turn_order)
	{
		player.clearHand();
	}
	_pot = 0;
	_currentRaise = 0;
}

void Game::startGame()
{
	_gameState = IN_PROGRESS;
	_handNumber = 0;
	_roundNum = FIRST_ROUND;
	_deck.resetDeck(_gameMode);

	for (Player& p : _player_turn_order)
	{
		if (p.getChips() == 0) { p.setChips(100); }
	}

	dealHand();
	startBettingRound();
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
		endGame();
	}
	else
	{
		for (Player player : _player_turn_order)
		{
			player.clearHand();
		}
		dealHand();
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
	std::cout << "Showdown:" << std::endl;
	int maxScore = -1000; 
	std::vector<std::reference_wrapper<Player>> contenders;
	for (Player & player : _players_still_in_round)
	{
		try {
			int score = player.calculateScore();
			std::cout << " - " << player.getName() << " cards: "
				<< cardColored_(player.getBoard()[0]) << ", "
				<< cardColored_(player.getBoard()[1]) << " => score: " << score << std::endl;
			if (score > maxScore)
			{
				maxScore = score;
				contenders.clear();
				contenders.push_back(player);
			}
			else if (score == maxScore)
			{
				contenders.push_back(player);
			}
		} catch (const std::exception&) {
			continue;
		}
	}

	if (contenders.empty())
	{
		std::cout << "No valid contenders." << std::endl;
		return;
	}

	if (contenders.size() == 1)
	{
		std::cout << "Winner: " << contenders[0].get().getName() << " wins pot " << _pot << std::endl;
		contenders[0].get().addChips(_pot);
		_pot = 0;
		return;
	}

	std::cout << "Tie-breaker draw..." << std::endl;
	bool resolved = false;
	while (!resolved)
	{
		int best = -1000;
		std::vector<size_t> indices;
		for (size_t i = 0; i < contenders.size(); ++i)
		{
			Card c = _deck.dealCard();
			int v = c.isJoker() ? 0 : c.getValue();
			std::cout << " - " << contenders[i].get().getName() << " draws " << c.toString() << std::endl;
			if (v > best)
			{
				best = v;
				indices.clear();
				indices.push_back(i);
			}
			else if (v == best)
			{
				indices.push_back(i);
			}
		}
		if (indices.size() == 1)
		{
			std::cout << "Winner: " << contenders[indices[0]].get().getName() << " wins pot " << _pot << std::endl;
			contenders[indices[0]].get().addChips(_pot);
			_pot = 0;
			resolved = true;
		}
	}
}

void Game::setAnte(int ante)
{
	if (ante < 0) throw NegativeNumberException();
	_ante = ante;
}

int Game::getAnte() const
{
	return _ante;
}

int Game::getPot() const
{
	return _pot;
}

void Game::anteUp()
{
	std::cout << "Ante " << _ante << " from each player" << std::endl;
	for (Player& p : _players_still_in_round)
	{
		p.removeChips(_ante);
		_pot += _ante;
	}
	std::cout << "Pot is now " << _pot << std::endl;
	_currentRaise = 0;
}

void Game::betRaise(Player& player, int amount)
{
	if (amount < 0) throw NegativeNumberException();
	int maxRaise = _pot;
	if (amount > maxRaise) throw InvalidActionException();
	player.removeChips(amount);
	_pot += amount;
	_currentRaise = amount;
	_lastRaisePlayer = player;
	std::cout << player.getName() << " raises " << amount << ", pot " << _pot << std::endl;
}

void Game::call(Player& player)
{
	int toCall = _currentRaise;
	player.removeChips(toCall);
	_pot += toCall;
	std::cout << player.getName() << " calls " << toCall << ", pot " << _pot << std::endl;
}

void Game::check(Player& player)
{
	std::cout << player.getName() << " checks" << std::endl;
}

void Game::fold(Player& player, bool placedOnlyOneCard)
{
	auto it = std::find(_players_still_in_round.begin(), _players_still_in_round.end(), player);
	if (it != _players_still_in_round.end())
	{
		if (placedOnlyOneCard)
		{
			int idx = it->findFirstNonEmptyIndex();
			if (idx >= 0)
			{
				it->removeCardAt(idx);
			}
		}
		std::cout << it->getName() << " folds" << std::endl;
		_players_still_in_round.erase(it);
	}
}

void Game::placeCard(Player& player, int handIndex, int boardIndex, bool faceUp)
{
	if (handIndex < 0 || handIndex >= HAND_SIZE) throw std::out_of_range("handIndex");
	if (boardIndex < 0 || boardIndex >= HAND_ONBOARD_SIZE) throw std::out_of_range("boardIndex");

	for (Player& p : _players_still_in_round)
	{
		if (p == player)
		{
			std::array<Card, HAND_SIZE> h = p.getHand();
			Card c = h[handIndex];
			if (c.getValue() == EMPTY) throw InvalidCardException();
			p.setBoardCard(boardIndex, c);
			p.setBoardFaceUp(boardIndex, faceUp);
			p.removeCardAt(handIndex);
			std::cout << p.getName() << " places "
				<< (faceUp ? cardColored_(c) : std::string("face-down card"))
				<< " to slot " << boardIndex << std::endl;
			break;
		}
	}
}

void Game::useJokerSwap(Player& actor, Player& target, int targetBoardIndex, int actorHandIndex)
{
	for (Player& p : _players_still_in_round)
	{
		if (p == actor)
		{
			std::array<Card, HAND_SIZE> h = p.getHand();
			if (actorHandIndex < 0 || actorHandIndex >= HAND_SIZE) throw std::out_of_range("actorHandIndex");
			Card a = h[actorHandIndex];
			if (!a.isJoker()) throw InvalidActionException();
			for (Player& t : _players_still_in_round)
			{
				if (t == target)
				{
					if (targetBoardIndex < 0 || targetBoardIndex >= HAND_ONBOARD_SIZE) throw std::out_of_range("targetBoardIndex");
					Card victimCard = t.getBoard()[targetBoardIndex];
					t.setBoardCard(targetBoardIndex, a);
					p.removeCardAt(actorHandIndex);
					Card drawn = _deck.dealCard();
					p.addCard(drawn);
					std::cout << p.getName() << " uses Joker on " << t.getName() << " slot " << targetBoardIndex << std::endl;
					return;
				}
			}
		}
	}
	throw InvalidActionException();
}

void Game::endRoundResolve()
{
	showdown();
}

void Game::startBettingRound()
{
	std::cout << "Starting hand with " << _player_turn_order.size() << " players" << std::endl;
	_roundNum = FIRST_ROUND;
	_players_still_in_round = _player_turn_order;
	for (Player& p : _players_still_in_round) p.resetBoard();

	printHands_(_players_still_in_round, "Initial hands:");

	std::cout << "Round 1: first face-down, second face-up" << std::endl;
	_roundNum = FIRST_ROUND;
	playRoundPattern(false, true, false);

	std::cout << "Round 2: both face-down" << std::endl;
	_roundNum = SECOND_ROUND;
	playRoundPattern(false, false, false);

	std::cout << "Round 3: first face-up, second face-down" << std::endl;
	_roundNum = THIRD_ROUND;
	playRoundPattern(true, false, false);

	std::cout << "Round 4: one face-down + community" << std::endl;
	_roundNum = FINAL_ROUND;
	playRoundPattern(false, false, true);

	std::cout << "Hand complete" << std::endl;
}

void Game::playRoundPattern(bool firstFaceUp, bool secondFaceUp, bool hasCommunity)
{
	if (_ante > 0) anteUp();

	// Before first placement
	printHands_(_players_still_in_round, "Hands before first placement:");

	int boardIdx = 0;
	for (Player& p : _players_still_in_round)
	{
		int handIdx = p.findFirstNonEmptyIndex();
		if (handIdx >= 0)
		{
			placeCard(p, handIdx, boardIdx, firstFaceUp);
		}
	}

	// After first placement
	printHands_(_players_still_in_round, "Hands after first placement:");

	_currentRaise = 0;
	for (Player& p : _players_still_in_round)
	{
		check(p);
	}

	if (hasCommunity)
	{
		Card community = _deck.dealCard();
		std::cout << "Community card: " << cardColored_(community) << std::endl;
		for (Player& p : _players_still_in_round)
		{
			p.setBoardCard(1, community);
			p.setBoardFaceUp(1, true);
		}
	}
	else
	{
		boardIdx = 1;
		for (Player& p : _players_still_in_round)
		{
			int handIdx = p.findFirstNonEmptyIndex();
			if (handIdx >= 0)
			{
				placeCard(p, handIdx, boardIdx, secondFaceUp);
			}
		}
	}

	// After second placement / community
	printHands_(_players_still_in_round, "Hands after second placement:");

	_currentRaise = 0;
	for (Player& p : _players_still_in_round)
	{
		check(p);
	}

	endRoundResolve();

	_players_still_in_round = _player_turn_order;
	for (Player& p : _players_still_in_round) p.resetBoard();
	_pot = 0;
	_currentRaise = 0;
}
