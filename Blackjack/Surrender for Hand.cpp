#include <iostream>
#include <string>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

void SurrenderforHand(int wagersur, int phandsur, std::string handsur) {

    
    extern int balance, DCard2;
    extern std::string FirstH, SecondH;
    extern int PHand1, PHand2, wager1, wager2; 
    extern int standh1; 
    extern int t, x; 
    extern std::string dd; 

    wagersur /= 2;
    balance -= wagersur;
    cout << "You'll recive half of your " + handsur + " hands wager back, but the dealers second card was " + std::to_string(DCard2) + "\n";
    cout << "Your balance is " + std::to_string(balance) + "\n";
    
    dd = " ";

    if (handsur == "first") {
        wager1 *= 2;
        PHand1 = phandsur;

        if (phandsur <= 21) {
            dd = "dd";
        }
        else if (PHand1 > 21) {

            if (PHand2 >= 21) {
                dd = "dd"; 
                StandforHand(wager1, PHand1, FirstH);
            }
            else {
                standh1 = 1;
            }

        }
    }
    else if (handsur == "second") {
        wager2 *= 2;
        PHand2 = phandsur;

        if (standh1 == 1) {
            t = 0;
            dd = "dd";
            StandforHand(wager1, PHand1, FirstH);
            dd = " ";
            StandforHand(wager2, PHand2, SecondH);

        }
        else {
            t = 1; x = 1;
            dd = " ";
            StandforHand(wager2, PHand2, SecondH);
        }
    }

}