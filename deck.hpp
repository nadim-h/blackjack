#pragma once
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <random>

class Deck{

private:

    std::vector<Card> deck;
    int i;
    void pop_deck(int decks);

public:

    Deck(int decks = 1);

    void reset_deck();

    void shuffle_deck();

    Card draw_card();
};