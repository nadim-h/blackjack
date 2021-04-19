#include "player.hpp"

Player::Player(double money){
    this->money = money;
}

double Player::get_bet() const {
    return bet;
}

void Player::set_bet(double bet){
    this->bet = bet;
}

double Player::get_score() const {
    return score;
}

void Player::add_score(int score){
    this->score += score;
}


double Player::get_money() const{
    return money;
}

void Player::add_money(double money){
    this->money += money;
}


void Player::add_card(Card c){
    if(c.get_rank() == Rank::ACE) aces++;
    hand.push_back(c);
}

void Player::print_hand(){
    for (Card i : hand){
        std::cout << i.card_string() << ", ";
    }
    std::cout << std::endl;
}

void Player::discard_cards(){
    aces = 0;
    score = 0;
    bet = 0;
    hand.clear();
}

void Player::hit(Deck &deck){
    Card c = deck.draw_card();
    int c_score = c.get_value();
    score += c_score;
    add_card(c);
    if(score>21 && aces > 0){
        aces--;
        score -= 10;
    }
}

void Player::player_turn(Deck &deck, int GOAL){
    std::cout << "*************Player loop starting***********" << std::endl;
    char inp;
    while(true){
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Players hand is:" << std::endl;
        print_hand();   
        std::cout << "Players; score: "      << score
                  << ", bet: "      << bet
                  << ", money: "    << money 
                  << std::endl << std::endl;
        
        
        if(score>GOAL) {
            std::cout << "Player bust" << std::endl;
            break;
        }
        else if(score == GOAL){
            std::cout << "Player got blackjack" << std::endl;
            break;
        }
        
        std::cout << "Press s (stop) or h (hit)" << std::endl;
        std::cin >> std::ws >> inp;
        
        if(inp == 's'){ 
            std::cout << "Player stopped" << std::endl;
            break;
        }
        else if (inp == 'h'){
            std::cout << "Player hit" << std::endl;
            hit(deck);
        }
    }
    std::cout << "*****************************************" << std::endl << std::endl;
}