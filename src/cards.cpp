#include <iostream>
#include <vector>
#include "cards.h"

using namespace std;

int Cards::genRanIndex(int n = 1) {
    int ranIndex;
    srand(static_cast<unsigned int>(std::time(nullptr)) * n);
    ranIndex = (rand() % 13);
    // cout << "Random index: " << ranIndex << endl;
    return ranIndex;
}

int Cards::genCards(int n = 1) {
    return cards[genRanIndex(n)];
}

