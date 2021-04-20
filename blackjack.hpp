#pragma once
#include "player.hpp"
#include "deck.hpp"
#include "dealer.hpp"
#include <iostream>
#include <vector>


class BlackJack{
    private:
        // game rule constants
        const int GOAL = 21;
        const int CUTOFF = 17;
        const double BLACKJACK = 2.5;
        const double WIN = 2;
        const double TIE = 0;
        const double LOSS = -1;
        
        Dealer dealer;
        std::vector<Player> players;
        Deck deck;

        void get_thecash(double factor, Player &player);
        std::vector<Player> set_players();
        Deck set_deck();

    public:

        BlackJack();

        void place_bets();

        void init_deal();
        void start_dealing();
        void conclusion();
        bool another_round();
        void reset_state();
};
