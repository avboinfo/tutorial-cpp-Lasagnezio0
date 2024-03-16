#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void riempiMatrice(int matrice[10][10]){
    for(int i = 0; i < 10;i++){
        for(int j = 0; j < 10; j++){
            matrice[i][j] = rand()%100;
        }
    }
}

void stampaMatrice(int matrice[10][10]){
    for(int i = 0; i < 10;i++){
        for(int j = 0; j < 10; j++){
            cout << matrice[i][j] << "\t";
        }
        cout << endl;
    }
}

int controllaNumero(int matrice[10][10], int numero){
    int cont = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(matrice[i][j] == numero) cont++;
        }
    }
    return cont;
}

int controllaDiag(int matrice[10][10], int numero){
    int contDiag = 0;
    for(int i = 0; i < 10; i++){
        if(matrice[i][i] == numero) contDiag++;
    }
    return contDiag;
}

int main(){
    srand(time(NULL));
    int m[10][10], n = 0;
    riempiMatrice(m);
    int ext = 1;
    while(ext == 1){
        stampaMatrice(m);
        cout << "Inserisci un numero a piacere ed allora ti dirò quante volte questo è nella matrice e quante volte è nella diagonale principale: ";
        cin >> n;
        cout << "\nil tuo numero è nella matrice " << controllaNumero(m,n) << " volte, e si trova nella diagonale principale " << controllaDiag(m,n) << " volte" << endl;
        cout << "vuoi continuare? [0] per no : [1] per si: ";
        cin >> ext;
    }
    cout << "grazie per l'utilizzo ed arrivederci"<<endl;
}