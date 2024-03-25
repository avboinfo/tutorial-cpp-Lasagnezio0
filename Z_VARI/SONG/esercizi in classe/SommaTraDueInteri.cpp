/*
* Dondi Alessandro
** 25/3/2024 3CIN 
*/

#include <iostream>

int sommaRicorsiva(int n1, int n2){
    do{
        if(n1 == n2) break;
        return n1 + sommaRicorsiva(n1 + 1, n2);
    }while(n1 != n2);
}

int main(){
    int m, n, somma;
    m = n = somma = 0;
    
    
    std::cout << "attenzione: il primo numero deve essere minore del secondo" << std::endl;
    std::cout << "Inserisci il primo numero: " << std::endl;
    std::cin >> m;
    std::cout << "Inserisci il secondo numero: " << std::endl;
    std::cin >> n;

    somma = sommaRicorsiva(m,n);
    std::cout << "La somma tra i numeri compresi tra i due numeri è " << somma << std::endl;
    
    return 0;
}