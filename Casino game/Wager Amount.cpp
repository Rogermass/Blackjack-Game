#include <string>
#include <iostream>

using std::cout; using std::cin; using std::endl;

int WagerAmmount() {
    extern int wager;
    extern int balance;


    if (balance <= 0) {
        cout << "Sorry no credits available";
        exit(EXIT_SUCCESS);

    }

    else {
        std::cout << "Current credit balance " + std::to_string(balance) + "\n"; std::cout << "Enter a wager to start playing: ";
        std::cin >> wager;
    }




    while (wager > balance) {
        std::cout << "Not enough credits available\n";
        std::cout << "Enter wagering amount: ";
        std::cin >> wager;
    }


    return wager;
}