#include "Player.h"


Player::Player()
{
    
}

void Player::AddCardToHand(const Card& card)
{
    hand.push_back(card);
}

void Player::ShuffleHand()
{

    for (size_t i = hand.size() - 1; i > 0; --i)
    {
        size_t j = std::rand() % (i + 1);  // Create a distribution in range [0, i]
        std::swap(hand[i], hand[j]); // Swap the current element with a randomly chosen element
    }
}
