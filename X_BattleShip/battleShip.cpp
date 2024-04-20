/*
** battleField.cpp 
** Classe per giocare alla battaglia navale
** Dondi Alessandro 3CIN 20/04/2024
*/

#include <iostream>
#include "battleField.cpp"

class BattleShip{

    private:
    battleField mappa;
    battleField campo;

    public:
    BattleShip(){
        mappa = battleField(VOID);
        campo = battleField(VOID);
        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);
        campo.placeHorizontalShip(2);
        campo.placeHorizontalShip(5);
    }


    void play(){
        //lancia 20 bombe a caso(sium)
        for(int i = 0; i < 20; i++){
            int x = rand()%DIM;
            int y =  rand()%DIM;
            if(campo.get(x,y) == HIT) continue;
            if(campo.get(x,y) == SHIP){
                campo.put(x,y, HIT);
                mappa.put(x,y, HIT);
            }
            else mappa.put(x , y , MISS);
        }
        mappa.stampa();

        ask();
        campo.stampa();
        mappa.stampa();

    }

    void ask(){
        int x = 0, y = 0;
        std::cout << "Inserisci le coordinate dove lanciare la bomba" << std::endl;
        std::cout << "coordinata [x]: ";
        std::cin >> x;
        std::cout << "\ncoordinata [y]: " << std::endl;
        std::cin >> y;
        if(campo.get(x,y) == SHIP){
            campo.put(x,y, HIT);
            mappa.put(x,y, HIT);
        }
        else mappa.put(x , y , MISS);
    }

};
