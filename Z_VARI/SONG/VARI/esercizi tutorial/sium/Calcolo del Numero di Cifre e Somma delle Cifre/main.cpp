#include <iostream>

int main() {
    int numero;

    // Chiede all'utente di inserire un numero intero positivo
    do {
        std::cout << "Inserisci un numero intero positivo: ";
        std::cin >> numero;

        if (numero <= 0) {
            std::cout << "Il numero deve essere positivo. Riprova." << std::endl;
        }
    } while (numero <= 0);

    int numeroTemp = numero;
    int contaCifre = 0;
    int sommaCifre = 0;

    // Calcola il numero di cifre e la somma delle cifre
    while (numeroTemp > 0) {
        int cifra = numeroTemp % 10;
        sommaCifre += cifra;
        numeroTemp /= 10;
        contaCifre++;
    }

    std::cout << "Il numero di cifre del numero " << numero << " è: " << contaCifre << std::endl;
    std::cout << "La somma delle cifre del numero " << numero << " è: " << sommaCifre << std::endl;

    return 0;
}
