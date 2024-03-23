#include <iostream>
#include "masterMind.cpp"

int main(int argc, char const *argv[])
{
    masterMind prova = masterMind();
    
    std::cout << "Benvenuto al gioco di mastermind!" << std::endl;
    
    do{
        prova.readNewMove();
        prova.move_result();
    }while(prova.can_continue());

    prova.ending_situation();
    return 0;
}
