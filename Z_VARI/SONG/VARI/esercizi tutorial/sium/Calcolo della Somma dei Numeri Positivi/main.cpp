#include <iostream>

using namespace std;

int main(){
    long long n = 1,somma = 0;

    while(true){
        cout << "Inserisci quanti numeri positivi vuoi, se inserisci un numero negativo, il programma finisce--> ";
        cin >> n;
        if(n < 0) break;
        somma += n;
    }

    cout << "La somma equivale a: " << somma << endl;
}