#include <string>

#ifndef HEADER_H
#define HEADER_H

int WagerAmmount();

void GenerateCards();

void ChooseNextMove(); 

void Surrender();

void Hit();

void Stand();

void DoubleDown();

void Split();

void PlayorNoPlay(); 

void RunItAll();

void AcePossible(); 

void HitH1();

void HitH2(); 

int HitforHand(int wagerh, int phand, std::string handh);

void StandforHand(int wagers, int phands, std::string hands);

void SurrenderforHand(int wagersur, int phandsur, std::string handsur);

void DoubleDownforHand(int wagerd, int phandd, std::string handd); 

#endif