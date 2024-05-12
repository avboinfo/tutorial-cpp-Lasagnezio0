#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIM = 5;

void stampaMatrice(int matrice[DIM][DIM]){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << matrice[i][j] << "\t";
        }
        cout << endl;
    }
}

void riempiMatrice(int matrice[DIM][DIM]){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            matrice[i][j] = rand()%DIM;
        }
    }
}

int main(){

    srand(time(NULL));
    int m[DIM][DIM];
    cout << "Prima di essere riempita da valori a caso" << endl;
    stampaMatrice(m);
    cout << "dopo essere stata riempita di valori a caso" << endl;
    riempiMatrice(m);
    stampaMatrice(m);
}