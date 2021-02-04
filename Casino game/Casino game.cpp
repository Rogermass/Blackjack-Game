
#include <iostream>
#include "Header.h"
#include <cstdlib>
#include <string>
#include <vector>



int balance = 1000;
int wager; 
int i; 
int PlayorNot;
int PTotalCard;
int DCard1, DCard2;
int PCard1, PCard2;
int DCardT, DCardEx;
char NextPlayA [];

std::string NextPlay; 
using std::cout; using std::cin;



std::vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 10, 10 };



int main()
{

    
    cout << "Sir this is a casino and you're Playing Blackjack!\n"; 
    
        
        WagerAmmount();

        GenerateCards();

        ChooseNextMove();

}

