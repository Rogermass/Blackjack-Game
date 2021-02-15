#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using std::cout; using std::cin; using std::endl;


std::string busted;

int c = 1;

void StandforHand(int wagers, int phands, std::string hands) {

    extern int wager;
    extern int balance;
    extern int PTotalCard;
    extern int DCard1, DCard2;
    extern int PCard1, PCard2;
    extern int DCardT, DCardEx;
    extern int standh1;
    extern int x; 
    extern std::string dd; 
    extern std::vector<int> cards;

    while (c == 1) {
        DCardT = DCard1 + DCard2;
        c--;
    }
    int z = 1;

    extern int t;

    while (DCardT < 17) {

        //TODO improve random system? 
        srand((unsigned)time(0));
        DCardEx = cards[rand() % 13];

        if (x == 1) {

            if (z == 1) {
                cout << "The dealers second card is " + std::to_string(DCard1) + ". ";
                z--;
            }


            if (DCardEx == 11) {

                if (DCardT < 11) {

                    DCardEx = 11;

                }
                else if (DCardT >= 11) {

                    DCardEx = 1;

                }
                else if (DCardT) {
                }
            }

            cout << "The dealers extra card is " + std::to_string(DCardEx) << endl;
            DCardT += DCardEx;
            cout << "The dealers total is " + std::to_string(DCardT) << endl;
        }
    }
    if (dd == "dd") {
        cout << "Your " + hands + " hand surrendered\n"; 
    }

    else if (phands == DCardT) {

        cout << "Push! Your " + hands + " hand is the same as the dealers total " << endl;
        cout << "the dealers total was " + std::to_string(DCardT) + ". Your toal was " + std::to_string(phands) << endl;
        cout << "Your balance remains at " + std::to_string(balance) + "\n";
        
    }
    
    else if(phands == 21) {
        cout << "Congratulations! your " + hands + " hand won a blackjack! ";

    }

    else if (phands > DCardT && phands < 21) {

        wagers *= 2;
        balance += wagers;
        cout << "Congratulations your " + hands + " hand wins, the dealers total was " + std::to_string(DCardT) + ". Your " + hands + " hands total was " + std::to_string(phands) << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        
        
    }

    else if (phands < DCardT && DCardT <= 21) {

         balance -= wagers;
         cout << "You loose, the dealers total is " + std::to_string(DCardT) + ". Your " + hands + " hands total is " + std::to_string(phands) + ". Your balance is " + std::to_string(balance) + "\n";

    }

    else if (DCardT > 21 && phands > 21 || phands > 21) {
        
        balance -= wagers; 
        cout << "Your " + hands + " hand busted, you loose, your balance is " + std::to_string(balance) + "\n"; 

    }
   
    else if (DCardT > 21) {
        
        wagers *= 2;
        balance += wagers;

        if (t == 1) {
            cout << "The Dealer busted, you win" << endl;
            cout << "Your balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay();
        }
        else {

        }
    }

    else {
        
        cout << "none of these";
    }

    if (t == 1) {
        
        PlayorNoPlay();
    }
    t = 1;
    
}