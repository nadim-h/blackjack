#include "player.hpp"

Player::Player(){
    this->score = 0;
    this->bets = 0;
}

double Player::get_bet() const {
    return this->bets;
}

void Player::modify_bet(double money){
    this->bets += money;
}

void Player::give_card(Card c){
    this->hand.push_back(c);
}

int Player::get_score() const {
    return this->score;
}

void Player::add_score(int s){
    this->score += s;
}

std::vector<Card> Player::get_hand() const{
    return this->hand;
}