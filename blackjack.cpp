#include "blackjack.hpp"
#include <vector>

int BlackJack::score_card(Card c) const {
    int score = (int) c.get_rank();
    if(score > 10) score = 10;
    return score;
}

Card BlackJack::hit(Player p){
    Card c = deck.draw_card();
    int score = score_card(c);
    p.add_score(score);
    p.give_card(c);
    if(p.get_score()>21 && p.has_ace()) p.dec_ace();
    return Card
}


BlackJack::BlackJack(Player p,int n_decks, double BLACKJACK, double WIN, double TIE, double LOSS){
    dealer = Player(0);
    player = p;
    
    deck = Deck(n_decks);

    this->BLACKJACK = BLACKJACK;
    this->WIN = WIN;
    this->TIE = TIE;
    this->LOSS = LOSS;
}

void BlackJack::place_bet(double money){
    player.modify_bet(money);
}

Card BlackJack::dealer_hit(){
    Card c = hit(dealer);
    cout << "Dealer got: " << c.card_string() << std::endl;
    return c;
}

Card BlackJack::player_hit(){
    Card c = hit(player);
    cout << "Player got: " << c.card_string() << std::endl;
    return c;
}

void BlackJack::init_deal(){
    std::cout << "Starting to deal cards..." << std::endl; 
    player_hit();
    dealer_hit();
    player_hit();
    if(player.get_score() == 21) player.set_status(Status::BLACKJACK);
}

void BlackJack::player_loop(){
    if(player.get_status() == Status::BLACKJACK) {
        std::cout << "Player has blackjack" << std::endl;
        return;
    }
    std::cout << "Player loop starting:" << std::endl;
    char inp;
    while(true){
        std::cout << "Current hand is:" << std::endl;
        player.print_hand();
        
        std::cout << "Current score: " << player.get_score()
                  << ", Current bet: " << player.get_bet()
                  << ", Current money: " << player.get_money() << std::endl;
        
        std::cout << "Stop (s) or any button" << std::endl;
        std::cin >> std::ws >> inp;

        if(inp == 's') break;
        player_hit();
        if(player.get_score()>21) {
            player.set_status(Status::OVERDRAWN);
            break;
        }
    }
}

void BlackJack::dealer_loop(){
    std::cout << "Dealer loop starting:" << std::endl;
    while(true){
        std::cout << "Current hand is:" << std::endl;
        dealer.print_hand();
        std::cout << "Current score: " << dealer.get_score() << std::endl;
        if(dealer.get_score() > 21) dealer.set_status(Status::OVERDRAWN);
        if(dealer.get_score() > 17) break;
        dealer_hit();
    }
}


void BlackJack::conclusion(){

    std::cout << "Dealers score: " << dealer.get_score() << std::endl;

    int score = player.get_score()
    double bet = player.get_bet()

    std::cout << "Player score: " << player.get_score() << std::endl;
    
    if(player.get_status() == Status::BLACKJACK)        player_blackjack();
    else if(player.get_status() == Status::OVERDRAWN)   player_lose();
    else if(dealer.get_status() == Status::OVERDRAWN)   player_win();
    else if(player.get_score() < dealer.get_score())    player_lose();
    else if(player.get_score() > dealer.get_score())    player_win();
    else if(player.get_score() == dealer.get_score())   tie();
}

void BlackJack::player_blackjack(){
    double bet = player.get_bet();
    player.modify_money(BLACKJACK*bet);
}

void BlackJack::player_win(){
    double bet = player.get_bet();
    player.modify_money(WIN*bet);
}

void BlackJack::tie(){
}

void BlackJack::player_lose(){
    double bet = player.get_bet();
    player.modify_money(LOSS*bet);
}

void BlackJack::reset_state(){
    player.discard_cards();
    dealer.discard_cards();
    player.set_bet(0);

    deck.reset_deck();
}