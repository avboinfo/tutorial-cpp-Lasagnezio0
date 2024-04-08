/*
** Dondi Alessandro 06/04/2024 - 08/04/2024 3CIN
*/
#include <iostream>
#include "coda.cpp"
 
class Ufficio{
    
    /*private:
    string nome;
    Coda codaS, codaR, codaF;
    int contS, contR, contF;

    public:
    Ufficio(string nome){
        this -> nome =  nome;
        codaS = Coda(1000);
        codaR = Coda(1000);
        codaF = Coda(1000);
        contS = contR = contF = 0;
    }*/
    private:
    Coda codaS = Coda(1000);
    Coda codaR = Coda(1000);
    Coda codaF = Coda(1000);

    int contS = 0, contR = 0, contF = 0;

    public:
    void Benvenuto(){
        std::cout << "---------Benvenuto nell'ufficio postale di via saliceto---------" << std::endl;
        std::cout << "Avrai il pieno controllo dell'ufficio postale, potrai aggiungere persone, togliere persone e stampare le diverse file" << std::endl;
        menu();
    }

    private:
    void menu(){
        int ext = 0;
        do {
            int risp;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "Ecco il menù dell'ufficio postale" << std::endl;
            std::cout << "[1] Aggiungi persona nella fila" << "\t" << "[2] rimuovi persona dalla fila" << "\n" << "[3] stampa le diverse file" << "\t" << "[4] esci dal programma" << std::endl;
            std::cout << "opzione: ";std::cin >> risp;
            if(risp == 1){
                char categoria;
                std::cout << "Inserisci in che sportello vuoi questa persona tra S(spedizione), R(ricezione) e F(finanziario), inserisci solo la lettera iniziale" << std::endl;
                cin >> categoria;
                NuovoUtente(categoria);
            }else if(risp == 2){
                char categoria;
                std::cout << "Inserisci in che sportello vuoi questa persona tra S(spedizione), R(ricezione) e F(finanziario), inserisci solo la lettera iniziale" << std::endl;
                cin >> categoria;
                chiamataUtente(categoria);
            }else if(risp == 3){
                std::cout << "stampo le file degli diversi sportelli: " << std::endl;
                stampUtenti();
            }else if(risp == 4){
                std::cout << "grazie per avere utilizzato di questo ufficio postale" << std::endl;
                ext = 1;
            }else{
                std::cout << "opzione non valida, riprova";
            }
            std::cout << "\n";
        }while(ext != 1);
    }
    void NuovoUtente(char categoria){
        if (categoria == 'S' || categoria == 's'){
            std::cout << "aggiunta una persona alla coda per lo sportello spedizione" << std::endl;
            codaS.enter(contS++);
        }else if (categoria == 'R' || categoria == 'r'){
            std::cout << "aggiunta una persona alla coda per lo sportello ricezione" << std::endl;
            codaR.enter(contR++);
        }else if (categoria == 'F' || categoria == 'f'){
            std::cout << "aggiunta una persona alla coda per lo sportello finanziario" << std::endl;
            codaF.enter(contF);
            contF++;
        }else{
            std::cout << "sportello non valido" << std::endl;
        }
    }

    void chiamataUtente(char categoria){
        if (categoria == 'S' || categoria == 's'){
            if(contS <= 0){
                std::cout << "sportello spedizione vuoto, impossibile rimuovere utenti" << std::endl;
                return;
            }
            codaS.exit();
            contS--;
        }else if (categoria == 'R' || categoria == 'r'){
            if(contR <= 0){
                std::cout << "sportello ricezione vuoto, impossibile rimuovere utenti" << std::endl;
                return;
            }
            codaR.exit();
            contR--;
        }else if (categoria == 'F' || categoria == 'f'){
            if(contF <= 0){
                std::cout << "sportello finanziario vuoto, impossibile rimuovere utenti" << std::endl;
                return;
            }
            codaF.exit();
            contF--;
        }else{
            std::cout << "categoria " << categoria << " non accettata in questo ufficio" << std::endl;
        }
    }

    void stampUtenti(){
        std::cout << "\nEcco tutte le persone in fila nei diversi sportelli" << std::endl;
        std::cout << "nello sportello Spedizione ci sono " << contS << " persone" << std::endl;
        std::cout << "nello sportello Ricezione ci sono " << contR << " persone" << std::endl;
        std::cout << "nello sportello Finanziario ci sono " << contF << " persone" << std::endl;
    }
};