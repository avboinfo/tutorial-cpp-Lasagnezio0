/*
** Vettore.cpp
** Classe Pila d'interi - Dondi Alessandro - 11/03/2024
*/


#include <iostream>

using namespace std;

/* private da un "information hiding" oppure in italiano è "incapsulamento": 
*/

class Pila {
    
    protected: // si riferisce agli attributi subito dopo, sono 
    int size, len, delta, agg = 0;
    int *v;

    public:
        Pila(int size, int delta){
            this ->size = size;
            //size = d;
            this->delta = delta;
            len = 0;
            v = new int[size]; // caro sistema operativo, trova spazio per un vettore grande size, e fallo puntare a v, allora v punta memoria
                              // fuori dallo stack e non dentro
        }

        void push(int n){
            if(len == size){
                //DEBUG cout << "Estendo da " << size << " a " << size + delta << endl;
                int *nuovov = new int[size + delta];
                for(int i = 0; i < size; i++) nuovov[i] = v[i];
                size += delta;
                delete[] v;
                v = nuovov;
                agg++;
            }
            v[len] = n;
            ++len;
        }

        int pop(){
            if(len == 0) { 
                cout << "\n ERRORE Pila vuota\n";
            }
            return v[--len];
        }

        int getElement(int index){
            return v[index];
        }

        void setElement(int index, int newValue){
            v[index] = newValue;
        }

        void print(){
            cout << "contenuto della pila: ";
            for( int i = 0; i < len; ++i) cout << v[i] << " ";
            cout << endl;
            cout << "\nHo risizeensionato il vettore " << agg << " volte" << endl;
        }

};


int main(int argc, char const *argv[])
{
    Pila vett(10, 2); //primo argomento è lunghezza vettore, il secondo è quanto si deve aggiungere ogni volta
    for(int i = 0; i < 100; i++)vett.push(i);
    for(int i = 0; i < 101; i++) cout << vett.pop() << " ";
    return 0;
}
