#include <iostream>
#include <string>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

void Surrender() {

    extern int wager;
    extern int balance, DCard2; 

    wager /= 2;
    balance -= wager;
    cout << "You'll recive half your wager back, but the dealers second card was " + std::to_string(DCard2) + "\n";
    cout << "Your balance is " + std::to_string(balance) + "\n";
    PlayorNoPlay();

}
