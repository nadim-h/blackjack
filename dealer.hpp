#pragma once
#include "player.hpp"
class Dealer : public Player {
    public:
        void player_turn (Deck &deck, int GOAL, int CUTOFF);
};