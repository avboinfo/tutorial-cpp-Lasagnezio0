#include <iostream>
#include "Posta.cpp"

int main(){
    Ufficio Saliceto;
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('R');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('F');
    Saliceto.NuovoUtente('F');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('R');
    Saliceto.NuovoUtente('S');
    Saliceto.NuovoUtente('R');
    Saliceto.NuovoUtente('R');
    Saliceto.NuovoUtente('F');

    Saliceto.stampUtenti();

    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('R');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('F');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');
    Saliceto.chiamataUtente('S');



    Saliceto.stampUtenti();
    return 0;
}