#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

void GenerateCards() {

    extern int DCardT, DCard1, DCard2;
    extern int PCard1, PCard2;

    std::string DrawCards;
    extern int balance;
    extern int wager;

    

        AcePossible();

        if (PCard1 + PCard2 == 21 && DCard1 + DCard2 != 21) {
            wager *= 2;
            balance += wager;
            cout << "Congratulations! You won a blackjack! ";
            cout << "You have won " + std::to_string(wager) +  " credits, Your total balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay();
        }
        else if (PCard1 + PCard2 == 21 && DCard1 + DCard2 == 21) {
            cout << "Push!, the dealers second card was " + std::to_string(DCard2);
            cout << "You'll recieve your initial wager back\n Your balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay();
        }
        else if (PCard1 + PCard2 > 21 && PCard1 + PCard2 != 22) {
            balance -= wager;
            cout << "Bust!, you've lost your entire wager\nYour Balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay();

        }

}

