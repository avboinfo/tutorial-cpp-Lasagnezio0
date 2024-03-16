#include <iostream>

class Orario{
    private:
    int H, M, S;
    std::string pos;

    public:
    Orario(int H, int M, int S, std::string posizione){
        this -> H = H;
        this -> M = M;
        this -> S = S;
        pos = posizione;
    }

    void controlloOrario(){
        int x1 = 0, x2 = 0, x3 = 0;
        while( x1 != 1 && x2 != 1 && x3 != 1){
            x1 = controlloH();
            x2 = controlloM();
            x3 = controlloS();
        }
    }
    
    int controlloH(){
        while(H > 24 || H < 0){
            std::cout << "ore invalide del "<< pos << " tempo, reinserire: ";
            std::cin >> H;
            std::cout << "Nuove ore: " << H << std::endl;
        }
        return 1;
    }
    int controlloM(){
        while(M > 60 || M < 0){
            std::cout << "minuti invalidi del " << pos << " tempo, reinserire: ";
            std::cin >> M;
            std::cout << "nuovi minuti: " << M << std::endl;
        }
        return 1;
    }
    int controlloS(){
        while(S > 60 || S < 0){
            std::cout << "secondi invalidi" << pos << " tempo, reinserire: ";
            std::cin >> S;
            std::cout << "nuovi secondi: " << S << std::endl;
        }
        return 1;
    }

    
    
    std::string orarioStringa(){      
        return "sono le --> "+ std::to_string(H) + ":" + std::to_string(M) + ":" + std::to_string(S);
    }

    int calcoloSecondi(){
        long int x = 0;
        x = (H * 3600) + (M * 60) + S;
        return x;
    }


    int differenzaSecondi(int secondi){
        int diff;
        if(calcoloSecondi() > secondi){
            diff = calcoloSecondi() - secondi;
            return diff;
        }
        diff = secondi - calcoloSecondi();
        return diff;

    }

};

int main(){
    
    int sec1, sec2, differenza = 0;
    std::string orario1, orario2;
    
    Orario O1(14,42,31, "primo");
    Orario O2(23,23,59, "secondo");
    
    O1.controlloOrario();
    O2.controlloOrario();
    
    //ESEMPIO DEL CONTROLLO DA RIGA 16 A RIGA 48
    /*Orario O3(25,62,71, "terzo");
    O3.controlloOrario();
    std::string orario3 = O3.orarioStringa();
    std::cout << "terzo orario " << orario3 << std::endl;*/
    
    orario1 = O1.orarioStringa();
    orario2 = O2.orarioStringa();
    std::cout << "Per il primo orario sono le " << orario1 << ", mentre per il secondo orario sono le " << orario2 << std::endl;

    sec1 = O1.calcoloSecondi();
    sec2 = O2.calcoloSecondi();
    std::cout << "\nprimo orario in secondi: " << sec1 << ", secondo orario in secondi: " << sec2 << std::endl;

    differenza = O1.differenzaSecondi(sec2);
    std::cout << "\nLa differenza degli orari in secondi è di: " << differenza << std::endl;
}