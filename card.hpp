#pragma once
#include <iostream>
#include <string>

enum class Rank {
    begin=2,TWO=begin,THREE,FOUR,FIVE,
    SIX,SEVEN,EIGHT,NINE, TEN,
    ACE,JACK, QUEEN, KING, end
};

enum class Suit {
    begin,SPADES=begin, HEARTS, 
    DIAMONDS, CLUBS,end   
};

Rank& operator ++(Rank& e);

Suit& operator ++(Suit& e);

class Card {
    private:
        Suit suit;
        Rank rank;
        int value;

        int rank_value();
        std::string suit_string();
        std::string rank_string();
    
    public:
        Card(Suit s, Rank r);
        Suit get_suit();
        Rank get_rank();
        int get_value();
        std::string card_string();

};