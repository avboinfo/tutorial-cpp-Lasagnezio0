#include <iostream>
#include <cstdlib>
#include <ctime>

class masterMind
{
private:
    int n_moves;
    std::string last_move;
    
    static const int DIM_VALID_MOVE = 4;
    int valid_move[DIM_VALID_MOVE];
    int secret_code[DIM_VALID_MOVE];
    bool victory;

    bool sanitize_input(){
        if(DIM_VALID_MOVE != last_move.size()) return false;
        for (int i = 0; i < last_move.size(); i++)
        {
            char c = last_move[i];
            if(c >= '0' && c <= '9'){
                valid_move[i] = c - '0';
            } else if(c == '-'){
                valid_move[i] = -1; // il trattino viene convertito in -1
            }else return false;
        }
        return true;
               
    }
    //generazione di codice segreto casuale
    void generate_secret_code(){
        srand(time(NULL));
        for(int i = 0; i < DIM_VALID_MOVE; i++){
            secret_code[i] = rand()% 10;
            //std::cout << secret_code[i];
        }
    }

    void print_secret(){
        for(int i = 0; i < DIM_VALID_MOVE; i++){
            std::cout << secret_code[i];
        }
        std::cout << std::endl;
    }
    
    int* copia_vettore(int og_vettore[]){
        
        static int copy_vect[DIM_VALID_MOVE]; // static avvisa che la parte di memoria del vettore non venga cancellata una volta finito il metodo
        //copio il vettore risposta affinchè esso non venga modificato
        
        for(int i = 0; i < DIM_VALID_MOVE; i++){
            copy_vect[i] = og_vettore[i];
        }
        
        return copy_vect;
    }

    void copia_vettore_bis(int vettore_originale[], int vettore_copia[], int dim_vet){
        for(int i = 0; i < DIM_VALID_MOVE; i++){
            vettore_copia[i] = vettore_originale[i];
        }
    }


public:

    masterMind(){
        n_moves = 0;
        last_move = "";
        victory = false;
        generate_secret_code();
    };

    void readNewMove(){
        do{
            std::cout << "tentativo " <<  n_moves + 1 << ": ";
            std::getline(std::cin, last_move); //getline legge anche gli spazi, si ferma a leggere quando incontra un a capo 
        }while(!sanitize_input());

        n_moves++;
    }

    void move_result(){
        int ball = 0;
        int strike = 0;

        int *copy_secret = copia_vettore(secret_code);

        // controllo ball e strike
        for(int j = 0; j < DIM_VALID_MOVE; j++){
            for(int i = 0; i < DIM_VALID_MOVE; i++){
                
                if(valid_move[i] == copy_secret[i]){
                    strike++;
                    copy_secret[i] = -2;
                    continue;
                }
                if(valid_move[j] == copy_secret[i]){
                    ball++;
                    copy_secret[i] = -2;
                    continue;
                }
            }
        }

        if(strike == DIM_VALID_MOVE) victory = true;

        std::cout << "Here your strike [" << strike << "] and ball [" << ball << "]" << std::endl;
    }

    bool can_continue(){
        if(victory == true || n_moves >= 9) return false;
        return true;
    }

    void ending_situation(){
        print_secret();
        if(victory == true) std::cout << "Hai vinto!" << std::endl;
        else std::cout << "Mi dispiace, hai perso!" << std::endl;
    }
    
};

