/*
** battleField.cpp 
** Il programma che gioca alla battaglia navale
** Dondi Alessandro 3CIN 20/04/2024
*/

#include <iostream>
#include "battleShip.cpp"

int main(){

    std::cout << "Gioco della Battaglia Navale - Buon divertimento" << std::endl;
    BattleShip gioco = BattleShip();
    gioco.play();
    std::cout << "GAME OVER!" << std::endl;
    return 0;
}