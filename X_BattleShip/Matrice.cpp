/*
** Matrice.cpp 
** Classe definita da me che spupazza le matrici
** Dondi Alessandro 3CIN 13/04/2024
*/

#include <iostream>

class Matrice{

    private:
    int n;
    int m[10][10];

    public:
    Matrice(int n){
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++) 
                m[i][j] = n;
    }
    
    void stampa( ){
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                std::cout << m[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << "--------------------------------------------------------------------------------" << std::endl;;
    }
};

int main(){

    Matrice M1 = Matrice(5);
    M1.stampa();
}