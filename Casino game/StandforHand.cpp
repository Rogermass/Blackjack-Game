#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using std::cout; using std::cin; using std::endl;


std::string busted;

void StandforHand(int wagers, int phands, std::string hands) {

    extern int wager;
    extern int balance;
    extern int PTotalCard;
    extern int DCard1, DCard2;
    extern int PCard1, PCard2;
    extern int DCardT, DCardEx;
    extern int standh1; 

    std::vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 10, 10 };

    DCardT = DCard1 + DCard2;
    int x = 1;

    extern int t;
        
 while (DCardT < 17) {


        srand((unsigned)time(0));
        DCardEx = cards[rand() % 13];

        if (x == 1) {

            cout << "The dealers second card is " + std::to_string(DCard1) + ". ";





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
            x = 0; 
        }
 }

 

    if (DCardT > 21) {
        wagers *= 2;
        balance += wagers;
        
        if (t == 1) {
            cout << "The Dealer busted, you win" << endl;
            cout << "Your balance is " + std::to_string(balance) + "\n";
            PlayorNoPlay(); 
        }
    }


    if (phands == DCardT) {

        cout << "Your " + hands + " hand is the same as the dealers total " << endl;
        cout << "the dealers total was " + std::to_string(DCardT) + ". Your toal was " + std::to_string(phands) << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        
    }

    else if (phands > DCardT) {

        wagers *= 2;
        balance += wagers;
        cout << "Congratulations you win, the dealers total was " + std::to_string(DCardT) + "Your " + hands + " hands total was " + std::to_string(phands) << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        
        
    }

    else if (phands < DCardT && DCardT < 21) {

        balance -= wagers;

        
         cout << "You loose the dealers total was " + std::to_string(DCardT) + "Your " + hands + " hands total was " + std::to_string(phands) + " Your balance is " + std::to_string(balance) + "\n";
         
        

        
    }

    if (t == 1) {
        PlayorNoPlay();
    }
    t = 1; 
}