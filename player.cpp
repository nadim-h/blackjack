#include "player.hpp"

Player::Player(double money){
    this->money = money;
    status = Status::ACTIVE;
    score = 0;
    bet = 0;
    aces = 0;
}

double Player::get_bet() const {
    return bet;
}

void Player::set_bet(double bet){
    this->bet = bet;
}

void Player::add_card(Card c){
    if(c.get_rank() == Rank::ACE) aces++;
    hand.push_back(c);
}

int Player::get_score() const {
    return score;
}

void Player::add_score(int s){
    score += s;
}

void Player::discard_cards(){
    aces = 0;
    score = 0;
    hand.clear()
}

std::vector<Card> Player::get_hand() const{
    return hand;
}

void Player::modify_money(double money){
    this->money += money;
}

bool Player::has_ace(){
    return (aces > 0);
}

void Player::dec_ace(){
    aces--;
    scores -= 10;
}

void Player::print_hand(){
    for (Card i : hand){
        std::cout << i.card_string() << " ";
    }
    std::cout << std::endl;
}

void Player::get_status() const{
    return status;
}

void Player::set_status(Status status){
    this->status = status;
}