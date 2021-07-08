#include <iostream>
using namespace std;

class Rules {
public:
    void showRules() {
        cout << "**************************************************************************\n";
        cout << "1. The goal of blackjack is to beat the dealer's hand without going over 21.\n";
        cout << "2. Face cards are worth 10. Aces are worth 1 or 11, whichever makes a better hand.\n";
        cout << "3. Each player starts with two cards, one of the dealer's cards is hidden until the end.\n";
        cout << "4. To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.\n";
        cout << "5. If you go over 21 you bust, and the dealer wins regardless of the dealer's hand.\n";
        cout << "6. If you are dealt 21 from the start (Ace & 10), you got a blackjack.\n";
        cout << "7. Blackjack usually means you win 1.5 the amount of your bet. Depends on the casino.\n";
        cout << "8. Dealer will hit until his/her cards total 17 or higher.\n";
        cout << "9. Doubling is like a hit, only the bet is doubled and you only get one more card.\n";
        cout << "10. Split can be done when you have two of the same card - the pair is split into two hands.\n";
        cout << "11. Splitting also doubles the bet, because each new hand is worth the original bet.\n";
        cout << "12. You can only double/split on the first move, or first move of a hand created by a split.\n";
        cout << "13. You cannot play on two aces after they are split.\n";
        cout << "14. You can double on a hand resulting from a split, tripling or quadrupling you bet.\n";
        cout << "**************************************************************************\n";
    }
};