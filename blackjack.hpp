#pragma once
#include "player.hpp"
#include "deck.hpp"
#include <iostream>


class BlackJack{
    private:
        const double BLACKJACK;
        const double WIN;
        const double TIE;
        const double LOSS;
        
        Player dealer;
        Player player;

        Deck deck;
        int score_card(Card c);
        void hit(Player p);

    public:
        BlackJack(Player p, int decks, double BLACKJACK, double WIN, double TIE, double LOSS);    

        void place_bet(double money);

        void dealer_hit();
        void player_hit();
        void init_deal();

        void player_loop();
        void dealer_loop();

        void conclusion();

        void player_blackjack();
        void player_win();
        void tie();
        void player_lose();

        void reset_state();
};
