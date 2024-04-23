/*
** battleShip.cpp 
** Classe per giocare alla battaglia navale
** Dondi Alessandro 3CIN 20/04/2024
*/

#include <iostream>
#include "battleField.cpp"

class BattleShip{

    private:
    battleField mappa;
    battleField campo;
    int x = 0, y = 0;

    public:
    BattleShip(){
        mappa = battleField(VOID);
        campo = battleField(VOID);
        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);
        campo.placeHorizontalShip(2);
        campo.placeHorizontalShip(5);
    }

    bool checkWin(){
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                if(campo.get(i,j) == SHIP) return false;
            }
        }
        return true;
    }


    void play(){

        do{
            mappa.stampa();
            if(!playHand()) break;
        }while(!checkWin());
        
        std::cout << "\nEcco il campo dove erano tutte le navi" << std::endl;
        campo.stampa();


    }

    bool playHand(){
        std::cout << "Inserisci le coordinate dove lanciare la bomba(da 1 a "<< DIM << ")" << "\nPuoi inserire 0 per uscire dal programa" << std::endl;
        
        std::cout << "coordinata [x]: ";
        std::cin >> x;
        if(x == 0 || x > DIM) return false;
        else x--;
        
        std::cout << "\ncoordinata [y]: " << std::endl;
        std::cin >> y;
        if(y == 0 || y > DIM) return false;
        else y--;

        if(campo.get(x,y) == SHIP){
            campo.put(x,y, HIT);
            mappa.put(x,y, HIT);
            std::cout << "COLPITA LA NAVE A COORDINATE (" << x + 1 << " ; " << y + 1 << ")" << std::endl;
        }
        else{
            mappa.put(x , y , MISS);
            std::cout << "NESSUNA NAVE COLPITA A COORDINATE (" << x + 1 << " ; " << y + 1<< ")" << std::endl;
        }

        return true;
    }

};
