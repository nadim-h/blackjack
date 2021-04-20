#include "blackjack.hpp"

void BlackJack::get_thecash(double factor,Player &player){
    std::cout << "*************results************" << std::endl;


    double prev_money = player.get_money();
    double bet = player.get_bet();
    double change = bet * factor;
    player.add_money(change);
    
    std::cout << player.get_name() << " prev bank: " << prev_money << std::endl;
    std::cout << player.get_name() << " bet: " << bet << std::endl;
    std::cout << player.get_name() << " change in money: " << change << std::endl;
    std::cout << player.get_name() << " new total bank: " << player.get_money() << std::endl;
    std::cout << std::endl;
}


Deck BlackJack::set_deck(){
    std::cout << "Enter deck size; has to be greater than 0" << std::endl;
    int n_decks;
    std::cin >> std::ws >> n_decks;
    if(n_decks < 1){
        throw std::invalid_argument{"Set deck size less than 1"};
    }
    return Deck(n_decks);
}

std::vector<Player> BlackJack::set_players(){
    std::cout << "Set players"<< std::endl;
    double money;
    char inp;
    std::string name;
    std::vector<Player> ps;
    while(true){
        std::cout << "Set new player name:" << std::endl;
        std::cin >> std::ws >> name;
        std::cout << "Set "<< name << " starting bank" << std::endl;
        std::cin >> std::ws >> money;
        Player p = Player(money,name);
        ps.push_back(p);

        std::cout << "No more players 'n' or 'm' for more players" << std::endl;
        std::cin >> std::ws >> inp;
        if(inp == 'n'){
            break;
        }
        else if(inp == 'm'){
            continue;
        }
        else {
            throw std::invalid_argument( "Recieved invalid argument "
            + std::to_string(inp) +" in set_players" );
        }
    }
    return ps;
}

BlackJack::BlackJack() 
    : dealer(Dealer()), players(set_players()), deck(set_deck()){
        std::cout << "xxxxxxxxxxxxxx Blackjack xxxxxxxxxxxxxx" <<std::endl;
    }

void BlackJack::place_bets(){
    double bet;
    for (size_t i = 0; i < players.size(); i++){
        std::cout << "Set bet for player " 
                  << players[i].get_name() 
                  << ", bank is: " << players[i].get_money() 
                  << " or input -1 to walk away"<< std::endl;
        
        std::cin >> std::ws >> bet;
        if(bet == -1){
            std::cout << "Player " << players[i].get_name() << " has exited" << std::endl;
            players.erase(players.begin() + i);
            break;
        }
        else if(bet > players[i].get_money()){
            throw std::invalid_argument( players[i].get_name() 
                + " tried to bet with "
                + std::to_string(bet) + " while available money is "
                + std::to_string(players[i].get_money()));
        }
        else {
            std::cout << "Player " << players[i].get_name() << " has bet" << bet << std::endl;
            players[i].set_bet(bet);
        }
    }
}

void BlackJack::init_deal(){
    std::cout << "****Starting to deal cards...***" << std::endl << std::endl; 
    for (Player &player : players) {
        player.hit(deck);
    }

    dealer.hit(deck);
    
    for (Player &player : players) {
        player.hit(deck);
    }
}

void BlackJack::start_dealing(){
    for (Player &player : players){
        player.player_turn(deck, GOAL);   
    }
    
    dealer.player_turn(deck, GOAL, CUTOFF);
}

void BlackJack::conclusion(){

    std::cout << std::endl << ">>>>>>>>>>>>>>RESULTS<<<<<<<<<<<<<<<<<" << std::endl;
    
    int d_score = dealer.get_score();
    std::cout << "Dealers score: " << d_score << ", dealer hand: ";
    dealer.print_hand();
    std::cout << std::endl;

    for (Player &player : players) {
    
        int score = player.get_score();

        std::cout << player.get_name() << " score: " << score << ", player hand: ";
        player.print_hand();
        std::cout << std::endl;

        // player blackjack
        if(score == GOAL) {
            std::cout << player.get_name() << " got BLACKJACK; player won!" << std::endl;
            get_thecash(BLACKJACK,player);
        }
        //player bust
        else if(score > GOAL) {
            std::cout << player.get_name() << " BUST; player lost!" << std::endl;
            get_thecash(LOSS,player);
        }
        //dealer bust
        else if(d_score > GOAL) {
            std::cout << "Dealer BUST; player won!" << std::endl;
            get_thecash(WIN,player);
        }
        //player less score than dealer
        else if(score < d_score) {
            std::cout << player.get_name() << " got lower score than dealer; player lost!" << std::endl;
            get_thecash(LOSS,player);
        }
        //player more score than dealer
        else if(score > d_score){
            std::cout << player.get_name() << " got higher score than dealer; player won!" << std::endl;
            get_thecash(WIN,player);
        }
        //player tied with dealer
        else if(score == d_score){
            std::cout << player.get_name() << " tied with dealer; player tied!" << std::endl;
            get_thecash(TIE,player);
        }
    }
}

bool BlackJack::another_round(){
    char inp;
    std::cout << "Bet again? yes (y) or no (any key)" << std::endl;
    std::cin >> std::ws >> inp;
    return (inp != 'y');
}

void BlackJack::reset_state(){
    for (Player &player : players){
        player.discard_cards();   
    }
    dealer.discard_cards();
    deck.reset_deck();
}