#include <vector>
using namespace std;

long long int trova_massimo(int N, vector<int> V) {

    // Inserisci il tuo codice qui
    long long int max = V[0];
    
    for(int i = 1; i < N; i++){
        if(V[i] > max){
            max = V[i];
        }
    }
    return max;
}
