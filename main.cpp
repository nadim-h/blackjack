#include "blackjack.hpp"
#include <iostream>


int main(){
    const int N_DECKS = 1;
    double money;

    std::cout << "xxxxxxxxxxxxxx Blackjack xxxxxxxxxxxxxx" <<std::endl;
    
    std::cout << "Set players starting bank" << std::endl;
    std::cin >> std::ws >> money;
    Player p = Player(money);
    BlackJack b = BlackJack(p,N_DECKS);
    
    char inp;
    while(true){
        std::cout << "################################################" << std::endl;
        std::cout << "Game starting, enter an int to place bet" << std::endl;
        
        double bet;
        std::cin >> bet;

        b.place_bet(bet);
        b.init_deal();
        b.start_dealing();
        b.conclusion();
        
        std::cout << "Bet again? yes (y) or no (n)" << std::endl;
        std::cin >> std::ws >> inp;
        if(inp == 'n') break;
        
        b.reset_state();
    }

    return 0;
}