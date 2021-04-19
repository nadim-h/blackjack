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
        Player player;
        Deck deck;

        void get_thecash(double factor);

    public:
        BlackJack(Player p, int n_decks);    

        void place_bet(double money);

        void init_deal();
        void start_dealing();
        void conclusion();
        void reset_state();
};
