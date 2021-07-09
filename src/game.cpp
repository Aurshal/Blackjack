#include "game.h"
void Game::menu() {
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
    cout << "Available money: " << money << endl;
    cout << "Enter your bid: ";cin >> bid;
    if (bid > money) {
        cout << "You cannot bid more than your available money: " << endl;
        cout << "Enter your bid: ";cin >> bid;
    }

}

void Game::play() {
    gameCount++;
    system("clear");
    Art::art();
    cout << setw(65);
    cout << "======WELCOME TO THE GAME OF BLACKJACK=====\n";

    Game::init();
    Player::showCards();
    Computer::showCards();
    hitOrStandMenu();


}

void Game::chooseWinner() {
    Player::showCards();
    Computer::showCards(false);
    cout << endl << "Your total: " << Player::calcCards() << endl;
    cout << "Dealer's total: " << Computer::calcCards() << endl;


    if ((Player::calcCards() > Computer::calcCards() || Computer::calcCards() > 21) && Player::calcCards() <= 21) {
        money += bid;
        cout << "You WON!" << endl;
        cout << "\nAvailable money: " << money << endl;
    }
    else if ((Player::calcCards() < Computer::calcCards() || Player::calcCards() > 21) && Computer::calcCards() <= 21) {
        cout << "Dealer WON!" << endl;
        money -= bid;
        cout << "\nAvailable money: " << money << endl;

    }

    else if (Player::calcCards() == Computer::calcCards()) {
        cout << "Drawn";
        cout << "\nAvailable money: " << money << endl;

    }

}

void Game::resultMenu() {
    cout << "====Your game results======" << endl;
    cout << "Total hands: " << gameCount << endl;
    if (money > 1000)
        cout << "Money won: " << (money - 1000) << endl;
    else
        cout << "Money lost: " << (1000 - money) << endl;
}

void Game::playAgain() {
    string usrInput;
    cout << "\n\nPlay AGAIN? 'Y' for YES and 'N' for NO >> ";
    cin >> usrInput;
    if ((usrInput == "Y" || usrInput == "y") && money > 0)
        play();
    else {
        system("clear");
        Art::art();
        if (money < 0)
            cout << "==============YOU WERE OUT OF MONEY==========" << endl;
        resultMenu();
        money = 1000;
        gameCount = 0;
        menu();
    }
}

void Game::hitOrStandMenu() {
    do {
        cout << "\n\nHIT OR STAND?\nEnter:\n1. 'H' or 'h' for HIT\n2. 'S' or 's' for STAND\n\n>> ";cin >> hitOrStand;
        // while (Computer::calcCards() < 17)
        //     Computer::onHit();
        if (hitOrStand == "H" || hitOrStand == "h") {
            Player::onHit();
            Player::showCards();
            Computer::showCards();
            if (Player::calcCards() == 21) {
                cout << "\n\nYou got BLACKJACK! You WON!!" << endl;
                money += bid;
                cout << "\nAvailable money: " << money << endl;

                playAgain();
            }

            else if (Player::calcCards() > 21) {
                cout << endl << "Your total: " << Player::calcCards() << endl;
                cout << "Dealer's total: " << Computer::calcCards() << endl;
                money -= bid;
                cout << "\nDealer WON!" << endl;
                cout << "\nAvailable money: " << money << endl;
                playAgain();
            }
        }
        else if (hitOrStand == "S" || hitOrStand == "s") {
            while (Computer::calcCards() < 17)
                Computer::onHit();
            chooseWinner();
            playAgain();
        }
        else {
            cout << "\nPlease choose a correct key." << endl;
            hitOrStandMenu();
        }

    } while (hitOrStand == "H" || hitOrStand == "h");
}