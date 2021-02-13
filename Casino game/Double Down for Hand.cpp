#include <iostream>
#include <string>
#include "Header.h"
#include <vector>

using std::cout; using std::cin; using std::endl;

extern int wager1, wager2; 
extern int balance;
extern int DCard2, DCardT;
extern int standh1, PHand1, PHand2; 
extern std::vector<int> cards;
extern int x, t; 
extern std::string FirstH, SecondH; 

void DoubleDownforHand(int wagerd, int phandd, std::string handd) {

    wagerd *= 2;

    cout << "Your " + handd + " hands wager has doubled to " + std::to_string(wagerd) + "\n";

    

    srand((unsigned)time(0));

    int PHcardExd = cards[rand() % 13];
    
    if (PHcardExd == 11) {

        cout << "Choose if you want your extra card to be worth 11 or 1: ";
        cin >> PHcardExd;

    }
    else {
        cout << "Your extra card is " + std::to_string(PHcardExd) + "\n";
    }

    phandd += PHcardExd;

    if (phandd == 21 && DCardT != 21) {
        wagerd *= 3;
        balance += wagerd;
        cout << "Congratulations! You won a blackjack! ";
        cout << "Your have won " + std::to_string(wagerd) + ", Your total balance is " + std::to_string(balance) + "\n";
        
    }
    else if (phandd == 21 && DCardT == 21) {
        cout << "Push!, the dealers second card was " + std::to_string(DCard2);
        cout << "You'll recieve your initial wager back\nYour balance is " + std::to_string(balance) + "\n";
        
    }
    else if (phandd > 21) {
        
        cout << "Bust!, you've lost your " + handd + " hands entire wager, your total was " + std::to_string(phandd) << endl; 
 
    }
    
    if (handd == "first") {
        wager1 *= 2;
        PHand1 = phandd;
        
        if (phandd <= 21) {
            standh1 = 1;
        }
        else if (PHand1 > 21) {

            if (PHand2 >= 21) {
                StandforHand(wager1, PHand1, FirstH);
            }
            else {
                standh1 = 1;
            }

        }
    }
    else if (handd == "second") {
        wager2 *= 2;
        PHand2 = phandd;
        
        if (standh1 == 1) {
            t = 0;
            StandforHand(wager1, PHand1, FirstH);
            StandforHand(wager2, PHand2, SecondH);

        }
        else {
            t = 1; x = 1;
            StandforHand(wager2, PHand2, SecondH);
        }
    }

    

    
    
}
