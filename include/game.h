#pragma once
#include <iomanip>
#include <cstdlib>



#include "computer.h"
#include "player.h"
#include "art.h"
#include "rules.h"


class Game :public Player, public Computer, public Art, public Rules {
    string hitOrStand;
private:
    int money{ 1000 };
    int bid{ 0 };
    int gameCount{ 0 };
public:
    void menu();
    void init();
    void play();
    void playAgain();
    void chooseWinner();
    void resultMenu();
};


