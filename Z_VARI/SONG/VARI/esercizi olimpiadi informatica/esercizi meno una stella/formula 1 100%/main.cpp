// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> H, V;

int main() {
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];
    
    int somma1 = 0, somma2 = 0, veloce1 = 0, veloce2 = 0;
    
    
    
    for(int i = 0; i < N ; i++) somma1 += H[i];
    for(int i = 0; i < N ; i++) somma2 += V[i];
    
    if(somma1 > somma2) cout << "Verstappen" << endl;
    else cout << "Hamilton" << endl;
    
    
    veloce1 = H[0];
    for(int i = 1; i <= N - 1; i++){
        if(veloce1 > H[i]){
           veloce1 = H[i]; 
        }
    }
    
    veloce2 = V[0];
    for(int i = 1; i <= N - 1; i++){
        if(veloce2 > V[i]){
            veloce2 = V[i];
        }
    }
    
    if(veloce1 < veloce2) cout << "Hamilton" << endl;
    else cout << "Verstappen" << endl;
    
    return 0;
}
