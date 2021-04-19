#include "card.hpp"

Rank& operator ++(Rank& e){
    e = Rank(int(e) + 1);
    return e;
}

Suit& operator ++(Suit& e){
    e = Suit(int(e) + 1);
    return e;
}



int Card::rank_value() {
    int score = static_cast<int>(rank);

    if( rank == Rank::ACE){
        score = 11; 
    }
    else if(score > 10) {
        score = 10;
    }

    return score;
}

std::string Card::suit_string(){
    
    std::string s;
    switch (suit){
    case Suit::SPADES:
        s = "spades";
        break;
    case Suit::HEARTS:
        s = "hearts";
        break;
    case Suit::DIAMONDS:
        s = "diamonds";
        break;
    case Suit::CLUBS:
        s = "clubs";
        break;
    default:
        throw std::domain_error{"Illegal suit value in suit_string function"};
        break;
    }

    return s;

}

std::string Card::rank_string(){
    std::string s;
    
    switch (rank){
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
        int tmp = static_cast<int>(rank);
        if(tmp <2 || tmp>11){
            throw std::domain_error{"Illegal rank value in rank_string function"};
        }
        s = std::to_string(tmp);
        break;
    }

    return s;
}

std::string Card::card_string(){
    std::string s = suit_string() + " " + rank_string();
    return s;
}

Card::Card(Suit s, Rank r){
    suit = s;
    rank = r;
    value = rank_value();
}

Suit Card::get_suit(){
    return suit;
}

Rank Card::get_rank(){
    return rank;
}

int Card::get_value(){
    return value;
}

