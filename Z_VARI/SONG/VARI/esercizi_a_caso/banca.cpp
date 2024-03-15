#include <iostream>

using namespace std;

class ContoBancario{
    public:
    int numeroConto; // Un intero che rappresenta il numero del conto.
    double saldo; //Un valore double che rappresenta il saldo attuale del conto.
    string nomePropietario;  //Una stringa che rappresenta il nome del proprietario del conto

    ContoBancario(int numeroConto, double saldo, string nomePropietario){
        this -> numeroConto = numeroConto;
        this -> saldo = saldo;
        this -> nomePropietario = nomePropietario;
    }

    void deposito(double importo){
        saldo += importo;
    }

    void prelievo(double importo){
        if(importo > saldo){
            cout << "Impossibile, stai chiedendo più soldi di quanti questo conto ne abbia" << endl;
        }else{
        saldo -= importo;
        }
    }

    void mostraInformazioniConto(){
        cout << numeroConto << "\n" << saldo << "\n" << nomePropietario << endl << endl;
    }
};

int main(){
    ContoBancario C1(234142,100,"Edoardo");
    ContoBancario C2(201932,2500,"Alessandro");

    C2.deposito(100);
    C2.mostraInformazioniConto();
    C2.prelievo(150);
    C2.mostraInformazioniConto();

    C1.prelievo(50);
    C1.mostraInformazioniConto();

    C2.deposito(50);
    C2.mostraInformazioniConto();
}