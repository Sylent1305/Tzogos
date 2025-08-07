#include "Deck.h"
#include "Game.h"

Deck::Deck()
{
	emptyDeck();// sets all cards of deck into empty cards
}

Deck::Deck(int gamemode)
{
	resetDeck(gamemode); // Initialize the deck with cards and shuffle it
}

Deck::~Deck()
{

}

void Deck::shuffle()
{
	std::vector<Card> temp(_deck.begin(), _deck.end()); // temp vector
	std::random_device rd;
	std::mt19937 eng(rd());
	std::shuffle(temp.begin(), temp.end(), eng); // suffle
	_deck.assign(temp.begin(), temp.end()); // back to list
}


Card Deck::dealCard()  
{  
   if (_deck.empty()) // Check if the deck is empty  
   {  
       throw std::out_of_range("No cards left in the deck to deal."); // Throw an exception if no cards are left to deal  
   }  
   Card dealtCard = _deck.front(); // Copy the first card  
   _deck.pop_front(); // Remove the first card from the deck  
   return dealtCard; // Return the card by value  
}



void Deck::resetDeck(int gamemode)
{
    _deck.clear(); // Clear current deck

    int jokers_per_deck = 2; // Default jokers per standard deck
    int deck_count = 1; // Number of decks to use

    _limitJoker = false;

    switch (static_cast<GameMode>(gamemode))
    {
    case SD:
    case TD:
        deck_count = 1;
        jokers_per_deck = 2;
        break;

    case DD:
    case SDD:
    case TDD_JL:
    case SDD_JL:
        deck_count = 2;
        jokers_per_deck = 4;
        break;

    case JL:
    case SD_JL:
    case TD_JL:
        deck_count = 1;
        jokers_per_deck = 2;
        _limitJoker = true;
        break;

    default:
        // Fall back to default if unknown
        deck_count = 1;
        jokers_per_deck = 2;
        break;
    }

    // Populate deck(s)
    for (int d = 0; d < deck_count; ++d)
    {
        for (int suit = SPADES; suit <= CLUBS; ++suit)
        {
            for (int value = TWO; value <= ACE; ++value)
            {
                Card newCard(suit, value);
                _deck.push_back(newCard);
            }
        }
    }

    // Add jokers
    for (int i = 0; i < jokers_per_deck; ++i)
    {
        Card newjoker(NONE, JOKER, true);
        _deck.push_back(newjoker);
    }

    this->shuffle(); 
}


void Deck::dealHand(std::list<Player>& players, int amountofcards)
{
	if (players.empty()) // Check if there are no players
	{
		throw PlayerNotFoundException(); 
	}
	if (amountofcards <= 0) // Check if the amount of cards to deal is valid
	{
		throw InvalidCardValueException(); // Throw an exception if the amount is invalid
	}
	for (auto& player : players)  // Clear the player's hand before dealing new cards
	{
		player.clearHand(); 
	}
	for (size_t i = 0; i < HAND_SIZE; i++)
	{
		for (auto& player : players) // IRL like dealing method
		{
			player.addCard(dealCard()); 
		}
	}
	
}

void Deck::emptyDeck()
{
	_deck.clear(); // Clear the deck
	for (Card card : _deck)
	{
		card.setSuit(NONE); // Set the suit of each card to NONE
		card.setValue(EMPTY); // Set the value of each card to -1, means empty
		card.setIsJoker(false); // Set the joker flag to false
	}
}
