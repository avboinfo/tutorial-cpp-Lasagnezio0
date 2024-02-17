/*
* Se in griglia c'è ZERO --> spazio vuoto
* Se in griglia c'è UNO --> X
* Se in griglia c'è DUE --> Y
*/

#include <iostream>

using namespace std;


class Tris{
public:
    int griglia[3][3];

    void reset_tab(){
        for(int i=0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j] = 0;
            }
        }
    }

    void stampa_griglia(){
        for(int i =0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }
    bool giocatore_uno(int x, int y){
        if( x > 2 || x < 0) return false;
        if( y > 2 || y < 0) return false;
        if(griglia[x][y] == 1 || griglia[x][y] == 2) return false;
        // se un false è vero, allora return false e esce fuori
        griglia[x][y] = 1;
        return true;
    }
    
    bool giocatore_due(int x, int y){
        if( x > 2 || x < 0) return false;
        if( y > 2 || y < 0) return false;
        if(griglia[x][y] == 1 || griglia[x][y] == 2) return false;
        // se un false è vero, allora return false e esce fuori
        griglia[x][y] = 2;
        return true;
    }
};

int main(int argc, char const *argv[]){
    Tris MyTris;
    MyTris.reset_tab();
   
    cout << "stato iniziale!" << endl;
    MyTris.stampa_griglia();

    int x = 0, y = 0;
    bool mossa_valida, mossa_valida2;
    
    do{
        cout << "gioca moosa del giocatore uno -->" << endl;
        cout << "coordinata [x] "; cin >> x; cout << "coordinata [y] "; cin >> y;
        mossa_valida = MyTris.giocatore_uno(x, y);

    } while(!mossa_valida);
    MyTris.stampa_griglia();

    do{
        cout << "gioca moosa del giocatore due -->" << endl;
        cout << "coordinata [x] "; cin >> x; cout << "coordinata [y] "; cin >> y;
        mossa_valida2 = MyTris.giocatore_due(x, y);
        
    } while(!mossa_valida2);
    MyTris.stampa_griglia();
    
    return 0;
}