#pragma once
#include <iostream>
#include <list>
#include "Player.h"
class Game
{
private:
	std::vector<Player> players;
	std::vector<Card> deckPile;
	std::vector<Card> discardPile;
	std::vector<Card> bubblePile;

	Player currentPlayer;
	Card cardBuffer;
	int currentPlayerIndex = 0;

	int numPlayers = 2;
	int initialHandSize = 5;

	int bubbleRodCards = 4;
	int bubbleSoapCards = 4;
	int bubbleNetCards = 4;
	int needleCards = 4;
	int bubbleCards = 18;

	void InitializeDeckPile();
	void ShuffleDeckPile();
	void InitializePlayers(const int& _players);
	void DiscardCard(Card & card); 
	void DrawCard(); //current player draws card
	void PlayCard(const Card& card);
	void PlayBubbleRod();
	void PlayBubbleNet();
	void PlayNeedle();
	void AddDiscardToDeck();

	void InitializeGame();
public:
	void Run();

	Game();
};

