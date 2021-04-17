#include "deck.hpp"

void Deck::pop_deck(int decks) {

    for (int i = 0; i < decks; i++){
        for (Suit s = Suit::begin; s != Suit::end; ++s) {
            for (Rank r = Rank::begin; r != Rank::end; ++r){
                deck.push_back(Card(s, r));
            }
        }
    }

}

Deck::Deck(int decks) {
    i = 0;
    pop_deck(decks);
}

void Deck::reset_deck() {
    i = 0;
    shuffle_deck();
}

void Deck::shuffle_deck() {
    std::shuffle(std::begin(deck) + i, std::end(deck), std::default_random_engine());
}

Card Deck::draw_card() {
    return deck[i++];
}
