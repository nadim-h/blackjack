#include "deck.hpp"

void Deck::populate_deck(int decks) {

    for (int i = 0; i < decks; i++){
        for (Suit s = Suit::begin; s != Suit::end; ++s) {
            for (Rank r = Rank::begin; r != Rank::end; ++r){
                deck.push_back(Card(s, r));
            }
        }
    }

}

Deck::Deck(int n_decks) {
    if(n_decks < 1){
        throw std::invalid_argument{"Number of decks must be greater than 0, was set to " 
            + std::to_string(n_decks)};
    }

    i = 0;
    populate_deck(n_decks);
    shuffle_deck();
}

void Deck::reset_deck() {
    i = 0;
    shuffle_deck();
}

void Deck::shuffle_deck() {
    std::shuffle(std::begin(deck) + i, std::end(deck), rng);
}

Card Deck::draw_card() {
    return deck[i++];
}
