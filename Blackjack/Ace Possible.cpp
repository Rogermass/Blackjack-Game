#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Header.h"

using std::cout; using std::cin; using std::endl;


void AcePossible() {
    extern int balance;
    extern std::vector<int> cards;

    
    
    extern int PCard1; extern int PCard2;
    extern int DCard1; extern int DCard2;
    
    
    
    srand((unsigned)time(0));
    PCard1 = cards[rand() % 13];
    PCard2 = cards[rand() % 13];
    DCard1 = cards[rand() % 13];
    DCard2 = cards[rand() % 13];

    PCard1 = 5; 
    PCard2 = 5; 
    

    if (PCard1 == 11 && PCard2 == 11) {

        cout << "The dealers shown card is " + std::to_string(DCard2) + "\n";

        cout << "Your two cards are aces choose if you want the first one to be worth 11 or 1: ";
        cin >> PCard1;
        cout << "Choose if you want the second one to be worth 11 or 1: ";
        cin >> PCard2;

    }
    else if (PCard1 == 11 && PCard2 != 11) {

        cout << "The dealers shown card is " + std::to_string(DCard2) + "\n";

        cout << "Your first cards is " + std::to_string(PCard2) + ", ";
        cout << "your second card is an Ace, do you want it to be worth 11 or 1? ";
        cin >> PCard1;

    }
    else if (PCard2 == 11 && PCard1 != 11) {
        cout << "The dealers shown card is " + std::to_string(DCard2) + "\n";

        cout << "Your first cards is " + std::to_string(PCard1) + ", ";
        cout << "your second card is an Ace, do you want it to be worth 11 or 1? ";
        cin >> PCard2;

    }
    else {

        cout << "Your first cards is " + std::to_string(PCard1) + " your second card is " + std::to_string(PCard2) + "\n";
        cout << "The dealers shown card is " + std::to_string(DCard2) + "\n";
    }

    if (DCard1 == 11 && DCard2 == 11) {

        DCard1 = 1;

    }
    else if (DCard1 == 11 && DCard2 >= 10) {

        DCard1 = 1;

    }
    else if (DCard2 == 11 && DCard1 >= 10) {

        DCard2 = 1;

    }

   
}
