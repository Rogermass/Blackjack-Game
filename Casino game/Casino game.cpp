
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

char NextPlayA [];

std::string NextPlay; 
using std::cout; using std::cin;

int main()
{

    
    cout << "Sir this is a casino and you're Playing Blackjack!\n"; 
    
        
        WagerAmmount();

        GenerateCards();

        ChooseNextMove();
       
   
    


    

}

