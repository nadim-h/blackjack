#pragma once
#include "deck.hpp"
#include <vector>
#include <string>
#include <iostream>


class Player{

    protected:

        double money;
        double bet;
        int score;
        int aces;

        std::string name;
        
        void add_card(Card c);
        std::vector<Card> hand;

    public:

        Player(double money = 0, std::string name = "dealer");

        std::string get_name() const;

        double get_bet() const;
        void set_bet(double bet);

        double get_score() const;
        void add_score(int s);

        double get_money() const;
        void add_money(double money);

        void print_hand();
        void discard_cards();

        void hit(Deck &deck);
        virtual void player_turn(Deck &deck, int GOAL);
};