#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Header.h"

using std::cout; using std::cin; using std::endl;



void HitforHand(int wagerh, int phand, std::string handh) {

    extern int balance;
    extern int wager1, wager2;
    extern int PTotalCard;
    extern int DCardT, DCard1, DCard2;
    DCardT = DCard1 + DCard2;
    extern int PCard1, PCard2;
    extern std::vector<int> cards;

    
    srand((unsigned)time(0));

    int PHardEx = cards[rand() % 13];
    cout << "Your " + handh + " hands extra card is " + std::to_string(PHardEx) + "\n";

    phand += PHardEx;

    if (phand == 21) {
        wagerh *= 3;
        balance += wagerh;
        cout << "Congratulations! your " + handh + " hand won a blackjack! ";
    }
    else if (PTotalCard + PCard1 + PCard2 > 21) {
        balance -= wagerh;
        cout << "Bust!, you've lost your " + handh + " hands entire wager, your total was " + std::to_string(phand) << endl;
 

    }
    else {

        extern std::string NextPlay;

        cout << "Choose what you'd like to do next for your " + handh + " hand 'Stand', 'Hit', or 'Surrender': ";
        getline(cin, NextPlay);

        std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
            [](unsigned char c) { return std::tolower(c); });

        while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "surrender") {
            cout << "Try Again, choose 'Stand', 'Hit', 'Split' or 'Surrender': ";
            getline(cin, NextPlay);

            std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
                [](unsigned char c) { return std::tolower(c); });
        }




        if (NextPlay == "stand") {
            extern int standh1; 

            standh1 = 1;
        }
        else if (NextPlay == "hit") {
            HitforHand(wagerh, phand, handh);
        }
        else if (NextPlay == "surrender") {
            //SurrenderforHand(wagerh, phand);
        }
    }


}