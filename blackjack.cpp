#include "blackjack.hpp"

int BlackJack::score_card(Card c){
    int score = (int) c.get_rank();
    if(score > 10) score = 10;
    return score;
}

BlackJack::BlackJack(int decks){
    this->dealer = Player();
    this->dealer = Player();
    this->deck = Deck(decks);
}

void BlackJack::place_bet(double money){
    player.modify_bet(money);
}


void BlackJack::hit(Player p){
    
}


