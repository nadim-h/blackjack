#include "dealer.hpp"

Dealer::Dealer() : Player::Player(0){}

void Dealer::player_turn (Deck &deck,int GOAL, int CUTOFF) {
    std::cout << "**********Dealer loop starting*************" << std::endl;
    while(true){
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Dealer hand is:" << std::endl;
        print_hand();
        std::cout << "Dealer score: " << score << std::endl;
        hit(deck);

        if(score > GOAL) {
            std::cout << "Dealer bust" << std::endl;
            break;
        }
        else if(score == GOAL){
            std::cout << "Dealer got perfect score" << std::endl;
            break;
        }
        else if(score >= CUTOFF){
            std::cout << "Dealer loop exit, score: " << score << std::endl;
            break;
        }
    }
    std::cout << "******************************************" << std::endl;
}