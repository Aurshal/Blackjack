#pragma once
#include <iomanip>
#include <cstdlib>



#include "computer.h"
#include "player.h"
#include "art.h"
#include "rules.h"


class Game :public Player, public Computer, public Art, public Rules {
    bool isGameOver = false;
    string hitOrStand;

public:
    void menu();
    void init();
    void play();
    void playAgain();
    void chooseWinner();
};


