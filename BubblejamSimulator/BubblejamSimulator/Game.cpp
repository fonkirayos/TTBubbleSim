#include "Game.h"


void Game::InitializeDeckPile()
{
	
	cardBuffer.id = 0;

	for (int i = 0; i < bubbleRodCards; i++) 
	{
		deckPile.push_back(cardBuffer);
	}

	cardBuffer.id = 2;

	for (int i = 0; i < bubbleNetCards; i++)
	{
		deckPile.push_back(cardBuffer);
	}

	cardBuffer.id = 3;

	for (int i = 0; i < needleCards; i++)
	{
		deckPile.push_back(cardBuffer);
	}
	
	
}

void Game::ShuffleDeckPile()
{
	for (size_t i = 0; i < deckPile.size(); i++)
	{
		size_t j = std::rand() % (deckPile.size() - 1); // Create a distribution in range [0, i]
		std::swap(deckPile[i], deckPile[j]); // Swap the current element with a randomly chosen element
	}
}

void Game::InitializePlayers(const int& _players)
{
	Player player;
	for (int i = 0; i < _players; i++) {
		players.push_back(player);
		currentPlayerIndex = i;
		for (int j = 0; j < initialHandSize; j++) {
			DrawCard();
		}
	}
	
}

void Game::DiscardCard(Card& card)
{
	if (card.id != 4) {
		discardPile.push_back(card);
	}
}

void Game::DrawCard()
{
	if (!deckPile.empty()) {
		players[currentPlayerIndex].AddCardToHand(deckPile[0]);
		deckPile.erase(deckPile.begin()); //erase from deck vector
	}
	else {
		AddDiscardToDeck();
		ShuffleDeckPile();
		players[currentPlayerIndex].AddCardToHand(deckPile[0]);
		deckPile.erase(deckPile.begin()); //erase from deck vector
	}
}

void Game::PlayCard(const Card& card)
{
	switch (card.id)
	{
	default:
		break;
	case 0:
		PlayBubbleRod();
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}

void Game::PlayBubbleRod()
{
	Card card;
	card.id = 4;

	currentPlayer.hand.push_back(card);
}


void Game::AddDiscardToDeck()
{
	deckPile = std::move(discardPile);
	discardPile.clear();
}

void Game::InitializeGame()
{
	InitializeDeckPile();
	ShuffleDeckPile();
	InitializePlayers(numPlayers);
}


void Game::Run()
{
	InitializeGame();
}


Game::Game()
{
	
}
