/*
* Se in griglia c'è ZERO --> spazio vuoto
* Dondi Alessandro 3CIN 25/02/2024
* Tris versione FINALE
*/

#include <iostream>

using namespace std;


class Tris{
public:
    char griglia[3][3];

    void reset_tab(){
        for(int i=0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j] = ' ';
            }
        }
    }

    void stampa_griglia(){
        cout << "------------- " << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << griglia[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }
    bool giocatore_uno(int x, int y){
        if( x > 2 || x < 0) return false;
        if( y > 2 || y < 0) return false;
        if(griglia[x][y] == 'X' || griglia[x][y] == 'O') return false;
        // se un false è vero, allora return false e esce fuori
        griglia[x][y] = 'X';
        return true;
    }
    
    bool giocatore_due(int x, int y){
        if( x > 2 || x < 0) return false;
        if( y > 2 || y < 0) return false;
        if(griglia[x][y] == 'X' || griglia[x][y] == 'O') return false;
        // se un false è vero, allora return false e esce fuori
        griglia[x][y] = 'O';
        return true;
    }

    int controlla_vincitore(){
        int risultato;
        for(int i = 0; i < 3; i++){
            risultato = controlla_colonna(i);
            if(risultato != 0) return risultato;

            risultato = controlla_riga(i);
            if(risultato != 0) return risultato;

        }
        /*risultato = controlla_diagonale();
        return risultato;*/
        
        // compatto riga 60, 61
        return controlla_diagonale();
    }
private:
    int controlla_colonna(int col){
        int acc_uno = 0;
        int acc_due = 0;
        for(int i = 0; i < 3; i++){
            int cella = griglia[i][col];
            if(cella == 'X') ++acc_uno;
            else if(cella == 'O') ++acc_due;
        }
        if(acc_uno == 3) return 1;
        else if(acc_due == 3) return 2;
        return 0;
    }

    int controlla_riga(int rig){
        int acc_uno = 0;
        int acc_due = 0;
        for(int i = 0; i < 3; i++){
            int cella = griglia[rig][i];
            if(cella == 'X') ++acc_uno;
            else if(cella == 'O') ++acc_due;
        }
        if(acc_uno == 3) return 1;
        else if(acc_due == 3) return 2;
        return 0;
    }

    int controlla_diagonale(){
        int acc_uno = 0;
        int acc_due = 0;
        for(int i = 0; i < 3; i++){
            int cella = griglia[i][i];
            if(cella == 'X') ++acc_uno;
            else if(cella == 'O') ++acc_due;
        }
        if(acc_uno == 3) return 1;
        else if(acc_due == 3) return 2;

        //check diagonale secondaria
        acc_uno = 0;
        acc_due = 0;
        for(int i = 0; i < 3; i++){
            int cella = griglia[i][2 - i];
            if(cella == 'X') ++acc_uno;
            else if(cella == 'O') ++acc_due;
        }
        if(acc_uno == 3) return 1;
        else if(acc_due == 3) return 2;

        // nessuno ha vinto, gg
        return 0;
    }

};

int main(int argc, char const *argv[]){
    Tris MyTris;
    MyTris.reset_tab();
   
    cout << "stato iniziale!" << endl;
    MyTris.stampa_griglia();

    int x = 0, y = 0;
    bool mossa_valida, mossa_valida2;
    int vincitore = 0;
    int mosse_totali = 0;
    
    while(mosse_totali < 9){
        do{
        cout << "gioca mossa del giocatore uno -->" << endl;
        cout << "coordinata [x] "; cin >> x; cout << "coordinata [y] "; cin >> y;
        mossa_valida = MyTris.giocatore_uno(x, y);
        } while(!mossa_valida);
        MyTris.stampa_griglia();

        vincitore = MyTris.controlla_vincitore();
        if(vincitore != 0) break;
        // controlla pareggio
        mosse_totali++;
        if(mosse_totali == 9) break;

        do{
        cout << "gioca mossa del giocatore due -->" << endl;
        cout << "coordinata [x] "; cin >> x; cout << "coordinata [y] "; cin >> y;
        mossa_valida2 = MyTris.giocatore_due(x, y); 
        } while(!mossa_valida2);
        MyTris.stampa_griglia();

        vincitore = MyTris.controlla_vincitore();
        if(vincitore != 0) break;

        mosse_totali++;
    }

    if(vincitore  == 1) cout << "bravo giocatore 1, hai vinto!" << endl;
    else if(vincitore == 2) cout << "bravo giocatore 2, hai vinto!" << endl;
    else cout << "PAREGGIO!!!!!!!!!" << endl;
    
    return 0;
}