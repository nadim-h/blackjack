#include "blackjack.cpp"
#include "player.hpp"
#include <iostream>


int main(){
    const double BLACKJACK = 2.5;
    const double WIN = 2;
    const double TIE = 1;
    const double LOSS = -1; 
    
    const int N_DECKS = 1;

    std::cout << "-----------Blackjack------------" <<std::endl;
    
    std::cout << "Starting total money"<< std::endl;
    double money;
    std::cin >> money;
    Player p = Player(money);
    
    BlackJack b = BlackJack(p,N_DECKS,BLACKJACK,WIN,TIE,LOSS);
    char inp;
    while(true){

        std::cout << "Game starting, place your bet" << std::endl;
        double bet;
        std::cin >> bet;
        b.place_bet(bet);
        b.init_deal();
        b.player_loop();
        b.dealer_loop();
        b.conclusion();
        
        std::cout << "Play again? yes (y) or no (n)" << std::endl;
        std::cin >> std::ws >> inp;
        if(inp == 'n') break;
        b.reset_state();
    }

    return 0;
}