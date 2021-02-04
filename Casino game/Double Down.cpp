#include <iostream>
#include <string>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

void DoubleDown() {

    extern int wager;
    wager *= 2;

    cout << "Your wager has doubled to " + std::to_string(wager) + "\n";

    Hit();
}
