#include "computer.h"

void Computer::setCards() {
    computerCards.clear();
    for (int i = 0; i < 2; i++) {
        computerCards.push_back(genCards(i + 7));
    }
}

void Computer::showCards(bool hidden) {
    // cout << "\nCard size: " << computerCards.size() << endl;
    cout << "\nDealer's card: ";
    for (unsigned i = 0; i < computerCards.size(); i++) {
        if (i != 1 && hidden == true)
            cout << " * ";
        else
            cout << computerCards.at(i) << " ";
    }
}

int Computer::calcCards() {
    int sum{ 0 };
    for (auto card : computerCards) {
        sum += card;
    }
    return sum;
}

void Computer::onHit() {
    int prevTot = Computer::calcCards();
    int newCard = genCards(1);
    if ((newCard == 11) && (prevTot + newCard) > 21) {
        newCard = 1;
    }
    computerCards.push_back(newCard);
}