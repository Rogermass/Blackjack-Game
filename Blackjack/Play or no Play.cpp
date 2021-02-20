#include <iostream>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

void PlayorNoPlay() {

    int PlayorNot = 2;

    extern int PCard1, PCard2, PTotalCard;

    PCard1 = 0, PCard2 = 0, PTotalCard = 0;

    
    cout << "To Play another round enter '1', to quit the game enter '2': ";
    cin >> PlayorNot;
    cout << "\n";
    cout << "\n";

    while (PlayorNot == 1) {
        RunItAll();

    }
}
