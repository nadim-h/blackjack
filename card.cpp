#include "card.hpp"
#include <iostream>
#include <string>

Card::Card(Suit s, Rank r){
    suit = s;
    rank = r;
}

Suit Card::get_suit(){
    return suit;
}


std::string Card::suit_string(){
    
    std::string s;
    switch (suit){
    case Suit::SPADE:
        s = "spades";
        break;
    case Suit::HEART:
        s = "hearts";
        break;
    case Suit::DIAMOND:
        s = "diamonds";
        break;
    case Suit::CLUBS:
        s = "clubs";
        break;
    default:
        s = "fel, kasta exception lr nåt";
        break;
    }

    return s;

}

std::string Card::rank_string(){
    std::string s;
    
    switch (suit){
    case Rank::KING:
        s = "king";
        break;
    case Rank::QUEEN:
        s = "queen";
        break;
    case Rank::JACK:
        s = "jack";
        break;
    case Rank::ACE:
        s = "ace";
        break;
    default:
        s = std::stoi(suit);
        break;
    }

    return s;
}

std::string Card::card_string(){
    std::string s = suit_string() + " " + rank_string();
    return s;
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