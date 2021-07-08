#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include <cstdlib> 
#include <ctime>

class Cards {
protected:
    int cards[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
public:
    int genRanIndex(int n);
    int genCards(int n);
    // void setCards(vector <int>);
    // void showCards(vector <int>);
    // int calcCards(vector <int>);
};


