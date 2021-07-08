#include "player.h"

void Player::setCards() {
    playerCards.clear();
    for (int i = 0; i < 2; i++) {
        playerCards.push_back(genCards(i + 1));
    }
}

void Player::showCards() {
    // cout << "\nCard size: " << playerCards.size() << endl;
    cout << "\nYour's cards: ";
    for (auto card : playerCards) {
        cout << card << " ";

    }
}

int Player::calcCards() {
    int sum{ 0 };
    for (auto card : playerCards) {
        sum += card;
    }
    return sum;
}

void Player::onHit() {
    int prevTot = Player::calcCards();
    int newCard = genCards(1);
    if ((newCard == 11) && (prevTot + newCard) > 21) {
        newCard = 1;
    }
    playerCards.push_back(newCard);
}