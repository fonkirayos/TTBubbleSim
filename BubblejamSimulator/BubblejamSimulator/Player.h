#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"
class Player
{
public:
	Player();
	std::vector<Card> hand;
	void AddCardToHand(const Card & card);
	void ShuffleHand();
};

