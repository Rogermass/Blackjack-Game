#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using std::cout; using std::cin; using std::endl;




void Stand() {

    extern int wager;
    extern int balance;
    extern int PTotalCard;
    extern int DCard1, DCard2;
    extern int PCard1, PCard2; 
    extern int DCardT, DCardEx;

    std::vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 10, 10 };

    DCardT = DCard1 + DCard2;
    int x = 1;

 

    while (DCardT < 17) {


        srand((unsigned)time(0));
        DCardEx = cards[rand() % 13];

        if (x == 1) {
            cout << "The dealers second card is " + std::to_string(DCard1) + ". ";
            x--;
        }

        cout << "The dealers extra card is " + std::to_string(DCardEx) << endl;
        DCardT += DCardEx;
        cout << "The dealers total is " + std::to_string(DCardT) << endl;

        if (DCardT > 21) {

            wager *= 2;
            balance += wager;

            cout << "The Dealer busted, you win" << endl;
            cout << "Your balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay();

        }


    }

    PTotalCard += PCard1 + PCard2;

    if (PTotalCard == DCardT) {

        cout << "The Player and the Dealer have the same amount, nobody looses!" << endl;
        cout << "the dealers total was " + std::to_string(DCardT) + ". Your toal was " + std::to_string(PTotalCard) << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }

    else if (PTotalCard > DCardT) {

        wager *= 2;
        balance += wager;
        cout << "Congratulations you win, the dealers total was " + std::to_string(DCardT) + ". Your toal was " + std::to_string(PTotalCard) << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }

    else if (PTotalCard < DCardT) {

        balance -= wager;

        if (x == 1) {
            cout << "The dealer's hidden card was " + std::to_string(DCard1) + " You loose" << endl;
        }

        else {
            cout << "You loose the dealers total was " + std::to_string(DCardT) + ". Your toal was " + std::to_string(PTotalCard) << endl;
        }

        PlayorNoPlay();
    }

}