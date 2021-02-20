#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Header.h"

using std::cout; using std::cin; using std::endl; 



void Hit() {

    extern int balance;
    extern int wager;
    extern int PTotalCard;
    extern int DCardT, DCard1, DCard2;
    DCardT = DCard1 + DCard2;
    extern int PCard1, PCard2;
    extern std::vector<int> cards; 


    srand((unsigned)time(0));
    
    int PCardEx = cards[rand() % 13];
    
    
    if (PCardEx == 11) {

        cout << "Choose if you want your extra card to be worth 11 or 1: ";
        cin >> PCardEx;

    }
    else {
        cout << "Your extra card is " + std::to_string(PCardEx) + "\n";
    }

    PTotalCard += PCardEx;

    if (PTotalCard + PCard1 + PCard2 == 21 && DCardT != 21) {
        wager *= 3;
        balance += wager;
        cout << "Congratulations! You won a blackjack! ";
        cout << "Your have won " + std::to_string(wager) + ", Your total balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }
    else if (PTotalCard + PCard1 + PCard2 == 21 && DCardT == 21) {
        cout << "Push!, the dealers second card was " + std::to_string(DCard2);
        cout << "You'll recieve your initial wager back\nYour balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }
    else if (PTotalCard + PCard1 + PCard2 > 21) {
        balance -= wager;
        cout << "Bust!, you've lost your entire wager, your total was " + std::to_string(PTotalCard + PCard1 + PCard2) << endl; cout << "Your Balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();

    }
    else {

        extern std::string NextPlay;

        cout << "Choose what you'd like to do next, 'Stand', 'Hit', or 'Surrender': ";
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
            Stand();
        }
        else if (NextPlay == "hit") {
            Hit();
        }
        else if (NextPlay == "surrender") {
            Surrender();
        }
    }


}