#include "blackjack.hpp"
#include <iostream>


int main(){
    const int N_DECKS = 1;
    double money;
    int n_players;
    std::string name;
    std::vector<Player> players;

    std::cout << "xxxxxxxxxxxxxx Blackjack xxxxxxxxxxxxxx" <<std::endl;
    std::cout << "Set total players"<< std::endl;
    std::cin >> std::ws >> n_players;

    for (size_t i = 0; i < n_players; i++){
        std::cout << "Set player " << (i+1) << " name:" << std::endl;
        std::cin >> std::ws >> name;
        std::cout << "Set "<< name << " starting bank" << std::endl;
        std::cin >> std::ws >> money;
        Player p = Player(money,name);
        players.push_back(p);
    }
    
    BlackJack b = BlackJack(players,N_DECKS);
    
    char inp;
    while(true){
        std::cout << "################################################" << std::endl;

        b.place_bets();
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