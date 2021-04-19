#pragma once
#include "player.hpp"
class Dealer : public Player {
    public:
        Dealer();
        void player_turn (Deck &deck, int GOAL, int CUTOFF);
};