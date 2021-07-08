cmake_minimum_required(VERSION 3.19.8)

project(blackjack)

# find_package(wxWidgets REQUIRED COMPONENTS net core base)
# include(${wxWidgets_USE_FILE})
include_directories(include/)
add_executable(blackjack main.cpp src/player.cpp src/computer.cpp src/cards.cpp src/game.cpp src/art.cpp)
# target_link_libraries(myapp ${wxWidgets_LIBRARIES})
