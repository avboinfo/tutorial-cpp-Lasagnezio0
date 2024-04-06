#include <iostream>
#include "coda.cpp"
 
class Ufficio{
    private:
    Coda codaS = Coda(1000);
    Coda codaR = Coda(1000);
    Coda codaF = Coda(1000);

    int contS = 1, contR = 1, contF = 1;

    public:
    void NuovoUtente(char categoria){
        if (categoria == 'S'){
            codaS.enter(contS);
            contS++;
        }else if (categoria == 'R'){
            codaR.enter(contR);
            contR++;
        }else if (categoria == 'F'){
            codaF.enter(contF);
            contF++;
        }else{
            std::cout << "categoria non accettata in questo ufficio" << std::endl;
        }
    }

    void chiamataUtente(char categoria){
        if (categoria == 'S'){
            codaS.exit();
            contS--;
        }else if (categoria == 'R'){
            codaR.exit();
            contR--;
        }else if (categoria == 'F'){
            codaF.exit();
            contF--;
        }else{
            std::cout << "categoria non accettata in questo ufficio" << std::endl;
        }
    }

    void stampUtenti(){
        std::cout << "\nEcco tutte le persone in fila dei diversi sportelli" << std::endl;
        std::cout << "nello sportello Spedizione ci sono " << contS << " persone" << std::endl;
        std::cout << "nello sportello Ricezione ci sono " << contR << " persone" << std::endl;
        std::cout << "nello sportello Finanziario ci sono " << contF << " persone" << std::endl;
    }
};