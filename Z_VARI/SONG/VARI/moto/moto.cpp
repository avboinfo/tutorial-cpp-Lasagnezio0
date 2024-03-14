#include <iostream>

using namespace std;

class Moto{
    public:
    int velMax, tempi;
    string colore;

    Moto(int v, int tempi, string c){
        velMax = v;
        this->tempi = tempi;
        colore = c;
    }

    void presentati(){
        cout << "Sono una moto a " << tempi << " tempi, che raggiunge una velocità massima di " << velMax << " km/h  e di colore " << colore << endl;
    }

    bool probIncidente(){
        if(velMax >= 300) return true;
        return false;
    }
    
};

class GP : public Moto{
    public:
    void presentati2(){
        cout << " ah giusto sono una moto che partecipa alla MotoGP";
    }
};


int main(){

    bool x = 0;
    Moto a(300,2, "giallo");
    a.presentati();
    x = a.probIncidente();
    cout << x << endl;


    Moto b(150,4, "rossa");
    b.presentati();
    x = b.probIncidente();
    cout << x << endl;


    Moto c(220, 4, "verde");
    c.presentati();
    x = c.probIncidente();
    cout << x << endl;

    
    GP d(1000,1, "arcobaleno");
    d.presentati();
    d.presentati2();
    x = d.probIncidente();
    cout << x << endl;

}