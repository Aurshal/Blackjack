#pragma once

#include "cards.h"
class Computer : public Cards {
protected:
    vector <int> computerCards;
    bool b_computerWin = false;
    bool b_computerHit = false;

public:
    void setCards();
    void showCards(bool hidden = true);
    int calcCards();
    void onHit();

};