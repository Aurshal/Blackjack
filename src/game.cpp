#include "game.h"
void Game::menu() {
    // Art::art();
    string usrInp;
    cout << "\nEnter:\n1. 'P' to play\n2. 'R' for Rules\n3. 'H' for Help\n4.'q' to quit\n";
    cout << ">> ";cin >> usrInp;
    if (usrInp == "P" || usrInp == "p")
        play();
    else if (usrInp == "R" || usrInp == "r") {
        system("clear");
        Art::art();
        Rules::showRules();
        menu();
    }
    else if (usrInp == "h" || usrInp == "H") {
        system("clear");
        Art::art();
        cout << "Go to rules from the menu below if want some help: \n";
        menu();
    }
    else if ((usrInp == "q" || usrInp == "Q")) {
        system("clear");
        exit(1);

    }
    else {
        system("clear");
        Art::art();
        cout << "You bastard! Read the menu properly and enter the correct keywords." << endl;
        menu();
    }


}
void Game::init() {
    Player::setCards();
    Computer::setCards();
}

void Game::play() {
    system("clear");
    Art::art();
    cout << setw(65);
    cout << "======WELCOME TO THE GAME OF BLACKJACK=====\n";

    Game::init();
    Player::showCards();
    Computer::showCards();

    do {
        cout << "\nHIT OR STAND?\nEnter:\n1. 'h' or 'H' for HIT\n2. Other key for STAND\n>> ";cin >> hitOrStand;
        if (Computer::calcCards() < 17)
            Computer::onHit();
        if (hitOrStand == "H" || hitOrStand == "h") {
            Player::onHit();
            Player::showCards();
            Computer::showCards();
            if (Player::calcCards() == 21) {
                cout << "\n\nYou got BLACKJACK! You WON!!" << endl;
                playAgain();
            }

            else if (Player::calcCards() > 21) {
                cout << endl << Player::calcCards() << endl;
                cout << Computer::calcCards() << endl;
                cout << "\nDealer WON!" << endl;
                playAgain();

            }
        }
        else {
            chooseWinner();
            playAgain();

        }

    } while (hitOrStand == "H" || hitOrStand == "h");
}

void Game::chooseWinner() {
    Player::showCards();
    Computer::showCards(false);
    cout << endl << "Your total: " << Player::calcCards() << endl;
    cout << "Dealer's total: " << Computer::calcCards() << endl;


    if ((Player::calcCards() > Computer::calcCards() || Computer::calcCards() > 21) && Player::calcCards() <= 21) {
        Player::bid *= 1.5;
        cout << "You WON!" << endl;
    }
    else if ((Player::calcCards() < Computer::calcCards() || Player::calcCards() > 21) && Computer::calcCards() <= 21) {
        cout << "Dealer WON!" << endl;
    }

    else if (Player::calcCards() == Computer::calcCards()) {
        cout << "Drawn";
    }

}

void Game::playAgain() {
    string usrInput;
    cout << "\n\nWanna continue to play? 'Y' for YES and 'N' for NO >>";
    cin >> usrInput;
    if (usrInput == "Y" || usrInput == "y")
        play();
    else {
        system("clear");
        Art::art();
        menu();
    }

}