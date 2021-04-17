#pragma once

enum class Rank {
    begin=2,TWO=begin,THREE,FOUR,FIVE,
    SIX,SEVEN,EIGHT,NINE, TEN,
    JACK, QUEEN, KING, ACE, end
};

enum class Suit {
    begin,SPADE=begin, HEART, 
    DIAMOND, SPADES,end   
};

Rank& operator ++(Rank& e);

Suit& operator ++(Suit& e);

class Card {
    public:

        Card(Suit s, Rank r);
        Suit get_suit();
        Rank get_rank();

    private:
        Suit suit;
        Rank rank;
};