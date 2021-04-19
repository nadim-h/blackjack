#include "blackjack.hpp"

void BlackJack::get_thecash(double factor){
    std::cout << "*************results************" << std::endl;

    double prev_money = player.get_money();
    double bet = player.get_bet();
    double change = bet * factor;
    player.add_money(change);
    
    std::cout << "Players prev bank: " << prev_money << std::endl;
    std::cout << "Players bet: " << bet << std::endl;
    std::cout << "Change in money: " << change << std::endl;
    std::cout << "Players now total bank: " << player.get_money() << std::endl;
    std::cout << std::endl;
}

BlackJack::BlackJack(Player p, int n_decks) 
    : player(p),dealer(Dealer()), deck(Deck(n_decks)){

}

void BlackJack::place_bet(double money){
    player.set_bet(money);
}

void BlackJack::init_deal(){
    std::cout << "****Starting to deal cards...***" << std::endl << std::endl; 
    player.hit(deck);
    dealer.hit(deck);
    player.hit(deck);
}

void BlackJack::start_dealing(){
    player.player_turn(deck, GOAL);
    dealer.player_turn(deck, GOAL, CUTOFF);
}

void BlackJack::conclusion(){

    std::cout << std::endl << ">>>>>>>>>>>>>>RESULTS<<<<<<<<<<<<<<<<<" << std::endl;

    int d_score = dealer.get_score();
    int score = player.get_score();

    std::cout << "Dealers score: " << d_score << ", dealer hand: ";
    dealer.print_hand();
    std::cout << std::endl;
    std::cout << "Player score: " << score << ", player hand: ";
    player.print_hand();
    std::cout << std::endl;

    // player blackjack
    if(score == GOAL) {
        std::cout << "Player got BLACKJACK; player won!" << std::endl;
        get_thecash(BLACKJACK);
    }
    //player bust
    else if(score > GOAL) {
        std::cout << "Player BUST; player lost!" << std::endl;
        get_thecash(LOSS);
    }
    //dealer bust
    else if(d_score > GOAL) {
        std::cout << "Dealer BUST; player won!" << std::endl;
        get_thecash(WIN);
    }
    //player less score than dealer
    else if(score < d_score) {
        std::cout << "Player got lower score than dealer; player lost!" << std::endl;
        get_thecash(LOSS);
    }
    //player more score than dealer
    else if(score > d_score){
        std::cout << "Player got higher score than dealer; player won!" << std::endl;
        get_thecash(WIN);
    }
    //player tied with dealer
    else if(score == d_score){
        std::cout << "Player tied with dealer; player tied!" << std::endl;
        get_thecash(TIE);
    }
}


void BlackJack::reset_state(){
    player.discard_cards();
    dealer.discard_cards();
    deck.reset_deck();
}