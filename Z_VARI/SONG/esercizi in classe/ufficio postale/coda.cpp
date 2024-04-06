/*
** Vettore.cpp
** Classe Coda d'interi - Dondi Alessandro - 6/4/2024
*/


#include <iostream>

using namespace std;

/* private da un "information hiding" oppure in italiano è "incapsulamento": 
*/

class Coda {
    
    protected: // si riferisce agli attributi subito dopo, sono 
    int size, start,stop = 0;
    int *v;

    public:
        Coda(int size){
            this ->size = size;
            v = new int[size]; // caro sistema operativo, trova spazio per un vettore grande size, e fallo puntare a v, allora v punta memoria
                              // fuori dallo stack e non dentro
            start = stop = 0;
        }

    void enter(int val){
        if (stop >= size){
            cout << "coda piena!";
            return;
        }
        v[stop] = val;
        stop++;
    }
    int exit(){
        if(start >= stop){
            cout << "Coda vuota!";
            return 0;
        }

        return v[start++]; 
    }

    void stampa(){
        cout << "elementi in coda: " << endl;
        for(int i = start; i< stop;i++) cout << v[i] << endl;
        cout << "--------------------" << endl;
    }

};