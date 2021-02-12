#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Header.h"

using std::cout; using std::cin; using std::endl;



int HitforHand(int wagerh, int phand, std::string handh) {

    extern int balance;
    extern int wager1, wager2;
    extern int PTotalCard;
    extern int DCardT, DCard1, DCard2;
    DCardT = DCard1 + DCard2;
    extern int PCard1, PCard2;
    extern std::vector<int> cards;


    srand((unsigned)time(0));

    int PHcardEx = cards[rand() % 13];

    if (PHcardEx == 11) {

        cout << "Choose if you want your extra card to be worth 11 or 1: ";
        cin >> PHcardEx;

    }
    else {
        cout << "Your " + handh + " hands extra card is " + std::to_string(PHcardEx) + "\n";
    }

    phand += PHcardEx;

    if (phand == 21) {
        wagerh *= 3;
        balance += wagerh;
        cout << "Congratulations! your " + handh + " hand won a blackjack! \n";
       
    }
    else if (phand > 21) {
        //balance -= wagerh;
        cout << "Bust!, you've lost your " + handh + " hands entire wager \n"; //your total balance is " + std::to_string(balance) << endl;
        

    }
    return phand;
}