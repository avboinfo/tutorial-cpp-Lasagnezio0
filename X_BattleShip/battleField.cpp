/*
** battleField.cpp 
** Classe definita da me che spupazza le matrici
** Dondi Alessandro 3CIN 20/04/2024
*/

#include <iostream>

const int DIM = 10;
const char SHIP = 'X';
const char MISS = 'O';
const char HIT = '*';
const char VOID = '-';

class battleField{

    private:
    int m[DIM][DIM];

    public:

    battleField() {
        for(int i = 0; i < DIM; i++)
            for(int j = 0; j < DIM; j++) 
                m[i][j] = 97 + rand()%26;
    }

    battleField(char c){
        for(int i = 0; i < DIM; i++)
            for(int j = 0; j < DIM; j++) 
                m[i][j] = c;
    }
    
    char get(int x, int y){
        return m[x][y];
    }

    void put(int x, int y, char c){
        m[x][y] = c;
    }

    void stampa( ){
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                printf("%c ", m[i][j]);
                //std::cout << m[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;;
    }

    void bomb() {
        int x = rand()%DIM;
        int y =  rand()%DIM;   
        m[x][y] = HIT;
    }
    
    void placeHorizontalShip(int len) {
        if(len <= 0 || len >= DIM) return;
        int x = rand()% DIM;
        int y =  rand()% (DIM-len);
        for(int i = 0; i < len; i++) m[x][y + i] = SHIP;
    }

    void placeVerticalShip(int len) {
        if(len <= 0 || len >= DIM) return;
        int x = rand()% (DIM-len);
        int y =  rand()% DIM;
        for(int i = 0; i < len; i++) m[x + i][y] = SHIP;
    }
};
