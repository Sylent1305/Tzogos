#include "Deck.h"

Deck::Deck()
{
	resetDeck(); // Initialize the deck with cards and shuffle it
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



void Deck::resetDeck()
{
	const int jokers_amount_in_deck = 2; // number of jokers in deck
	_deck.clear(); // clear the deck
	// Add code to populate the deck with cards
	// For example, you can loop through all suits and values to create a standard 52-card deck
	for (int suit = SPADES; suit <= CLUBS; ++suit)
	{
		for (int value = TWO; value <= ACE; ++value)
		{
			Card newCard(suit,value);
			_deck.push_back(newCard);
		}
	}
	for (size_t i = 0; i < jokers_amount_in_deck; i++)
	{
		Card newjoker(NONE,JOKER,true);
		_deck.push_back(newjoker); // add a joker to the deck
	}
	this->shuffle(); // shuffle the deck after resetting
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
