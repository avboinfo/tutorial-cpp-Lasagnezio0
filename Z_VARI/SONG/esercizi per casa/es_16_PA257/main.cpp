#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int trovaMassimo(int vett[], int lunghezza){
    int max = vett[lunghezza - 1];
    if(lunghezza == 0) return 0;
    if(vett[lunghezza - 1] > vett[lunghezza]) max = vett[lunghezza - 1];
    return std::max(max,trovaMassimo(vett, lunghezza - 1));
}

int main(){
    srand(time(NULL));

    std::cout << "definisci quanto deve essere grande il vettore" << std::endl;
    int len;
    std::cin >> len;
    int n[len];

    for(int i = 0; i < len; i++) n[i] = rand()% 100;
    for(int i = 0; i < len; i++) std::cout << n[i] << " ";

    int max = 0;io mo
    max = trovaMassimo(n, len);
    std::cout << "\nIl massimo valore nel vettore è " << max << std::endl;
}