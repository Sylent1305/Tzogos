#include "Deck.h"

Deck::Deck()
{
	resetDeck(); // Initialize the deck with cards and shuffle it
}

Deck::~Deck()
{
	// using stl list so no need to manually delete
}

void Deck::shuffle()
{
	// Use the random_shuffle algorithm to shuffle the deck
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::shuffle(this->deck.begin(), this->deck.end(), eng); // shuffle the deck using the random engine
}

Card Deck::dealCard()  
{  
   if (this->deck.empty()) // Check if the deck is empty  
   {  
       throw std::out_of_range("No cards left in the deck to deal."); // Throw an exception if no cards are left to deal  
   }  
   Card dealtCard = this->deck.front(); // Copy the first card  
   this->deck.pop_front(); // Remove the first card from the deck  
   return dealtCard; // Return the card by value  
}



void Deck::resetDeck()
{
	const int jokers_amount_in_deck = 2; // number of jokers in deck
	this->deck.clear(); // clear the deck
	// Add code to populate the deck with cards
	// For example, you can loop through all suits and values to create a standard 52-card deck
	for (int suit = SPADES; suit <= CLUBS; ++suit)
	{
		for (int value = TWO; value <= ACE; ++value)
		{
			Card newCard;
			newCard.setSuit(suit);
			newCard.setValue(value);
			this->deck.push_back(newCard);
		}
	}
	for (size_t i = 0; i < jokers_amount_in_deck; i++)
	{
		Card newjoker;
		newjoker.setSuit(NONE);
		newjoker.setValue(JOKER);
		this->deck.push_back(newjoker); // add a joker to the deck
	}
	this->shuffle(); // shuffle the deck after resetting
}
