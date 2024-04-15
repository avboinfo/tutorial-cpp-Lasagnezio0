/*
** Matrice.cpp 
** Classe definita da me che spupazza le matrici
** Dondi Alessandro 3CIN 13/04/2024
*/

#include <iostream>

const int DIM = 10;

class Matrice{

    private:
    int m[DIM][DIM];

    public:

    Matrice() {
        for(int i = 0; i < DIM; i++)
            for(int j = 0; j < DIM; j++) 
                m[i][j] = 97 + rand()%26;
    }

    Matrice(char c){
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
        m[x][y] = '*';
    }
    
    void placeHorizontalShip(int len) {
        if(len <= 0 || len >= DIM) return;
        int x = rand()% DIM;
        int y =  rand()% (DIM-len);
        for(int i = 0; i < len; i++) m[x][y +i] = '0';
    }

    void placeVerticalShip(int len) {
        if(len <= 0 || len >= DIM) return;
        int x = rand()% (DIM-len);
        int y =  rand()% DIM;
        for(int i = 0; i < len; i++) m[x + i][y] = '0';
    }
};

int main(){
    srand(time(NULL));
    Matrice mappa = Matrice('-');
    Matrice campo = Matrice('-');

    campo.placeHorizontalShip(3);
    campo.placeVerticalShip(4);
    campo.placeHorizontalShip(2);
    campo.placeVerticalShip(3);
    campo.placeHorizontalShip(5);

    //lancia 20 bombe a caso(sium)
    for(int i = 0; i < 20; i++){
        int x = rand()%DIM;
        int y =  rand()%DIM;   
        if(campo.get(x,y) == '0') mappa.put(x,y,'*');
    }
    mappa.stampa();
    return 0;
}