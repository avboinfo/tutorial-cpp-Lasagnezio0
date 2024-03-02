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

    bool sanitize_input(){
        if(DIM_VALID_MOVE != last_move.size()) return false;
        for (int i = 0; i < last_move.size(); i++)
        {
            char c = last_move[i];
            if(c >= '0' && c <= '9'){
                valid_move[i] = c - '0';
            } else if(c == '-'){
                valid_move[i] = -1;
            }else return false;
        }
        return true;
               
    }
    //generazione di codice segreto casuale
    void generate_secret_code(){
        srand(time(NULL));
        for(int i = 0; i < DIM_VALID_MOVE; i++){
            secret_code[i] = rand()% 10;
        }
    }

    bool check(){
        int ball = 0;
        int strike = 0;
        for(int j = 0; j < DIM_VALID_MOVE; j++){
            for(int i = 0; i < DIM_VALID_MOVE; i++){
                if(valid_move[i] == secret_code[i]) strike++;
                if(valid_move[j] == secret_code[i]) ball++;
            }

        }
    }

public:

    masterMind(){
        n_moves = 0;
        last_move = "";
    };

    void readNewMove(){
        do{
            std::cout << n_moves + 1 << ": ";
            std::getline(std::cin, last_move); //getline legge anche gli spazi, si ferma a leggere quando incontra un a capo 
        }while(!sanitize_input());

        n_moves++;
    }

    void move_result(){
        
    }
};

