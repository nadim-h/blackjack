cmake_minimum_required(VERSION 3.10)

# set the project name
project(Blackjack)

# add the executable
add_executable(blackjack main.cpp blackjack.cpp player.cpp deck.cpp card.cpp dealer.cpp)
