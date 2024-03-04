/*
** Vettore.cpp
** Class vettore d'interi - Dondi ALessandro - 04/03/2024
*/


#include <iostream>

using namespace std;

class Vettore {
    
    protected: // si riferisce agli attributi subito dopo, sono 
    int dim, len, delta, agg = 0;
    int *v;

    public:
        Vettore(int dim, int delta){
            this ->dim = dim;
            //dim = d;
            this->delta = delta;
            len = 0;
            v = new int[dim]; // caro sistema operativo, trova spazio per un vettore grande dim, e fallo puntare a v, allora v punta memoria
                              // fuori dallo stack e non dentro
        }

        void add(int n){
            if(len == dim){
                //DEBUG cout << "Estendo da " << dim << " a " << dim + delta << endl;
                int *nuovov = new int[dim + delta];
                for(int i = 0; i < dim; i++) nuovov[i] = v[i];
                dim += delta;
                delete[] v;
                v = nuovov;
                agg++;
            }
            v[len] = n;
            ++len;
        }

        void print(){
            cout << "contenuto del vettore: ";
            for( int i = 0; i < len; ++i) cout << v[i] << " ";
            cout << endl;
            cout << "\nHo ridimensionato il vettore " << agg << " volte" << endl;
        }

};


int main(int argc, char const *argv[])
{
    Vettore vett(10, 2); //primo argomento è lunghezza vettore, il secondo è quanto si deve aggiungere ogni volta
    for(int i = 0; i < 100; i++)vett.add(33 * i);
    vett.print();
    return 0;
}
