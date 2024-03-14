/*
** Bicicletta.cpp
*/

#include <iostream>
using namespace std;

class Bicicletta {
  public:
    
    int raggio;
    string colore;
    //se la bicicletta non ha parametri, allora costrutto non parametri
    Bicicletta() {
        raggio=10;
        colore="Bianco";
    }

    //se la bicicletta ha parametri, allora costrutto "speciale", allora costrutto con parametri
    Bicicletta(int r, string c){
        raggio = r;
        colore = c;
    }
    
    void presentati() {
        cout << "Buongiorno, sono una bici di colore " << colore << " e con le ruote di raggio " << raggio << "!" << endl;
    }
};


int main()
{
    Bicicletta x;
    //Bicicletta y(14,"rossastro");

    x.presentati();

    Bicicletta y(12, "Rosso");
    y.presentati();

    return 0;
}
