#pragma once
#include "player.hpp"
#include "deck.hpp"
#include <iostream>


class BlackJack{
    private:
        Player dealer;
        Player player;
        Deck deck;

        int score_card(Card c);

    public:
        BlackJack(int decks);    

        void place_bet(double money);

        void hit(Player p);

};
