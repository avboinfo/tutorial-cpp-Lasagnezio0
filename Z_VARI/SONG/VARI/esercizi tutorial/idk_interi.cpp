#include <iostream>

using namespace std;

double sommaNumeri(double n1, double n2){
    double somma = 0;
    somma = n1 + n2;
    return somma;
}


struct {
  string brand;
  string model;
  int year;
} myCar1, myCar2; // We can add variables by separating them with a comma here


int main(){

    int x = 20;
    float x1 = 2; //tiene i numeri con virgola
    double x2 = 23; // tiene i numeri con la virgola ma con piu precisione
    double x3 = 17;
    short x4 = 3; // fa schifo
    char c; string ciao; //utilizzate per memorizzazione caratteri

    int v[5];
    int m[5][5];

    if(x > x1) cout << "Ciao" << endl;
    else cout << "Pallone da calcio" << endl;


    switch(x){

        case 0:
            cout << "mangio banane" << endl;
            break;
        case 1:
            cout << "mangio pere" << endl;
            break;
        case 2:
            cout << "mangio mele" << endl;
            break;
        default:
            cout << "Mangio carne" << endl;
    }

    //il ciclo while non fa per forza una volta il codice, se la condizione risulta falsa, allora passa immediatamente oltre
    while(x1 > 0){
        cout << "questo programma fa pena" << endl;
        x1--; // x1 = x1 - 1
    }

    cout << "X1 ARRIVATO A 0, GODO!" << endl;

    //il do while invece fa almeno una volta le istruzioni, anche se la condizione risulta falsa
    do{
        cout << "Il do while lo fa almeno una volta ugualmente" << endl;
    }while(x1 != 0);

    //due cicli for che uno riempe il vettore, uno lo stampa
    for(int i = 0; i < 5; i++){
        v[i] = i;
    }
    for(int i = 0; i < 5; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    cout << sommaNumeri(x2,x3);


    // Put data into the first structure
    myCar1.brand = "BMW";
    myCar1.model = "X5";
    myCar1.year = 1999;

    // Put data into the second structure
    myCar2.brand = "Ford";
    myCar2.model = "Mustang";
    myCar2.year = 1969;

    // Print the structure members
    cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
    cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
}