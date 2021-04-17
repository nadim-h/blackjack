#pragma once
#include "card.hpp"
#include <vector>

class Player{

    private:

        int score;
        double bets;
        std::vector<Card> hand;

    public:

        Player();
        
        double get_bet() const;

        void modify_bet(double money);


        void give_card(Card c);

        int get_score() const;

        void add_score(int s);

        std::vector<Card> get_hand() const;
};