#include "blackjack.hpp"
#include <iostream>


int main(){
    try{

        BlackJack b = BlackJack();

        char inp;
        while(true){
            b.place_bets();
            b.init_deal();
            b.start_dealing();
            b.conclusion();
            if(b.another_round()) break;
            b.reset_state();
        }
    }
    catch(std::invalid_argument& ex){
        std::cout << "Invalid argument error " << ex.what() << std::endl;
    }
    catch(std::domain_error& ex){
        std::cout << "Invalid domain for card error " << ex.what() << std::endl;
    }
    return 0;
}