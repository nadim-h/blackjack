#pragma once
#include "card.hpp"
#include <vector>
#include <string>


enum class Status {
    begin,BLACKJACK=begin, OVERDRAWN, ACTIVE,end   
};


class Player{

    private:
        double money;
        int score;
        int aces;
        double bet;
        Status status;
        std::vector<Card> hand;

    public:

        Player(double money);
        
        double get_bet() const;

        void set_bet(double bet);

        void add_card(Card c);

        double get_score() const;

        void add_score(int s);

        double get_money() const;

        void discard_cards();

        std::vector<Card> get_hand() const;

        void modify_money(double money);

        bool has_ace();
        void dec_ace();

        void print_hand();

        void get_status();

        void set_status(Status status);
};