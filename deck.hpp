#pragma once
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <random>

class Deck{

private:
    int i;
    std::vector<Card> deck;
    void populate_deck(int decks);
    std::default_random_engine rng{std::random_device{}()};

public:
    Deck(int n_decks);

    void reset_deck();

    void shuffle_deck();

    Card draw_card();
};