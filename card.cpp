#include "card.hpp"
#include <iostream>

Card::Card(Suit s, Rank r){
    suit = s;
    rank = r;
}

Suit Card::get_suit(){
    return suit;
}

Rank Card::get_rank(){
    return rank;
}

Rank& operator ++(Rank& e){
    e = Rank(int(e) + 1);
    return e;
}

Suit& operator ++(Suit& e){
    e = Suit(int(e) + 1);
    return e;
}